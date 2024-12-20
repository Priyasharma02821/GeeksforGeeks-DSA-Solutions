//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the difference between the maximum and minimum frequency of
    // elements.
    int findDiff(vector<int>& arr) {
    unordered_map<int, int> freqMap;

    
    for (int num : arr) {
        freqMap[num]++;
    }

    int maxFreq = INT_MIN, minFreq = INT_MAX;

   
    for (auto& pair : freqMap) {
        maxFreq = max(maxFreq, pair.second);
        minFreq = min(minFreq, pair.second);
    }

    
    return (maxFreq == minFreq) ? 0 : (maxFreq - minFreq);

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
        cout << ob.findDiff(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends