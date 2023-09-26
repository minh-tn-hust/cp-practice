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
    long long numberOfCell = i * i;
    long long numberOfPair = (numberOfCell * (numberOfCell - 1)) / 2;

    // Count number of 3*2 rectangle can create in current size;
    // The first 2 means "every rectangle can have 2 pair invalid"
    // The second 2 means "3 * 2 and 2 * 3 have the same number invalid pair"
    long long numberOfInvalidPair = (i - 1) * (i - 2) * 2 * 2;

    cout << numberOfPair - numberOfInvalidPair << "\n";
  }
}