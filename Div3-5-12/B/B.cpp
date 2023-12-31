1350#include <iostream>
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

const int LOWER_CASE_DELETE = 'b';
const int UPPER_CASE_DELETE = 'B';

bool isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

vector<pair<char, int>> getRemainningInStack(stack<pair<char, int>> &stk) {
    vector<pair<char, int>> container;
    while (!stk.empty()) {
        auto top = stk.top();
        container.push_back(top);
        stk.pop();
    }

    return container;
}

string getOutput(string inputSequence) {
    stack<pair<char, int>> lowerCase;
    stack<pair<char, int>> upperCase;
    int index = 0;
    for (char keyPress : inputSequence) {
        if (keyPress == LOWER_CASE_DELETE) {
            if (!lowerCase.empty()) {
                lowerCase.pop();
            }
        } else if (keyPress == UPPER_CASE_DELETE) {
            if (!upperCase.empty()) {
                upperCase.pop();
            }
        } else {
            if (isUpperCase(keyPress)) {
                upperCase.push({keyPress, index});
            } else {
                lowerCase.push({keyPress, index});
            }
        }
        index++;
    }

    vector<pair<char, int>> lowerCaseSequence = getRemainningInStack(lowerCase);
    vector<pair<char, int>> upperCaseSequence = getRemainningInStack(upperCase);

    vector<pair<char, int>> combineSequence(lowerCaseSequence);
    combineSequence.insert(combineSequence.end(), upperCaseSequence.begin(), upperCaseSequence.end());
    sort(combineSequence.begin(), combineSequence.end(), [&](auto a, auto b) {
        return a.second < b.second;
    });

    string output = "";
    for (auto &[keyPress, index] : combineSequence) {
        output += keyPress;
    }

    return output;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << getOutput(s) << "\n";
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