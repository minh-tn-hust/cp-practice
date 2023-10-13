#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n;

  cin >> n;

  long long sum = (n * (n + 1)) / 2;

  unordered_set<int> appear;

  if (sum % 2 == 1) {
    cout << "NO";
  } else {
    long long subSum = sum / 2;
    vector<long long> firstSet;

    for(int i = n; i != 0; i--) {
      if (i <= subSum) {
        subSum -= i;
        firstSet.push_back(i);
        appear.insert(i);
      }
    }

    cout << "YES\n";
    cout << firstSet.size() << "\n";
    for (int i = 0; i < firstSet.size(); i++) {
      cout << firstSet[i] << " ";
    }
    cout << "\n";
    cout << n - firstSet.size() << "\n";
    for (int i = 1; i <= n; i++) {
      if (appear.find(i) == appear.end()) {
        cout << i << " ";
      }
    }
  }
  
}

