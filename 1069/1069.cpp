#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  int size = s.size();
  int numberOfDuplicateChar = 1;
  int ans = -100000;

  for (int i = 0; i < size - 1; i++) {
    if (s[i] == s[i + 1]) {
      numberOfDuplicateChar += 1;;
      continue;
    }

    ans = max(ans, numberOfDuplicateChar);
    numberOfDuplicateChar = 1;
  }

  ans = max(ans, numberOfDuplicateChar);
  cout << ans;

}

