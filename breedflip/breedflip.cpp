#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

void solve() {
  int size;
  cin >> size;
  string A, B;
  cin >> A >> B;

  int numberConsecutiveDiffirentSequence = 0;

  bool isDiffirentSequence = false;
  for (int i = 0; i < size; i++) {
    if (A[i] == B[i]) {
      numberConsecutiveDiffirentSequence += ((isDiffirentSequence == true) ? 1 : 0);
      isDiffirentSequence = false;
    } else {
      isDiffirentSequence = true;
    }
  }

  cout << numberConsecutiveDiffirentSequence;

}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
#else
  string FILE_NAME = "breedflip";

#endif
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

