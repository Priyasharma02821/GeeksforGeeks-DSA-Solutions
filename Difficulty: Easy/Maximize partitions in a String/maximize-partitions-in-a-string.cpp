//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
    // r: Stores the maximum number 
    // of partitions 
    // k: Stores the ending index 
    // of the partition 
    int i = 0, j = 0, k = 0; 
    int c = 0, r = 0; 
 
    // Stores the last index 
    // of every unique character 
    // of the string 
    unordered_map<int,int> m; 
 
    // Traverse the string and 
    // store the last index 
    // of every character 
    for (i = s.length() - 1; 
        i >= 0; 
        i--) { 
 
        if (m[s[i]] == 0) { 
            m[s[i]] = i; 
        } 
    } 
 
    i = 0; 
 
    // Store the last index of the 
    // first character from map 
    k = m[s[i]]; 
 
    for (i = 0; i < s.length(); i++) { 
 
        if (i <= k) { 
            c = c + 1; 
 
            // Update K to find 
            // the end of partition 
            k = max(k, m[s[i]]); 
        } 
 
        // Otherwise, the end of 
        // partition is found 
        else { 
 
            // Increment r 
            r = r + 1; 
            c = 1; 
 
            // Update k for the 
            // next partition 
            k = max(k, m[s[i]]); 
        } 
    } 
 
    // Add the last partition 
    if (c != 0) { 
        r = r + 1; 
    } 
    return r; 
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends