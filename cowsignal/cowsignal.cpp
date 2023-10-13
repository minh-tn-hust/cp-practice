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

void scale(string &s, int times) {
  string afterScale = "";
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < times; j++) {
      afterScale += s[i];
    }
  }

  for (int i = 0; i < times; i++) {
    cout << afterScale << "\n";
  }

}


void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  string s;

  for (int i = 0; i < N; i++) {
    cin >> s;
    scale(s, K);
  }
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

