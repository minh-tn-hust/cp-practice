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
  int N;
  cin >> N;

  vector<long long> alpha(N + 1);
  vector<long long> a(N + 1);
  vector<long long> b(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    alpha[i] = a[i] * i * (N + 1 - i);
  }

  sort(alpha.begin() + 1, alpha.end());

  for (int i = 1; i <= N; i++) {
    cin >> b[i];
  }

  sort(b.begin() + 1, b.end());

  long long ans = 0;

  for (int i = 1; i <= N; i++) {
    ans += b[N + 1 - i] * alpha[i];
  }

  cout << ans;
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

