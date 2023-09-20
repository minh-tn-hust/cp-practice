#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> array;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    array.push_back(temp);
  }

  long long numberOfStep = 0;

  for (int i = 1; i < n; i++) {
    if (array[i] < array[i - 1]) {
        numberOfStep += (long long) (array[i - 1] - array[i]);
        array[i] = array[i - 1];
    }
  }

  cout << numberOfStep;
}