//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        unordered_map<int, int> freqMap;
        int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        
        if (freqMap[complement] > 0) {
            count += freqMap[complement];
        }

        
        freqMap[arr[i]]++;
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends