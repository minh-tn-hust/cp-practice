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
 
const int MAX_INT = 1e6 + 5;
 
vector<int> divisor(MAX_INT);
 
void init() {
  for (int i = 1; i <= MAX_INT; i++) {
    divisor[i] = 1;
  }
 
  for (int i = 1; i <= MAX_INT; i++) {
    if (divisor[i] == 1) {
      for (int j = i; j <= MAX_INT; j += i) {
        divisor[j] = i;
      }
    }
  }
}
 
vector<int> cnt(MAX_INT);
vector<int> listDivisor;

void listDivisorOf(int value) {
  if (divisor[value] == 1) return;
  if (cnt[divisor[value]] == 0) {
    listDivisor.push_back(divisor[value]);
  }
  cnt[divisor[value]]++;
  listDivisorOf(value / divisor[value]);
}
 
void solve() {
  int t;
  cin >> t;
  init();
 
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      listDivisorOf(a[i]);
    }
 
    bool canEqual = true;
    for (auto divisor : listDivisors) {
      if (cnt[divisor] % n != 0) {
        canEqual = false;
        break;
      }
    }
 
    if (canEqual) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
 
 
int main() {
 
#ifndef ONLINE_JUDGE
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  solve();
}