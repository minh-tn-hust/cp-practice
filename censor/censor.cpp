#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>


using namespace std;

bool isSuffix(string &subString, string &S) {
  int lastIndex = S.size() - 1;
  int subStrSize = subString.size();
  for (int i = 0; i < subString.size(); i++) {
    if (lastIndex < 0) {
      return false;
    }
    if (subString[subStrSize - 1 - i] == S[lastIndex]) {
      lastIndex--;
    } else {
      return false;
    }
  }

  return true;
}

void solve() {
  string S;
  string T;
  cin >> S;
  cin >> T;

  int numberOfDeleted = 0;
  string finalContent = "";

  for (int i = 0; i < S.size(); i++) {
    finalContent += S[i];

    if (finalContent.size() > T.size() && isSuffix(T, finalContent)) {
      finalContent.resize(finalContent.size() - T.size());
    }
  }

  cout << finalContent;
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "censor";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  solve();
}

