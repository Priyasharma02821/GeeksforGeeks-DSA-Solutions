//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dupLastIndex(vector<int>& arr) {
        int n = arr.size();
    if (n < 2) return {-1, -1}; 

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] == arr[i - 1]) {
            return {i, arr[i]};
        }
    }

    return {-1, -1};
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        vector<int> result = ob.dupLastIndex(nums);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends