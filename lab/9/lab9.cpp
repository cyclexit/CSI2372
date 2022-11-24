#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

static const std::string kInputFilePath = "./CSI2372.info";
static const std::string kOutputFilePath = "./CSI2372_Final.info";

struct Student {
  static constexpr int kTotalAssignments = 5;

  std::string first_name;
  std::string last_name;
  // payload begins
  int student_id;
  double labs_mark;
  std::vector<double> assignment_marks;
  double term_test_mark;
  double midterm_mark;
  double final_mark;
  // payload ends

  Student() {assignment_marks.resize(kTotalAssignments, 0.0);}

  static size_t payload_byte_len() {
    return sizeof(decltype(student_id)) + sizeof(decltype(labs_mark))
            + sizeof(decltype(assignment_marks)::value_type) * kTotalAssignments
            + sizeof(decltype(term_test_mark)) + sizeof(decltype(midterm_mark))
            + sizeof(decltype(final_mark));
  }
};

int main() {
  std::ifstream fin;
  // read the input file
  fin.open(kInputFilePath, std::ios::binary);
  if (!fin.is_open()) {
    std::cout << "File not found!" << std::endl;
    return 1;
  }
  std::string data;
  while (getline(fin, data)) {
    std::cout << data << std::endl;
  }
  fin.close();

  // decode the data
  std::vector<Student> all_students;
  // get first name and last name
  std::regex names_pattern("\\w+;\\w+;");
  std::sregex_iterator names_begin(
    data.begin(),
    data.end(),
    names_pattern
  );
  std::sregex_iterator names_end;
  for (auto itr = names_begin; itr != names_end; ++itr) {
    std::smatch names_match = *itr;
    std::stringstream ss(names_match.str());

    Student cur;
    bool is_first_name = true;
    std::string tmp;
    while (getline(ss, tmp, ';')) {
      if (is_first_name) {
        is_first_name = false;
        cur.first_name = tmp;
      } else {
        cur.last_name = tmp;
      }
    }

    all_students.push_back(cur);
  }
  // get payload part
  std::sregex_token_iterator payload_begin(
    data.begin(),
    data.end(),
    names_pattern,
    -1
  );
  ++payload_begin; // skip the empty token
  std::sregex_token_iterator payload_end;
  int idx = 0;
  for (auto itr = payload_begin; itr != payload_end; ++itr, ++idx) {
    std::stringstream ss(*itr);
    // std::cout << ss.str() << std::endl;
    ss.read((char *) &all_students[idx].student_id, sizeof(Student::student_id));
    // std::cout << all_students[idx].student_id << std::endl;
    ss.read((char *) &all_students[idx].labs_mark, sizeof(Student::labs_mark));
    // std::cout << all_students[idx].labs_mark << std::endl;
    for (int i = 0; i < Student::kTotalAssignments; ++i) {
      ss.read((char *) &all_students[idx].assignment_marks[i], sizeof(decltype(Student::assignment_marks)::value_type));
      // std::cout << "Assignmen " << i + 1 << ": " << all_students[idx].assignment_marks[i] << std::endl;
    }
    ss.read((char *) &all_students[idx].term_test_mark, sizeof(Student::term_test_mark));
    ss.read((char *) &all_students[idx].midterm_mark, sizeof(Student::midterm_mark));
    ss.read((char *) &all_students[idx].final_mark, sizeof(Student::final_mark));
  }

  // std::cout << all_students.size() << std::endl;
  // for (auto s : all_students) {
  //   std::cout << s.first_name << " " << s.last_name << std::endl;
  // }

  // std::cout << Student::payload_byte_len() << std::endl;

  // stringstream ss(data);
  // std::cout << "Tokens: " << std::endl;
  // int cnt = 0;
  // while (getline(ss, data, ';')) {
  //   std::cout << ++cnt << ": " << data << std::endl << "\tsize = " << data.size() << std::endl;
  //   if (cnt == 3 || (cnt > 3 && cnt % 3 == 2)) {
  //     stringstream tmp_ss(data);

  //     int id;
  //     tmp_ss.read((char *)&id, sizeof(decltype(id)));
  //     std::cout << "\t" << "id = " << id << std::endl;

  //     std::cout << std::endl;
  //   }
  // }
  return 0;
}