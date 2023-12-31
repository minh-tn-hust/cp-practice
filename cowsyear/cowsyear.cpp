#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const double epsilon = 1e-9;

using namespace std;

typedef struct Node {
  string cowName;
  int infoIndex;

  Node(string cowName, int infoIndex) : cowName(cowName), infoIndex(infoIndex) {};
} Node;

unordered_map<string, int> YEAR_CYCLE = {
  {"Ox" , 2 },
  {"Tiger" , 3 },
  {"Rabbit" , 4 },
  {"Dragon" , 5 },
  {"Snake" , 6 },
  {"Horse" , 7 },
  {"Goat" , 8 },
  {"Monkey" , 9 },
  {"Rooster" , 10 },
  {"Dog" , 11 },
  {"Pig" , 12 },
  {"Rat" , 1 },
};


const string PREV = "previous";
const string NEXT = "next";

int differenceYear(string yearLeft, string keyword, string yearRight) {
  int yearL = YEAR_CYCLE[yearLeft];
  int yearR = YEAR_CYCLE[yearRight];


  if (keyword == NEXT) {
    swap(yearR, yearL);
  }

  int difference;
  if (yearR < yearL) {
    difference = yearR + 12 - yearL;
  } else {
    difference = yearR - yearL;
  }

  if (yearL == yearR) {
    difference = 12;
  }

  if (keyword == PREV) {
    return -difference;
  }

  return difference;

}

void dfs(string currentVertex, unordered_map<string, vector<Node>> &adjVertex, unordered_map<string, string> &prevNode, unordered_map<string, bool> &isVisited) {
  for (auto nextVertex : adjVertex[currentVertex]) {
    if (isVisited[nextVertex.cowName] == false) {
      isVisited[nextVertex.cowName] = true;
      prevNode[nextVertex.cowName] = currentVertex;
      dfs(nextVertex.cowName, adjVertex, prevNode, isVisited);
    }
  }
}

vector<string> findPath(unordered_map<string, vector<Node>> &adjVertex, string from, string to) {
  unordered_map<string, string> prevNode;
  unordered_map<string, bool> isVisit;
  
  dfs(from, adjVertex, prevNode, isVisit);

  vector<string> path;
  path.push_back(to);
  while (to != from) {
    path.push_back(prevNode[to]);
    to = prevNode[to];
  }

  reverse(path.begin(), path.end());
  return path;
}

string getKeyWord(string from, string to, vector<string> &info)  {
  if (from == info[3]) {
    return info[1];
  } else {
    if (info[1] == PREV) {
      return NEXT;
    }
    return PREV;
  }
}

void solve() {
  unordered_map<string, vector<Node>> adjVertex;

  int N;
  cin >> N;
  vector<vector<string>> listInfo;
  for (int i = 0; i < N; i++) {
    vector<string> info;
    for (int j = 0; j < 8; j++) {
      string token;
      cin >> token;
      if (j == 0 || j == 3 || j == 4 || j == 7) {
        info.push_back(token);
      }
    }

    listInfo.push_back(info);

    adjVertex[info[0]].push_back({info[3], i});
    adjVertex[info[3]].push_back({info[0], i});
  }

  vector<string> path = findPath(adjVertex, "Bessie", "Elsie");
  string currentYear = "Ox";
  int diffecence = 0;

  for (int i = 0; i < path.size() - 1; i++) {
    int infoIndex;
    for (auto node : adjVertex[path[i]]) {
      if (node.cowName == path[i + 1]) {
        infoIndex = node.infoIndex;
        break;
      }
    }

    string keyword =  getKeyWord(path[i], path[i + 1], listInfo[infoIndex]);
    diffecence += differenceYear(listInfo[infoIndex][2], keyword, currentYear);
    currentYear = listInfo[infoIndex][2];
  }

  cout << abs(diffecence);
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

