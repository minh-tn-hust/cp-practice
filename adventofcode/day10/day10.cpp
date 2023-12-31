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

char START = 'S';
char VERTICAL ='|';
char HORIZONTAL = '-';
char BOTTOM_LEFT = 'L';
char BOTTOM_RIGHT = 'J';
char TOP_RIGHT = '7';
char TOP_LEFT = 'F';

typedef struct Cell {
    int row, col;
    Cell(int row, int col) : row(row), col(col) {};
    Cell() {};
    bool equal(Cell &other) {
        return row == other.row && col == other.col;
    }
} Cell;
void __print(Cell cell) {
    cerr << "(";
    __print(cell.row);
    cerr << ", ";
    __print(cell.col);
    cerr << ")";
}

map<char, vector<Cell>> DIGITAL_TILE = {
    {VERTICAL, {{1, 0}, {-1, 0}}},
    {HORIZONTAL, {{0, 1}, {0, -1}}},
    {BOTTOM_LEFT, {{-1, 0}, {0, 1}}},
    {BOTTOM_RIGHT, {{-1, 0}, {0, -1}}},
    {TOP_RIGHT, {{0, -1}, {1, 0}}},
    {TOP_LEFT, {{1, 0}, {0, 1}}},
};

bool isStartingCell(char s) {
    return s == START;
}

Cell locateStartingCell(vector<string> &pileMap) {
    for (int i = 0; i < pileMap.size(); i++) {
        for (int j = 0; j < pileMap[i].size(); j++) {
            if (isStartingCell(pileMap[i][j])) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool isInRange(int value, int max) {
    return (0 <= value && value < max);
}

vector<Cell> getNextCells(Cell &curCell, char tile, int mapLimit) { 
    vector<Cell> cellChanges = DIGITAL_TILE[tile];
    vector<Cell> nextCells;

    for (auto &cellChange : cellChanges) {
        int nextRow = curCell.row + cellChange.row;
        int nextCol = curCell.col + cellChange.col;
        if (isInRange(nextRow, mapLimit) && isInRange(nextCol, mapLimit)) {
            nextCells.push_back({nextRow, nextCol});
        }
    }
    return nextCells;
}

vector<Cell> bfs(Cell &startingCell, vector<string> &pileMap, char startTile) {
    vector<vector<bool>> visited(pileMap.size(), vector<bool>(pileMap[0].size()));
    vector<Cell> order;

    int mapSize = pileMap.size();

    stack<Cell> bfsQueue;
    visited[startingCell.row][startingCell.col] = true;
    order.push_back(startingCell);

    vector<Cell> initCells = getNextCells(startingCell, startTile, mapSize);
    for (auto cell : initCells) {
        bfsQueue.push(cell);
    }

    int loopSize = 0;

    while (!bfsQueue.empty()) {
        Cell curCell = bfsQueue.top();
        bfsQueue.pop();

        // if you dfs, the final case is the queue have 2 the same node
        // so this loop condition appear when the queue remain a visited node
        if (visited[curCell.row][curCell.col]) {
            return order;
        }

        visited[curCell.row][curCell.col] = true;
        loopSize++;
        order.push_back(curCell);

        vector<Cell> nextCells = getNextCells(curCell, pileMap[curCell.row][curCell.col], mapSize);
        for (auto nextCell : nextCells){
            if (!visited[nextCell.row][nextCell.col]) {
                bfsQueue.push(nextCell);
            }
        }
    }

    return {};
}

int squareOfPolynomial(vector<Cell> &points) {
    if (points.size() == 0) {
        return 0;
    }
    int square = 0;
    int numPoints = points.size();
    for (int i = 1; i < numPoints; i++) {
        square += points[i - 1].row * points[i].col - points[i].row * points[i - 1].col;
    }

    square += points[numPoints - 1].row * points[0].col - points[0].row * points[numPoints - 1].col;

    return abs(square) / 2;
}

int getMaximumLoopSize(Cell &startingCell, vector<string> &pileMap) {
    int maxSize = INT_MIN;
    for (auto &[tileType, _] : DIGITAL_TILE) {
        vector<Cell> path = bfs(startingCell, pileMap, tileType);
        if (path.size() != 0) {
            int square = squareOfPolynomial(path);
            cout << square + 1 - path.size() / 2 << "\n";
            if (path.size() != 0) {
                maxSize = max(maxSize, (int)path.size());
            }

        }
    }
    return maxSize;
}

vector<string> getPileMapFromIO() {
    vector<string> pileMap;
    int mapSize;
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++) {
        string s;
        cin >> s;
        pileMap.push_back(s);
    }

    return pileMap;
}


void solve() {
    int mapSize;

    vector<string> pileMap = getPileMapFromIO();

    Cell startingCell = locateStartingCell(pileMap);
    int maxLoopSize = getMaximumLoopSize(startingCell, pileMap);
    if (maxLoopSize % 2 == 0) {
        cout << maxLoopSize / 2;
    } else {
        cout << maxLoopSize / 2 + 1;
    }
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