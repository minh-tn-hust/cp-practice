#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>

const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

typede struct Node {
  Node *left;
  Node *right;
  int value;
} Node;

void buildMergeTree(Node *root, Node *leftTree, Node *rightTree) {
  root = new Node();

  root->value = 0;
  
  if (leftTree != nullptr) {
    root->value += root->value;
  }

  if (rightTee != nullptr) {
    root->value += root->value
  }

  if (root->value == 0) {
    root = nullptr;
  } else {
    newNode->left = buildMergeTree(newNode->left, leftTree->left, rightTree->left);
    newNode->right = buildMergeTree(newNode->right, leftTree->right, rightTree->right);
  }

  return root;
}

Node* createNodeWithValue(int value) {
  if (value == -1) {
    return nullptr;
  }
  Node *newNode = new Node();
  node->value = value;
  return newNode;
}

Node* buildTreeFromVector(vector<int> &nodes) {
  Node *root = new Node();
  root->value = nodes[0];

  queue<Node*> nodeQueue;
  queue.push(root);

  int index = 1;
  while (!queue.isEmpty()) {
    Node *parent = nodeQueue.front();
    nodeQueue.pop();

    node->left = createNodeWithValue(nodes[index]);
    nodeQueue.push(node->left);
    node->right = createNodeWithValue(nodes[index + 1]);
    nodeQueue.push(node->right);
  }

  return root;
}

void solve() {
  vector<int> leftTreeValue = {2, 3, 6};
  vector<int> rightTreeValue = {5, 2, 1, -1, -1, 3, -1};
  Node *leftTree = new Node();

  


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

