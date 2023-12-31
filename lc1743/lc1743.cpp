#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

class Solution {
public:
    vector<int> array;
    void dfs(int currentElement, unordered_map<int, vector<int>> &listAdjs, unordered_map<int, bool> &isVisited) {
        if (isVisited[currentElement]) {
            return;
        }
        isVisited[currentElement] = true;
        array.push_back(currentElement);
        for (int nextElement : listAdjs[currentElement]) {
            dfs(nextElement, listAdjs, isVisited);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjPairs;

        for (auto &adjPair : adjacentPairs) {
            adjPairs[adjPair[0]].push_back(adjPair[1]);
            adjPairs[adjPair[1]].push_back(adjPair[0]);
        }

        int firstElement;
        for (auto &[num, listAdj] : adjPairs) {
            if (listAdj.size() == 1) {
                firstElement = num;
                break;
            }
        }


        unordered_map<int, bool> isVisited;
        dfs(firstElement, adjPairs, isVisited);


        return array;

    }
};

void solve() {
  vector<vector<int>> adjPairs = {
    {4,-2},{1,4},{-3,1}
  };

  Solution *sol = new Solution();
  sol->restoreArray(adjPairs);
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

