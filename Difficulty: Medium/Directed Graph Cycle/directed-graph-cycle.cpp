//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> adj[V];
    vector<int> indegree(V, 0);

    // Build adjacency list and indegree array
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;

    // Push all nodes with 0 indegree
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    // If count != V, cycle exists
    return count != V;
}
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends