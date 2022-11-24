#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

static const string kInputFilePath = "./CSI2372.info";
static const string kOutputFilePath = "./CSI2372_Final.info";

struct Student {
  static constexpr int kTotalAssignments = 5;

  string first_name;
  string last_name;
  int student_id;
  double labs_mark;
  vector<double> assignment_marks;
  double term_test_mark;
  double midterm_mark;
  double final_mark;

  Student() {assignment_marks.resize(kTotalAssignments, 0.0);}

  static size_t byte_len_without_names() {
    return sizeof(decltype(student_id)) + sizeof(decltype(labs_mark))
            + sizeof(decltype(assignment_marks)::value_type) * kTotalAssignments
            + sizeof(decltype(term_test_mark)) + sizeof(decltype(midterm_mark))
            + sizeof(decltype(final_mark));
  }

  // friend istream& operator>>(istream& in, Student& s) {
  //   in >> s.first_name >> s.last_name >> s.student_id;
  //   in >> s.labs_mark;
  //   for (int i = 0; i < Student::kTotalAssignments; ++i) {
  //     in >> s.assignment_marks[i];
  //   }
  //   in >> s.term_test_mark >> s.midterm_mark >> s.final_mark;
  //   return in;
  // }
};

int main() {
  ifstream fin;
  fin.open(kInputFilePath, ios::binary);
  if (!fin.is_open()) {
    cout << "File not found!" << endl;
    return 1;
  }
  string data;
  while (getline(fin, data)) {
    cout << data << endl;
  }
  fin.close();

  cout << Student::byte_len_without_names() << endl;

  stringstream ss(data);
  cout << "Tokens: " << endl;
  int cnt = 0;
  while (getline(ss, data, ';')) {
    cout << ++cnt << ": " << data << endl << "\tsize = " << data.size() << endl;
    if (cnt == 3 || (cnt > 3 && cnt % 3 == 2)) {
      stringstream tmp_ss(data);

      int id;
      tmp_ss.read((char *)&id, sizeof(decltype(id)));
      cout << "\t" << "id = " << id << endl;

      cout << endl;
    }
  }
  return 0;
}