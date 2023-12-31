#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

#include <bits/stdc++.h>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ", "), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

const char GALAXY = '#';

vector<int> findingExpanedRow(vector<string> &universe) {
    vector<int> expanedRows;
    for (int i = 0; i < universe.size(); i++) {
        bool hasGalaxy = false;
        for (auto c : universe[i]) {
            if (c == GALAXY) {
                hasGalaxy = true;
                break;
            }
        }

        if (!hasGalaxy) {
            expanedRows.push_back(i);
        }
    }

    return expanedRows;
}

vector<int> findingExpanedCol(vector<string> &universe) {
    vector<int> expanedCols;
    int width = universe[0].size();
    int height = universe.size();

    for (int c = 0; c < width; c++) {
        bool hasGalaxy = false;
        for (int r = 0; r < height; r++) {
            if (universe[r][c] == GALAXY) {
                hasGalaxy = true;
                break;
            }
        }
        
        if (!hasGalaxy) {
            expanedCols.push_back(c);
        }
    }
    return expanedCols;
}

typedef struct GalaxyLocation {
    int row, col;
    GalaxyLocation(int row, int col) : row(row), col(col) {}
} GalaxyLocation;

void __print(GalaxyLocation galaxy) {
    cerr << "(";
    cerr << galaxy.row << " " << galaxy.col;
    cerr << ")";
}

vector<GalaxyLocation> locateGalaxy(vector<string> &universe) {
    vector<GalaxyLocation> galaxies;

    for (int row = 0; row < universe.size(); row++) {
        for (int col = 0; col < universe[row].size(); col++) {
            if (universe[row][col] == GALAXY) {
                galaxies.push_back({row, col});
            }
        }
    }
    return galaxies;
}

bool isInrange(int value, int max, int min) {
    return ((value - max) * (value - min) < 0);
}

const int BIGGER_TIME = 1000000;

int getVerticalSpace(GalaxyLocation &first, GalaxyLocation &second, vector<int> &expanedRows) {
    int verticalSpace = abs(first.row - second.row);
    for (auto expanedRow : expanedRows) {
        if (isInrange(expanedRow, first.row, second.row)) {
            verticalSpace += (BIGGER_TIME - 1);
        }
    }

    return verticalSpace;
}

int getHorizontalSpace(GalaxyLocation &first, GalaxyLocation &second, vector<int> &expanedCols) {
    int horizontalSpace = abs(first.col - second.col);
    for (auto expanedCol : expanedCols) {
        if (isInrange(expanedCol, first.col, second.col)) {
            horizontalSpace += (BIGGER_TIME - 1);
        }
    }

    return horizontalSpace;

}


void solve() {
    int size;
    cin >> size;
    vector<string> universe;
    string temp;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        universe.push_back(temp);
    }

    vector<int> expanedRows = findingExpanedRow(universe);
    vector<int> expanedCols = findingExpanedCol(universe);
    vector<GalaxyLocation> galaxies = locateGalaxy(universe);

    long long sum = 0;
    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i + 1; j < galaxies.size(); j++) {
            int verticalSpace = getVerticalSpace(galaxies[i], galaxies[j], expanedRows);
            int horizontalSpace = getHorizontalSpace(galaxies[i], galaxies[j], expanedCols);
            sum += (verticalSpace + horizontalSpace);
        }
    }

    cout << sum;
}


int main() {

#ifdef LOCAL
  string FILE_NAME = "local";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}