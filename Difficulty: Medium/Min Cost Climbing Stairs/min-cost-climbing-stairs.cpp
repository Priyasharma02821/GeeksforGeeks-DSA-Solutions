//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
    
    if (n==1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for (int i=2; i<n; i++) {
        int curr = cost[i] + 
        min(prev1, prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    // Return minimum of cost to 
    // climb (n-1)th stair and 
    // cost to reach (n-2)th stair
    return min(prev1, prev2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends