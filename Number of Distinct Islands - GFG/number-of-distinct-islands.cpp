//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int x, int y, vector<vector<int>> &grid, set<vector<bool>> &s, vector<bool> &vec) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            vec.push_back(0);
            return;
        }
        
        vec.push_back(1);
        grid[x][y] = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != dy && dx*dy == 0) {
                    dfs(x + dx, y + dy, grid, s, vec);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<bool>> s;
        vector<bool> vec;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, s, vec);
                    s.insert(vec);
                    vec = {};
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends