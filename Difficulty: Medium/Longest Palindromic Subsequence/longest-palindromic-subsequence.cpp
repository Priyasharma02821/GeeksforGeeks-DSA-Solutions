//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.size();

    // Create two vectors: one for the current state (dp)
    // and one for the previous state (dpPrev)
    vector<int> curr(n), prev(n);

    // Loop through the string in reverse (starting from the end)
    for (int i = n - 1; i >= 0; --i){

        // Initialize the current state of dp
        curr[i] = 1;

        // Loop through the characters ahead of i
        for (int j = i + 1; j < n; ++j){

            // If the characters at i and j are the same
            if (s[i] == s[j]){

                // Add 2 to the length of the palindrome between them
                curr[j] = prev[j - 1] + 2;
            }
            else{

                // Take the maximum between excluding either i or j
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }

        // Update previous to the current state of dp
        prev = curr;
    }

    return curr[n-1];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends