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
  long long sum = 0;
  long long number = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> number;
    sum += number;
  }
  cout << n * (n + 1LL) / 2LL - sum;
}

