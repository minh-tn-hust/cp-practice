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

typedef struct OnTime {
  int time;
  int customer;

  OnTime(int time, int customer) : time(time), customer(customer) {};
} OnTime;

bool comparePlan(const OnTime &a, const OnTime &b) {
  return a.time < b.time;
}

void solve() {
  int n;
  cin >> n;

  vector<OnTime> plans;

  int beginTime, endTime;
  for (int i = 0; i < n; i++) {
    cin >> beginTime >> endTime;
    plans.push_back({beginTime, 1});
    plans.push_back({endTime, -1});
  }

  sort(plans.begin(), plans.end(), comparePlan);

  int currentCustomer = 0;
  int maximumCustomer = 0;

  for (auto plan : plans) {
    currentCustomer += plan.customer;
    maximumCustomer = max(currentCustomer, maximumCustomer);
  }

  cout << maximumCustomer;

}

// Using map instead of sorting
// void solve() {
//   int n;
//   cin >> n;

//   vector<OnTime> plans;

//   int beginTime, endTime;
//   for (int i = 0; i < n; i++) {
//     cin >> beginTime >> endTime;
//     plans.push_back({beginTime, endTime});
//   }

//   map<int, int> timeAndCustomer;

//   for (auto customerTime : plans) {
//     timeAndCustomer[customerTime.begin]++;
//     timeAndCustomer[customerTime.end + 1]--;
//   }

//   int lastNCustomer = 0;
//   int maxCustomer = INT_MIN;
//   // O(time) ~ O(2e5)
//   for (auto &[time, customer] : timeAndCustomer) {
//     timeAndCustomer[time] = lastNCustomer + customer; // O(log(time))
//     lastNCustomer = timeAndCustomer[time];
//     maxCustomer = max(maxCustomer, lastNCustomer);
//   }
//   // -> O(n log n) // n is number of diffrent time
//   cout << maxCustomer;
// }


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "cowlying";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

