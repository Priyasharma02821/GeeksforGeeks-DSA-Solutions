//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
    vector<int> span(n);
    stack<int> s; 

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while stack is not empty and top element is less than or equal to current price
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // If stack is empty, it means no greater element on left, so span is i+1
        span[i] = s.empty() ? (i + 1) : (i - s.top());

        // Push current index onto stack
        s.push(i);
    }

    return span;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends