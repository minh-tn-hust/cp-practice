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

int hashCharacter(char s) {
  if (s == 'A') return 0;
  if (s == 'T') return 1;
  if (s == 'G') return 2;
  if (s == 'X') return 3;
}

vector<int> tripletAppear(100, 0);

bool isDifferenceTriplet(int i, int j, int k, vector<vector<int>> &plain, vector<vector<int>> &spotty) {

  for (auto plainGen : plain) {
    tripletAppear[plainGen[i] + plainGen[j] * 4 + plainGen[k] * 16] = 1;
  }

  bool isSame = false;
  for (auto spottyGen : spotty) {
    if (tripletAppear[spottyGen[i] + spottyGen[j] * 4 + spottyGen[k] * 16]) {
      isSame = true;
      break;
    }
  }

  for (auto plainGen : plain) {
    tripletAppear[plainGen[i] + plainGen[j] * 4 + plainGen[k] * 16] = 0;
  }

  return !isSame;

}



int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "cownomics";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

