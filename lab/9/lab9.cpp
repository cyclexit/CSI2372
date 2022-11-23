#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static const string kInputFilePath = "./CSI2372.info";
static const string kOutputFilePath = "./CSI2372_Final.info";

int main() {
  ifstream fin;
  fin.open(kInputFilePath, ios::binary);
  cout << fin.is_open() << endl; // debug
  string tmp;
  while (getline(fin, tmp)) {
    cout << tmp << endl;
  }
  fin.close();
  return 0;
}