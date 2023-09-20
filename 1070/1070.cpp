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

  int n;
  cin >> n;

  if (1 < n && n <= 3) {
    cout << "NO SOLUTION";
  } else {
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        cout << i << " ";
      }
    }

    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        cout << i << " ";
      }
    }
  }
}

