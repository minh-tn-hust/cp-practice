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


const int ODD = 1;
const int EVENT = 0;

int createGroup(int state, int odds, int evens) {
}

void solve() {
  int n;
  cin >> n;

  int numOdds = 0;
  int numEvens = 0;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp % 2 == 0) {
      numEvens++;
    } else {
      numOdds++;
    }
  }

  int groupState = 1;




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

