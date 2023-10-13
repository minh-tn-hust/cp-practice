#include <iostream>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;

  set<int> distinc;

  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    distinc.insert(temp);
  }

  cout << distinc.size();

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

