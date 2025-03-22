//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
       if (arr.empty()) return 0;
        if (arr.size() == 1) return arr[0];
        
        // Helper function to solve the problem for a linear array
        auto robLinear = [](const vector<int>& nums) -> int {
            if (nums.empty()) return 0;
            if (nums.size() == 1) return nums[0];
            
            vector<int> dp(nums.size(), 0);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            
            for (size_t i = 2; i < nums.size(); ++i) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            
            return dp.back();
        };
        
        // Subproblem 1: Exclude the first house
        vector<int> subproblem1(arr.begin() + 1, arr.end());
        int result1 = robLinear(subproblem1);
        
        // Subproblem 2: Exclude the last house
        vector<int> subproblem2(arr.begin(), arr.end() - 1);
        int result2 = robLinear(subproblem2);
        
        // Return the maximum value from the two subproblems
        return max(result1, result2);
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends