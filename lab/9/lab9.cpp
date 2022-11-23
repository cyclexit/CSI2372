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
  long long student_id;
  double labs_mark;
  vector<double> assignment_marks;
  double term_test_mark;
  double midterm_mark;
  double final_mark;

  Student() {assignment_marks.resize(kTotalAssignments);}

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
  string data;
  while (getline(fin, data)) {
    cout << data << endl;
  }
  fin.close();
  stringstream ss(data);
  return 0;
}