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

typedef struct Animal {
  string name = "";
  unordered_set<string> characteristics;

  void addCharacteristic(string characteristic) {
    characteristics.insert(characteristic);
  }

  bool hasCharacteristic(string characteristic) {
    if (characteristics.find(characteristic) == characteristics.end()) {
      return false;
    }

    return true;
  }
} Animal;

void solve() {
  int n;

  cin >> n;

  vector<Animal> animals(n);

  for (int i = 0;i < n; i++) {
    cin >> animals[i].name;
    int numberOfCharac;
    cin >> numberOfCharac;

    string characteristic;
    for (int j = 0; j < numberOfCharac; j++) {
      cin >> characteristic;
      animals[i].addCharacteristic(characteristic);
    }
  }

  int maximumGeneralCharac = INT_MIN;
  for (int i = 0; i < n; i++) {
    Animal &guessAnimal = animals[i];

    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      int numberOfCharac = 0;
      for (auto characteristic : guessAnimal.characteristics) {
        if (animals[j].hasCharacteristic(characteristic)) {
          numberOfCharac++;
        }
      }
      maximumGeneralCharac = max(maximumGeneralCharac, numberOfCharac);

    }
  }

  cout << maximumGeneralCharac + 1;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "guess";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

