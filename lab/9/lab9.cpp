#include <cassert>
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
  static constexpr double kAssignmentOriginalFullMark = 30.0;
  static constexpr double kAssignmentConvertedFullMark = 5.0;

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

  double converted_assignment_mark(int idx) const {
    return assignment_marks[idx] / kAssignmentOriginalFullMark * kAssignmentConvertedFullMark;
  }

  double total_mark() const {
    double res = 0.0;
    res += labs_mark;
    for (int i = 0; i < Student::kTotalAssignments; ++i) {
      res += converted_assignment_mark(i);
    }
    res += term_test_mark;
    res += midterm_mark;
    res += final_mark;
    return res;
  }

  std::string letter_grade() const {
    std::string res;
    double total = total_mark();
    if (total >= 90) {
      res = "A+";
    } else if (85 <= total && total < 90) {
      res = "A ";
    } else if (80 <= total && total < 85) {
      res = "A-";
    } else if (75 <= total && total < 80) {
      res = "B+";
    } else if (70 <= total && total < 75) {
      res = "B ";
    } else if (65 <= total && total < 70) {
      res = "C+";
    } else if (60 <= total && total < 65) {
      res = "C ";
    } else if (55 <= total && total < 60) {
      res = "D+";
    } else if (50 <= total && total < 55) {
      res = "D ";
    } else if (40 <= total && total < 50) {
      res = "E ";
    } else {
      res = "F ";
    }
    assert(res.size() == 2);
    return res;
  }

  friend std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "first_name: " << s.first_name << std::endl;
    out << "last_name: " << s.last_name << std::endl;
    out << "labs_mark: " << s.labs_mark << std::endl;
    for (int i = 0; i < Student::kTotalAssignments; ++i) {
      out << "assignment " << i + 1 << ": " << s.assignment_marks[i] << std::endl;
    }
    out << "term_test_mark: " << s.term_test_mark << std::endl;
    out << "midterm_mark: " << s.midterm_mark << std::endl;
    out << "final_mark: " << s.final_mark << std::endl;
    out << "total_mark: " << s.total_mark() << std::endl;
    out << "letter_grade: " << s.letter_grade() << std::endl;

    return out;
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

  // print the reading results
  std::cout << "Total students: " << all_students.size() << std::endl;
  for (int i = 0; i < all_students.size(); ++i) {
    std::cout << all_students[i] << std::endl;
  }

  // output to the output file
  std::ofstream fout;
  fout.open(kOutputFilePath, std::ios::binary);
  for (const auto& s : all_students) {
    int len = s.first_name.size();
    fout.write((char *) &len, sizeof(len));
    fout.write(s.first_name.c_str(), s.first_name.size());
    
    len = s.last_name.size();
    fout.write((char *) &len, sizeof(len));
    fout.write(s.last_name.c_str(), s.last_name.size());
    
    fout.write((char *) &s.student_id, sizeof(s.student_id));

    fout.write((char *) &s.labs_mark, sizeof(s.labs_mark));

    double converted_assignment_mark = -1.0;
    for (int i = 0; i < Student::kTotalAssignments; ++i) {
      converted_assignment_mark = s.converted_assignment_mark(i);
      fout.write((char *) &converted_assignment_mark, sizeof(converted_assignment_mark));
    }

    fout.write((char *) &s.term_test_mark, sizeof(s.term_test_mark));
    fout.write((char *) &s.midterm_mark, sizeof(s.midterm_mark));
    fout.write((char *) &s.final_mark, sizeof(s.final_mark));

    double total_mark = s.total_mark();
    fout.write((char *) &total_mark, sizeof(total_mark));

    std::string letter_grade = s.letter_grade();
    assert(letter_grade.size() == 2);
    fout.write(letter_grade.c_str(), letter_grade.size());
  }
  fout.close();

  return 0;
}