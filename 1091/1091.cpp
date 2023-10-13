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
  int n, m;
  cin >> n >> m;

  multiset<int> prices;

  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    prices.insert(temp);
  }

  for (int i = 0; i < m; i++) {
    cin >> temp;

    multiset<int>::iterator finding = prices.upper_bound(temp);
    if (finding == prices.begin()) {
      cout << -1 << " ";
    } else {
      cout << *(--finding) << "\n";
      prices.erase(finding);
    }
  }
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

