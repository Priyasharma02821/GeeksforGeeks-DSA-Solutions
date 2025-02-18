//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate squared 
// distance from the origin
int squaredDis(vector<int>& point) {
    return point[0] * point[0] + 
      point[1] * point[1];
}

// Function to find k closest points to
// the origin
vector<vector<int>> kClosest(
  vector<vector<int>>& points, int k) {
    
    // Max heap to store points with their 
    // squared distances
    priority_queue<pair<int, vector<int>>> maxHeap;

    // Iterate through each point
    for (int i=0;i<points.size();i++) {
        int dist = squaredDis(points[i]);

        if (maxHeap.size() < k) {
            
            // If the heap size is less than k, 
            // insert the point
            maxHeap.push({dist, points[i]});
        } else {
            
            // If the heap size is k, compare with
            // the top element
            if (dist < maxHeap.top().first) {
                
                // Replace the top element if the
                // current point is closer
                maxHeap.pop();
                maxHeap.push({dist, points[i]});
            }
            // Else, ignore the current point
        }
    }

    // Take the k closest points from the heap
    vector<vector<int>> res;
    while (!maxHeap.empty()) {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return res;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends