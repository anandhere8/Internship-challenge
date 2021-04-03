// techiehere08@gmail.com
// Author : ANAND KUMAR

#include <bits/stdc++.h>

using namespace std;

int match_cost(string &s1, string &s2) { // function for matching the two string to find similiarity  
  int n = s1.size();
  int m = s2.size();
  
  if (min(n, m) == 0) {
    return max (n, m);
  }
  
  int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
		}
	}

	return dp[n][m];
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Pass the input file & a word " << '\n';
    return 0;
  }
  
  if (argc < 3) {
    cout << "Pass a word to match " << '\n';
  }
    
  auto process = [](string &s) { // filtering string from frequency and commas
    string tmp = "";
    for (auto x : s) {
      if (x == ',') 
        break;
      tmp += x;
    }
    return tmp;
  };
    
  fstream fin;
  string file = argv[1];
  string word = argv[2];
  fin.open(file, ios :: in);
  string buf;
  vector<string> list;
  
  while (fin) {
    getline(fin, buf, '\n');
    string processed = process(buf);
    list.push_back(processed);
  }    
  
  vector<pair<int, string>> dict; // suggestion list
  
  for (auto x : list) {
    int tmp_cost = match_cost(word, x);
    dict.push_back({tmp_cost, x});
  }
  
  sort(dict.begin(), dict.end()); // sorting by cost
  
  vector<string> List;
    
  int limit = 5;
    
  for (auto x : dict) {
    if (!limit) 
      break;
    List.push_back(x.second);
    limit--;
  }
  
  for (auto x : List) {
    cout << x << '\n';
  }
    
  fin.close();
  return 0;
}
