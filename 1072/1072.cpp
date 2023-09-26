#include <iostream>

using namespace std;

long long fromPositionToInvalidCellPair(long long prevSize, long long row, long long col) {
  long long invalidCellPair = 0;
  if (row - 2 >= 1 && col - 1 >= 1) {
    invalidCellPair++;
  }

  if (row - 1 >= 1 && col - 2 >= 1) {
    invalidCellPair++;
  }

  if (row + 1 <= prevSize && col - 2 >= 1) {
    invalidCellPair++;
  }

  if (row + 2 <= prevSize && col - 1 >= 1) {
    invalidCellPair++;
  }
  return invalidCellPair;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n;
  cin >> n;

  long long ans = 0;

  for (long long i = 1; i <= n; i++) {
    if(i == 1) {
      ans = 0;
      cout << ans << "\n";
      continue;
    }

    if (i == 2) {
      ans = 6;
      cout << ans << "\n";
      continue;
    }

    long long additionCol = i;
    long long prevSize = i - 1;

    long long additionValidCellPair = 0;

    for (long long row = 1; row <= prevSize; row++) {
      long long invalidCellPair = fromPositionToInvalidCellPair(prevSize, row, additionCol);
      additionValidCellPair += prevSize * prevSize - invalidCellPair;
    }

    long long validCellPairAtConner = prevSize * prevSize - fromPositionToInvalidCellPair(prevSize, i, i);

    ans += (additionValidCellPair * 2) + validCellPairAtConner + prevSize * (2 * prevSize + 1)  +  - 2;

    cout << ans << "\n";
  }
}