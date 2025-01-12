//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> arranged(vector<int>& arr) {
       int n = arr.size();
    vector<int> positives, negatives;
    for (int num : arr) {
        if (num > 0) {
            positives.push_back(num);
        } else {
            negatives.push_back(num);
        }
    }
    vector<int> result;
    for (int i = 0; i < n / 2; i++) {
        result.push_back(positives[i]);
        result.push_back(negatives[i]);
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.arranged(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends