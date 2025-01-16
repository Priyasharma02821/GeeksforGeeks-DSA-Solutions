//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> cumSumMap;  
    int sum = 0, maxLength = 0;
    int N=arr.size();

    for (int i = 0; i < N; i++) {
        sum += arr[i];  

        
        if (sum == k) {
            maxLength = i + 1;
        }

      
        if (cumSumMap.find(sum - k) != cumSumMap.end()) {
            maxLength = max(maxLength, i - cumSumMap[sum - k]);
        }

        
        if (cumSumMap.find(sum) == cumSumMap.end()) {
            cumSumMap[sum] = i;
        }
    }

    return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends