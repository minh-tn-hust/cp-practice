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

const long long UPDATE = 0;
const long long PRINT = 1;

void solve() {

  unordered_map<long long, long long> mapping;

  long long Q;
  cin >> Q;

  long long queryType;
  for (long long i = 0; i < Q; i++) {
    cin >> queryType;

    long long k, v;
    if (queryType == UPDATE) {
      cin >> k >> v;
      mapping[k] = v;
    }

    if (queryType == PRINT) {
      cin >> k;
      cout << mapping[k] << "\n";
    }
  }
}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

