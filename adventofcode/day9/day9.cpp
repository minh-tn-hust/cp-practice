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

vector<string> split(string s, char splitter) {
    vector<string> splitString;
    int lastIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == splitter) {
            splitString.push_back(s.substr(lastIndex, i - lastIndex));
            lastIndex = i + 1;
        }
    }

    if (lastIndex != s.size()) {
        splitString.push_back(s.substr(lastIndex));
    }

    return splitString;
}

long long stringToNum(string s) {
    return atoi(s.c_str());
}

vector<int> exposeSensorHistory(string sensorHistory) {
    vector<string> sensorValues = split(sensorHistory, ' ');

    vector<int> history;
    for (auto sensorValue : sensorValues) {
        history.push_back(stringToNum(sensorValue));
    }

    return history;
}

int isHistoryStability(vector<int> &history) {
    for (auto value : history) {
        if (value != 0) {
            return false;
        }
    }
    return true;
}

long long extrapolate(vector<int> &history) {
    if (isHistoryStability(history)) {
        return 0;
    }

    vector<int> extrapolateHistory;
    int historySize = history.size();
    for (int i = 1; i < historySize; i++) {
        extrapolateHistory.push_back(history[i] - history[i - 1]);
    }

    long long firstValue = history[0];
    
    return firstValue - extrapolate(extrapolateHistory);
}



void solve() {
    int numSensors;
    cin >> numSensors;
    cin.ignore();

    long long sumOfExtrapolaValues = 0;
    for (int i = 0; i < numSensors; i++) {
        string sensorOutput;
        getline(cin, sensorOutput);

        vector<int> history = exposeSensorHistory(sensorOutput);
        long long nextValue = extrapolate(history);
        sumOfExtrapolaValues += nextValue;
    }

    cout << sumOfExtrapolaValues;
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