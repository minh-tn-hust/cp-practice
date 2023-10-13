#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>

const double EPSILON = 1e-9;

using namespace std;

typedef struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}

  distanceSquare(Point &point) {
    return (point.x - x) * (point.x - x) + (point.y - y) * (point.y - y);
  }

  isCoverPoint(double r, Point &point) {
    if (r * r - distanceSquare(point) >= 0) {
      return true;
    }
  }
  Point() {}
} Point;

bool isIntersect(Point &A, double rA, Point &B, double rB) {
  if (A.distanceSquare(B) <= (rA + rB) * (rA + rB)) {
    return true;
  }
  return false;
}

bool canMoveFromOToP(Point &A, Point &B, Point &O, Point &P, double r) {
  bool isACoverO = A.isCoverPoint(r, O);
  bool isACoverP = A.isCoverPoint(r, P);
  bool isBCoverO = B.isCoverPoint(r, O);
  bool isBCoverP = B.isCoverPoint(r, P);

  if (isACoverO && isACoverP) {
    return true;
  }

  if (isBCoverO && isBCoverP) {
    return true;
  }

  if (isACoverO && isBCoverP) {
    return isIntersect(A, r, B, r);
  }

  if (isACoverP && isBCoverO) {
    return isIntersect(A, r, B, r);
  }

  return false;
}

void solve() {
  int t;
  cin >> t;
  int x, y;
  Point A, B, P, O;
  O.x = 0;
  O.y = 0;

  while (t--) {
    cin >> P.x >> P.y;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;

    double left = 0, right = 6000;
    double middle;
    while (right - left > EPSILON) {
      middle = (left + right) / 2;
      if (canMoveFromOToP(A, B, O, P, middle)) {
        right = middle;
      } else {
        left = middle;
      }
    }

    cout << setprecision(10) << middle << "\n";
  }

}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

