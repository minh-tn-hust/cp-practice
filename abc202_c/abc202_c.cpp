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

const int MAX_N = 1e5 + 2;

using namespace std;

void solve() {
  unordered_map<int, int> sameValue;

  int N;
  cin >> N;

  int A[MAX_N];
  int B[MAX_N];
  int C[MAX_N];

  for (int i = 0; i < N;i++) {
    cin >> A[i];
    sameValue[A[i]]++;
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  long long numPairs = 0;
  for (int i = 0; i < N; i++) {
    numPairs += (long long) sameValue[B[C[i] - 1]];
  }

  cout << numPairs;
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

