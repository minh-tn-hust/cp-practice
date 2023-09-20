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

  long long n;
  cin >> n;
  cout << n << " ";
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
      cout << n << " ";
      continue;
    }

    n *= 3;
    n += 1;
    cout << n << " ";
  }
}
