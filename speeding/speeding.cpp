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

typedef struct Segment {
  int length;
  int maxSpeed;

  Segment(int length, int maxSpeed) {
    this->length = length;
    this->maxSpeed = maxSpeed;
  }
} Segment;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<Segment> road;
  int begin = 0;

  int length, maxSpeed;

  for (int i = 0; i < N; i++) {
    cin >> length >> maxSpeed;
    road.push_back({length, maxSpeed});
    begin = begin + length + 1;
  }

  vector<Segment> journey;
  for (int i = 0; i < M; i++) {
    cin >> length >> maxSpeed;
    journey.push_back({length, maxSpeed});
    begin = begin + length + 1;
  }

  int roadIdx = 0;
  int jourIdx = 0;
  int ans = INT_MIN;

  for (int currentMile = 1; currentMile <= 100; currentMile++) {

    ans = max(ans, journey[jourIdx].maxSpeed - road[roadIdx].maxSpeed);

    road[roadIdx].length -= 1;
    journey[jourIdx].length -= 1;

    if (road[roadIdx].length == 0) {
      roadIdx++;
    }

    if (journey[jourIdx].length == 0) {
      jourIdx++;
    }
  }

  cout << max(ans, 0);

}

int main() {

#ifndef ONLINE_JUDGE
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

