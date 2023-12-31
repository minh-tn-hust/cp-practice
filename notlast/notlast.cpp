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
  int n;
  cin >> n;
  unordered_map<string, int> milkProduce = {
    {"Bessie", 0}, 
    {"Elsie", 0}, 
    {"Daisy", 0}, 
    {"Gertie", 0}, 
    {"Annabelle", 0}, 
    {"Maggie", 0}, 
    {"Henrietta", 0}
  };
  for (int i = 0; i < n; i++) {
    string cowName;
    int milk;
    cin >> cowName >> milk;

    milkProduce[cowName] += milk;
  }
  int minimumMilk = INT_MAX;
  for (auto &[cowName, milk] : milkProduce)  {
    minimumMilk = min(minimumMilk, milk);
  }

  int lastSecondMilk = INT_MAX;
  string lastSecondCow;
  for (auto &[cowName, milk] : milkProduce) {
    if (milk != minimumMilk && milk < lastSecondMilk) {
      lastSecondMilk = milk;
    }
  }

  vector<string> listLastSecond;
  for (auto &[cowName, milk] : milkProduce) {
    if (milk == lastSecondMilk) {
      listLastSecond.push_back(cowName);
    }
  }

  if (listLastSecond.size() == 0 || listLastSecond.size() > 1) {
    cout << "Tie\n";
  } else {
    cout << listLastSecond[0] << "\n";
  }

}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
#else 
  string FILE_NAME = "notlast";
#endif
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

