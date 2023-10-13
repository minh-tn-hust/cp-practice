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

typedef struct MoviePlan {
  int begin;
  int end;

  MoviePlan(int begin, int end) : begin(begin), end(end) {}
} MoviePlan;

bool compareEndTime(const MoviePlan &a, const MoviePlan &b) {
  return a.end < b.end;
}

void solve() {
  int n;
  cin >> n;
  
  vector<MoviePlan> plans;

  int beginTime, endTime;
  for (int i = 0; i < n; i++) {
    cin >> beginTime >> endTime;
    plans.push_back({beginTime, endTime});
  }

  sort(plans.begin(), plans.end(), compareEndTime);

  int prevEndingTime = 0;
  int numberOfMovie = 0;
  for (auto plan : plans) {
    if (plan.begin >= prevEndingTime) {
      prevEndingTime = plan.end;
      numberOfMovie++;
    }
  }

  cout << numberOfMovie;
}


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

