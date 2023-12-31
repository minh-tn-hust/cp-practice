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

void solve() {
  long long N;
  cin >> N;
  
  string city, shorten;
  vector<string> cities;
  vector<string> shortens;

  unordered_map<string, long long> hashingState;

  for (long long i = 0; i < N; i++) {
    cin >> city >> shorten;
    cities.push_back(city);
    shortens.push_back(shorten);
    string hashing = "";
    hashing += city[0];
    hashing += city[1];
    if (hashing != shorten) {
      hashing.append(shorten);

      hashingState[hashing] += 1;
    }
  }

  long long numSpecialPair = 0;
  for (long long i = 0; i < N; i++) {
    string &city = cities[i];
    string &shorten = shortens[i];

    string hashing = "";
    hashing.append(shorten);
    hashing += city[0];
    hashing += city[1];

    numSpecialPair += hashingState[hashing];
  }

  cout << numSpecialPair / 2;
}

int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
#else
  string FILE_NAME = "citystate";
#endif
  ios::sync_with_stdio(0);
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  cin.tie(0);
  cout.tie(0);

  solve();
}

