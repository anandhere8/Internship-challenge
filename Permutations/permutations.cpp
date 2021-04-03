// techiehere08@gmail.com
// Author : ANAND KUMAR

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Pass the input file " << '\n';
    return 0;
  }
  
  auto process = [](string tmp) { // filtering the strings from unwanted characters
    string res = "";
    for (auto x : tmp) {
      if (isalpha(x)) {
        res += x;
      }
    }
    return res;
  };
  
  fstream fin;
  string file = argv[1];
  fin.open(file, ios :: in);
  string buf;
  vector<string> list;
  while (fin) {
    getline(fin, buf, '\n');
    string processed = process(buf);
    list.push_back(processed);
  }    
  vector<string> res;
  for (auto i : list[0]) {
    for (auto j : list[1]) {
      for (auto k : list[2]) {
        string tmp = " ";
        tmp += i, tmp += j, tmp += k;
        res.push_back(tmp);
      }
    }
  }
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i];
    if (i == (int)res.size() - 1) cout << '\n';
    else cout << ", ";
  }
  fin.close();
  return 0;
}
