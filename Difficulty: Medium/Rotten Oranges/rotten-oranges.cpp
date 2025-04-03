//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return -1;
    
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    int time = 0;
    
    // Initialize the queue with all initially rotten oranges and count fresh oranges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 2) {
                q.push({i, j});
            } else if (mat[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    if (fresh == 0) return 0; // No fresh oranges to rot
    
    // Directions for up, down, left, right
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty() && fresh > 0) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            
            for (auto dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                    mat[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
        if (!q.empty()) time++;
    }
    
    return fresh == 0 ? time : -1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends