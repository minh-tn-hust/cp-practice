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
typedef struct DayLog {
  int day;
  string cowName;
  int delta;
  DayLog() : day(0), cowName(""), delta(0) {}
} DayLog;

bool compareDay(const DayLog &a, const DayLog &b) {
  return a.day < b.day;
}

void solve() {
  int N;
  cin >> N;
  vector<DayLog> logBook(N);

  for (int i = 0; i < N; i++) {
    cin >> logBook[i].day >> logBook[i].cowName >> logBook[i].delta;
  }

  sort(logBook.begin(), logBook.end(), compareDay);

  int maximumMilk = 7;
  unordered_set<string> topCow;
  vector<int> dayChange(101, 0);
  int numberOfChange = 0;

  topCow.insert("Mildred");
  topCow.insert("Elsie");
  topCow.insert("Bessie");

  unordered_map<string, int> milkPerCow;
  milkPerCow["Mildred"] = 7;
  milkPerCow["Elsie"] = 7;
  milkPerCow["Bessie"] = 7;

  for (int i = 0; i < N; i++) {
    DayLog &log = logBook[i];

    if (milkPerCow[log.cowName] == 0) {
      milkPerCow[log.cowName] = 7;
    }

    milkPerCow[log.cowName] += log.delta;

    // Finding new top cow
    int newMaximumMilk = INT_MIN;
    set<string> newTopCow;

    for (auto cow : milkPerCow) {
      newMaximumMilk = max(newMaximumMilk, cow.second);
    }

    for (auto cow : milkPerCow) {
      if (cow.second == newMaximumMilk) {
        newTopCow.insert(cow.first);
      }
    }

    // Constrast with current top cow to see changing
    bool isChange = false;

    if (newTopCow.size() != topCow.size()) {
      isChange = true;
    } else {
      for (auto cow : newTopCow) {
        if (topCow.find(cow) == topCow.end()) {
          isChange = true;
          break;
        }
      }
    }

    if (isChange) {
      dayChange[log.day] = 1;
      topCow.clear();
      for (auto cow : newTopCow) {
        topCow.insert(cow);
      }
    }
  }


  for (int i = 1; i < dayChange.size(); i++) {
    if (dayChange[i] == 1) {
      numberOfChange++;
    }
  }

  cout << numberOfChange;
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "measurement";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

