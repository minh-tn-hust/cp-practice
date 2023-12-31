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

const int MAX_N = 2004;
using namespace std;

void solve() {
  int n, k;
  cin >> k >> n;
  
  int A[MAX_N];
  int prefixSumA[MAX_N];
  int B[MAX_N];

  int temp;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> A[i];
    sum += A[i];
    prefixSumA[i] = sum;
  }

  unordered_map<int, bool> appearing;
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    appearing[B[i]] = true;
  }

  set<int> possibleOptions;

  for (auto b : B) {
    // index of B after taking As point
    for (int i = 0; i < k; i++) {
      int initialPoint = b - prefixSumA[i];
      possibleOptions.insert(initialPoint);
    }
  }

  int numOptions = 0;

  for (auto initialPoint : possibleOptions) {

    // checking after go through all a value, all b value is appearing
    int numAppear = 0;
    for (int i = 0; i < n; i++) {
      appearing[B[i]] = true;
    }

    for (int j = 0; j < k; j++) {
      int b_j = initialPoint + prefixSumA[j];
      if (appearing[b_j]) {
        numAppear++;
        appearing[b_j] = false;
      }
    }

    if (numAppear == n) {
      numOptions++;
    }
  }

   cout << numOptions;
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

