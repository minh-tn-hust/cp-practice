#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>


using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<int>   flowerPetals;

  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    flowerPetals.push_back(temp);
  }

  vector<int> prefixSum(N);
  prefixSum[0] = flowerPetals[0];
  for (int i = 1; i < N; i++) {
    prefixSum[i] = prefixSum[i - 1] + flowerPetals[i];
  }

  int ans = N;
  for (int i = 0 ; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int sumPetals = prefixSum[j] - prefixSum[i] + flowerPetals[i];
      
      int numberOfFlowers = j - i + 1;
      for (int t = i; t <= j; t++) {
        if (sumPetals == numberOfFlowers * flowerPetals[t]) {
          ans++;
          break;
        }
      }
    }
  }

  cout << ans;

}


int main() {

#ifndef ONLINE_JUDGE
  // string FILE_NAME = "diamond";
  // freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  // freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

