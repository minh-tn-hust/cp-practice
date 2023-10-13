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

typedef struct Point {
  int x,y;
  Point(int x, int y) : x(x), y(y) {}
  void print() {
    cout << x << " "  << y << "\n";
  }
} Point;

typedef struct Vector {
  int x, y;
  Vector(int x, int y) : x(x), y(y) {}

  int dot(Vector &other) {
    return other.x * x + other.y * y;
  }
} Vector;


void solve() {
  int N;
  cin >> N;

  vector<Point> points;

  int x,y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    points.push_back({x, y});
  }

  int maximumArea = INT_MIN;

  for (int i = 0; i < N; i++) {
    Point &fPoint = points[i];
    for (int j = i + 1; j < N; j++) {
      Point &sPoint = points[j];
      for (int t = j + 1; t < N; t++) {
        Point &tPoint = points[t];

        bool isParallelX = false;
        bool isParallelY = false;
        Vector fs = {sPoint.x - fPoint.x, sPoint.y - fPoint.y};
        if (fs.x == 0) isParallelX = true;
        if (fs.y == 0)
        Vector ft = {tPoint.x - fPoint.x, tPoint.y - fPoint.y};
        Vector ts = {sPoint.x - tPoint.x, sPoint.y - tPoint.y};

        if (fs.dot(ft) == 0 || ft.dot(ts) == 0 || fs.dot(ts) == 0) {
          fPoint.print();
          sPoint.print();
          tPoint.print();
          int area = abs(fPoint.x * (sPoint.y - tPoint.y) + sPoint.x * (tPoint.y - fPoint.y) + tPoint.x * (fPoint.y - sPoint.y));
          cout << area << "\n";
          maximumArea = max(area, maximumArea);
        }
      }
    }
  }

  cout << maximumArea;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "triangles";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

