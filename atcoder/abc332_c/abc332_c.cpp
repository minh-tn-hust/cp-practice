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

template <typename a>
void __print(const a &x);
template <typename a, typename b>
void __print(const pair<a, b> &p);
template <typename... a>
void __print(const tuple<a...> &t);
template <typename t>
void __print(stack<t> s);
template <typename t>
void __print(queue<t> q);
template <typename t, typename... u>
void __print(priority_queue<t, u...> q);
template <typename a>
void __print(const a &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename a, typename b>
void __print(const pair<a, b> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... a>
void __print(const tuple<a...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ", "), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename t>
void __print(stack<t> s) {
    vector<t> debugvector;
    while (!s.empty()) {
        t t = s.top();
        debugvector.push_back(t);
        s.pop();
    }
    reverse(debugvector.begin(), debugvector.end());
    __print(debugvector);
}
template <typename t>
void __print(queue<t> q) {
    vector<t> debugvector;
    while (!q.empty()) {
        t t = q.front();
        debugvector.push_back(t);
        q.pop();
    }
    __print(debugvector);
}
template <typename t, typename... u>
void __print(priority_queue<t, u...> q) {
    vector<t> debugvector;
    while (!q.empty()) {
        t t = q.top();
        debugvector.push_back(t);
        q.pop();
    }
    __print(debugvector);
}
void _print() { cerr << "]\n"; }
template <typename head, typename... tail>
void _print(const head &h, const tail &...t) {
    __print(h);
    if (sizeof...(t))
        cerr << ", ";
    _print(t...);
}

#ifndef online_judge
#define debug(...) cerr << "line:" << __line__ << " [" << #__va_args__ << "] = ["; _print(__va_args__)
#else
#define debug(...)
#endif

const int max_n = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;


void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int maximumremaint = 10000;
    int temps = 10000;
    int tempm = m;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            temps = 10000;
            tempm = m;
        } 

        if (s[i] == '1') {
            if (tempm > 0) {
                tempm--;
            } else {
                temps--;
            }
        }

        if (s[i] == '2') {
            temps--;
        }
                
        maximumremaint = min(maximumremaint, temps);
    }

    cout << 10000 - maximumremaint;

}


int main() {

#ifdef local
  string file_name = "local";
  freopen((file_name + ".in").c_str(), "r", stdin);
  freopen((file_name + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}