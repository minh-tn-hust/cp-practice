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

  long long t;
  cin >> t;

  const long long FLAG_COL = 1;
  const long long FLAG_ROW = 2;

  while (t--) {
    long long col, row;
    cin >> row >> col;

    long long flag = (col > row) ? FLAG_COL : FLAG_ROW;
    long long flagValue = max(col, row);
    long long deltaValue = min(col, row) - 1;

    long long ans = 0;
    
    if (flag == FLAG_COL) {
      if (flagValue % 2 == 0) {
        ans += (flagValue - 1) * (flagValue - 1) + 1 + deltaValue;
      } else {
        ans += flagValue * flagValue + - deltaValue ;
      }
    } else {
      if (flagValue % 2 == 0) {
        ans += flagValue * flagValue - deltaValue;
      } else {
        ans += (flagValue - 1) * (flagValue - 1) + 1 + deltaValue;
      }
    }

    cout << ans << "\n";
  }
}

