#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const double epsilon = 1e-9;

using namespace std;

void solve() {

}

class Solution {
public:
    const long long MODULO = 2e9 + 19;
    const long long BASE = 26;
    vector<long long> pow(1001);
    void initPow() {
      pow[0] = 1;
      for (int i = 1; i < 1001; i++) {
        pow[i] = (pow[i - 1] * 26) % MODULO;
      }
    }

    string longestPalindrome(string s) {
        vector<int> hashPrefixLeftToRight(s.size());
        vector<int> hashPreifxRightToLeft(s.size());
        for (int i = 0; i < s.size(); i++) {
        }
    }
};



int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "lostcow";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

