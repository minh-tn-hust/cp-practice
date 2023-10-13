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

void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long n; 
    cin >> n;
    if(n % 3 == 0) {
      if (n >= 12) {
        cout << "YES\n";
        cout << 1 << " " << 4  << " " << (n - 1LL - 4LL) << "\n";
      } else {
        cout << "NO\n";
      }
    }

    if (n % 3 == 1) {
      if (n >= 7) {
        cout << "YES\n";
        cout << 1 << " " << 2  << " " << n - 1LL - 2LL << "\n";
      } else {
        cout << "NO\n";
      }
    }

    if (n % 3 == 2) {
      if (n >= 8){
        cout << 1 << " " << 2 << " " << n - 1LL - 2LL << "\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

