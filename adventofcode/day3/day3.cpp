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

int stringToNum(string s) {
    return atoi(s.c_str());
}

bool isSymbol(char c) {
    return !(c >= '0' && c <= '9' || c == '.');
}

bool isNumber(char c) {
    return (c >= '0' && c <= '9');
}

typedef struct NumberLocation {
    int row, leftCol, rightCol;

    NumberLocation() {};
    NumberLocation(int row, int leftCol, int rightCol) : row(row), leftCol(leftCol), rightCol(rightCol) {};
    bool isAnySymbolAround(vector<string> &engine) {
        int size = engine.size();
        for (int r = max(0, row - 1); r <= min(size - 1, row + 1); r++) {
            for (int c = max(0, leftCol - 1); c <= min(size - 1, rightCol + 1); c++) {
                if (isSymbol(engine[r][c])) {
                    return true;
                }
            }
        }
    }

    void printArea(vector<string> &engine) {
        // int size = engine.size();
        // for (int r = max(0, row - 1); r <= min(size - 1, row + 1); r++) {
        //     for (int c = max(0, leftCol - 1); c <= min(size - 1, rightCol + 1); c++) {
        //         cout << engine[r][c];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

    }
};

vector<NumberLocation> extractNumberLocation(vector<string> &engine) {
    int size = engine.size();
    vector<NumberLocation> nums;

    for (int r = 0; r < size; r++) {
        int beginNum = -1;
        for (int c = 0; c < size; c++) {
            if (isNumber(engine[r][c])) {
                if (beginNum == -1) {
                    beginNum = c;
                }
            } else {
                if (beginNum != -1) {
                    nums.push_back({r, beginNum, c - 1});
                    beginNum = -1;
                }
            }

        }
    }

    return nums;
}

void solve() {
    vector<string> engine;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        string row;
        cin >> row;
        engine.push_back(row);
    }
    
    vector<NumberLocation> nums = extractNumberLocation(engine);

    int sum = 0;
    int lastRow = 0;
    for (auto &location : nums) {
        if (location.isAnySymbolAround(engine)) {
            string num = engine[location.row].substr(location.leftCol, location.rightCol - location.leftCol + 1);
            cerr << num << " ";
            if (lastRow != location.row) {
                cerr << "\n";
                lastRow = location.row;
            }
            sum += stringToNum(num);
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