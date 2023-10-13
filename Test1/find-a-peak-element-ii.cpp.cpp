class Solution {
public:
    bool isPeak(vector<vector<int>> &mat, int x, int y) {
        bool isPeak = true;
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> directions = {
            {-1 , 0}, // left
            {1, 0}, // right
            {0, 1}, // top
            {0, -1} // bottom
        };

        for (auto direction : directions) {
            int xPos = x + direction.first;
            int yPos = y + direction.second;

            if (xPos < 0 || xPos >= n || yPos < 0 || yPos >= m) {
              continue;
            }

            if (mat[yPos][xPos] > mat[y][x]) {
              return false;
            }
        }

        return true;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        bool hasPeak = false;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
              if (isPeak(mat, x, y)) {
                ans.push_back(y);
                ans.push_back(x);
                hasPeak = true;
              }

              if (hasPeak) {
                break;
              }
            }
            if (hasPeak) {
              break;
            }
        }

        return ans;
    }
};