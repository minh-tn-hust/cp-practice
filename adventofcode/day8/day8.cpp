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

typedef struct Node {
    string name;
    Node *left;
    Node *right;
    Node(string name)  : name(name) {};
} Node;

string getString() {
    string s;
    cin >> s;
    return s;
}

long long getLonglong() {
    long long n;
    cin >> n;
    return n;
}


const int PARENT = 0;
const int LEFT_CHILD = 1;
const int RIGHT_CHILD = 2;
vector<string> split(string s, char splitter) {
    vector<string> splitString;
    int lastIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == splitter) {
            splitString.push_back(s.substr(lastIndex, i - lastIndex));
            lastIndex = i + 1;
        }
    }
}

bool isUppercase(char c) {
    return (c <= 'Z' && c >= 'A');
}

vector<string> exposeNodes(string input) {
    vector<string> nodes;
    int size = input.size();
    int firstChar = -1;
    for (int i = 0; i < size; i++) {
        if (isUppercase(input[i])) {
            if (firstChar == -1) {
                firstChar = i;
            }
        } else {
            if (firstChar != -1) {
                nodes.push_back(input.substr(firstChar, i - firstChar));
                firstChar = -1;
            }
        }
    }

    return nodes;
};

Node* getNodeFromMapByName(map<string, Node*> &nameToNode, string name) {
    if (nameToNode[name] == nullptr) {
        Node* newNode = new Node(name);
        nameToNode[name] = newNode;
    }
    return nameToNode[name];
}

map<string, Node*> convertInputIntoGraph(int numNodes) {
    map<string, Node*> nameToNode;
    for (int i = 0; i < numNodes; i++) {
        string s;
        getline(cin, s);
        vector<string> nodes  = exposeNodes(s);
        Node* parent = getNodeFromMapByName(nameToNode, nodes[PARENT]);
        Node* leftChild = getNodeFromMapByName(nameToNode, nodes[LEFT_CHILD]);
        Node* rightChild = getNodeFromMapByName(nameToNode, nodes[RIGHT_CHILD]);
        parent->left = leftChild;
        parent->right = rightChild;
    }

    return nameToNode;
}

bool fininshCondition(Node* currentNode, vector<string> &endNames) {
    return find(endNames.begin(), endNames.end(), currentNode->name) != endNames.end();
}

int traversalGraphFromBeginWithInstructions(map<string, Node*> &nameToNode, const string BEGIN,  string INSTRUCTIONS, vector<string> endNames) {
    int index = 0;
    int steps = 1;
    Node* currentNode = getNodeFromMapByName(nameToNode, BEGIN);
    int instructionSize = INSTRUCTIONS.size();
    while (true) {
        char nextInstruction = INSTRUCTIONS[index];
        if (nextInstruction == 'L') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (fininshCondition(currentNode, endNames)) {
            return steps;
        }

        index = (index + 1) % instructionSize;
        steps++;
    }
}


vector<string> getBeginNames(map<string, Node*> &nameToNode) {
    vector<string> names;
    for (auto &[name, node] : nameToNode) {
        if (name[name.size() - 1] == 'A') {
            names.push_back(name);
        }
    }

    return names;
}

vector<string> getEndNames(map<string, Node*> &nameToNode) {
    vector<string> names;
    for (auto &[name, node] : nameToNode) {
        if (name[name.size() - 1] == 'Z') {
            names.push_back(name);
        }
    }

    return names;
}

void solve() {
    string instructions = getString();
    long long numNodes = getLonglong();
    cin.ignore();

    map<string, Node*> nameToNode = convertInputIntoGraph(numNodes);

    vector<string> beginNames = getBeginNames(nameToNode);
    vector<string> endNames = getEndNames(nameToNode);

    set<int> stepRequireForEveryBeginNames;

    for (string &beginName : beginNames) {
        int numSteps = traversalGraphFromBeginWithInstructions(nameToNode, beginName, instructions, endNames);
        stepRequireForEveryBeginNames.insert(numSteps);
    }

    long long requireSteps = 1;
    for (int steps : stepRequireForEveryBeginNames) {
        requireSteps = lcm(requireSteps, steps);
    }

    cout << requireSteps;

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