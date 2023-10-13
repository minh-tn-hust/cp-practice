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

bool greaterCompare(const int &a, const int &b) {
  return a > b;
}

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> alphabet(27, vector<int>());
  // O(N * 26 * (26 * log(26)))
  for (int j = 0; j < N; j++) {
    string fWord, sWord;
    cin >> fWord >> sWord;
    vector<int> fCharacters(27, 0);
    vector<int> sCharacters(27, 0);

    for (int i = 0; i < fWord.size(); i++) {
      fCharacters[fWord[i] - 'a']++;
    }

    for (int i = 0; i < sWord.size(); i++) {
      sCharacters[sWord[i] - 'a']++;
    }

    for (int i = 0; i < 27; i++) {
      alphabet[i].push_back(max(fCharacters[i], sCharacters[i]));
    }
  }

  vector<int> ans(27, 0);
  for (int i = 0; i < 27; i++) {
    sort(alphabet[i].begin(), alphabet[i].end(), greaterCompare);
    for (int j = 0; j < N; j++) {
      ans[i] += alphabet[i][j];
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "blocks";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

