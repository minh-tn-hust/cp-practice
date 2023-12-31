#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>
#include <math.h>


const int MAX_N = 1e5 + 5;
const double epsilon = 1e-9;

using namespace std;

const int MULTIPLE = 1;
const int DIVIED = 2;
const int ADD = 3;
const int SUBTRACT = 4;
const int POW = 5;
const int PRIORITY[6] = {0, 3, 3, 1, 1, 4};


typedef struct Node {
  int token;
  int isNumber = false;

  Node *left = nullptr;
  Node *right = nullptr;
  Node *parent = nullptr;

  bool checkIsNumber(string s) {
    if (s[0] < '0' || s[0] > '9') {
      return false;
    }
    return true;
  }

  int stringToNum(string s) {
    int size = s.size();
    int num = 0;
    int pow = 1;
    for (int i = size - 1; i >= 0; i--) {
      num += (s[i] - '0') * pow;
      pow *= 10;
    }

    return num;
  }

  Node(string s) {
    if (checkIsNumber(s)) {
      token = stringToNum(s);
      isNumber = true;
    } else {
      if (s[0] == '*') {
        token = MULTIPLE;
      }

      if (s[0] == '+') {
        token = ADD;
      }

      if (s[0] == '/') {
        token = DIVIED;
      }

      if (s[0] == '-') {
        token = SUBTRACT;
      }

      if (s[0] == '^') {
        token = POW;
      }

      isNumber = false;
    }
  }

  Node(int value) {
    token = value;
    isNumber = true;
  }

} Node;

typedef struct ExpressionTree {
  Node *root = nullptr;

  Node *rightMostChild = nullptr;

  int doExpression(int first, int second, int expression) {
    if (expression == ADD) {
      return first + second;
    }

    if (expression == SUBTRACT) {
      return second - first;
    }

    if (expression == MULTIPLE) {
      return first * second;
    }

    if (expression == DIVIED) {
      return second / first;
    }

    if (expression == POW) {
      return (int) pow(second, first);
    }
  }

  void addNode(Node *newNode)  {
    if (root == nullptr) {
      root = newNode;
      rightMostChild = newNode;
      return;
    }

    if (newNode->isNumber) {
      rightMostChild->right = newNode;
      newNode->parent = rightMostChild;
      rightMostChild = newNode;
    } else {
      // Nếu node thêm vào là "*"" / "/"
      int prevOperatorPriority;
      if (rightMostChild->parent) {
        prevOperatorPriority = PRIORITY[rightMostChild->parent->token];
      } else {
        if (rightMostChild->isNumber) {
          prevOperatorPriority = 0;
        } else {
          prevOperatorPriority = PRIORITY[rightMostChild->token];
        }
      }
      int currentOperatorPriority = PRIORITY[newNode->token];
      if(prevOperatorPriority < currentOperatorPriority) {
        if (rightMostChild->parent == nullptr) {
          newNode->left = rightMostChild;
          rightMostChild->parent = newNode;

          root = newNode;
          rightMostChild = root;
        } else {
          newNode->left = rightMostChild;
          newNode->parent = rightMostChild->parent;
          newNode->parent->right = newNode;
          rightMostChild->parent = newNode;
          rightMostChild = newNode;
        }
      } else if (prevOperatorPriority == currentOperatorPriority || prevOperatorPriority - currentOperatorPriority == 1) {
        cerr << rightMostChild->token << " " << rightMostChild->parent->token << "\n";
        Node *prevOperator = rightMostChild->parent;
        newNode->left = prevOperator;
        newNode->parent = prevOperator->parent;

        if (newNode->parent == nullptr) {
          root = newNode;
        } else {
          newNode->parent->right = newNode;
        }
        rightMostChild = newNode;
      } else {
        root->parent = newNode;
        newNode->left = root;
        root = newNode;
        rightMostChild = newNode;
      }
    }
  }

  stack<int> stk;
  void suffixOrder(Node *root) {
    if (root == nullptr) return;

    suffixOrder(root->left);
    suffixOrder(root->right);

    int currentValue = root->token;

    if (root->isNumber) {
      stk.push(currentValue);
    } else {
      int first = stk.top();
      stk.pop();
      int second = stk.top();
      stk.pop();
      cerr << doExpression(first, second, currentValue) << "\n";
      stk.push(doExpression(first, second, currentValue));
    }
  }

  int calculate() {
    suffixOrder(root);
    return stk.top();
  }

  void inorder() {
    this->inorder(root);
  }

  void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    if (root->isNumber) {
      cerr << root->token << " ";
    } else {
      if (root->token == MULTIPLE) {
        cerr << "* ";
      }

      if (root->token == ADD) {
        cerr << "+ ";
      }

      if (root->token == DIVIED) {
        cerr << "/ ";
      }

      if (root->token == SUBTRACT) {
        cerr << "- ";
      }

      if (root->token == POW) {
        cerr << "^ ";
      }
    }
    inorder(root->right);
  }
} ExpressionTree;




ExpressionTree buildTree(vector<string> token, int &index) {
  ExpressionTree newTree;
  for (index; index < token.size(); index++) {
    cerr << index << "\n";
    if (token[index] == ")") {
      return newTree;
    }

    if (token[index] == "(") {
      ExpressionTree subTree = buildTree(token, ++index);
      int value = subTree.calculate();
      Node *newNode = new Node(value);
      newTree.addNode(newNode);
      continue;
    } else {
      Node *newNode = new Node(token[index]);
      newTree.addNode(newNode);
    }

  }

  return newTree;
}

int solve(string expression) {
  vector<string> tokenize;

  int size = expression.size();

  string token = "";
  for (int i = 0; i < size; i++) {
    if(expression[i] >= '0' && expression[i] <= '9') {
      token += expression[i];
    } else {
      if (token != "") {
        tokenize.push_back(token);
      }
      string syntax = "";
      syntax += expression[i];
      tokenize.push_back(syntax);
      token = "";
    }
  }

  if (token != "") {
    tokenize.push_back(token);
  }

  int index = 0;
  ExpressionTree eTree = buildTree(tokenize, index);
  eTree.inorder();
  return eTree.calculate();
}

void test(string expression, int num) {
  int result = solve(expression);
  cout << "result = " << result << " expected = " << num << ((result == num) ? " true" : " false") << "\n";
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

  string expression1 = "(3+5)*2-9/3+4^2";
  int result1 = ((3 + 5) * 2 - 9 / 3 + pow(4, 2));

  string expression2 = "6^2/(4+2)+5-(8*2)";
  int result2 = (pow(6, 2) / (4 + 2) + 5 - (8 * 2));

  string expression3 = "2*(7-4)^2+6/2";
  int result3 = (2 * pow((7 - 4), 2) + 6 / 2);

  string expression4 = "4^2-6/(3+2)+7*2";
  int result5 = (pow(4, 2) - 6 / (3 + 2) + 7 * 2);

  string expression5 = "(8+2)*3-5^2/(9-4)";
  int result6 = ((8 + 2) * 3 - pow(5, 2) / (9 - 4));

  string expression6 = "10/(2+3)+6*(7-4)^2";
  int result7 = (10 / (2 + 3) + 6 * pow((7 - 4), 2));

  string expression7 = "5^2-(6/2)+4*(9-7)";
  int result8 = (pow(5, 2) - (6 / 2) + 4 * (9 - 7));

  test(expression1, result1);
  test(expression2, result2);
  test(expression3, result3);
  test(expression5, result5);
  test(expression6, result6);
  test(expression7, result7);
}

