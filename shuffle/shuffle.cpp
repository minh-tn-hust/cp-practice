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

  map<int, int> reverseShuffle;
  vector<int> finalId;


  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    reverseShuffle.insert({temp - 1, i});
  }

  for (int i = 0; i < N; i++) {
    cin >> temp;
    finalId.push_back(temp);
  }

  vector<int> initialId(N);


  for (int i = 0; i < N; i++) {
    initialId[reverseShuffle[reverseShuffle[reverseShuffle[i]]]] = finalId[i];
  }

  for (int i = 0; i < N; i++) {
    cout << initialId[i] << "\n";
  }
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "shuffle";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

