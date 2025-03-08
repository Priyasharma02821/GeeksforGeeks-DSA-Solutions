//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
      int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    // Traverse the input string
    for (int i = 0; i < n; i++) {

        // THIS RUNS TWO TIMES 
        // for both odd and even length
        // palindromes. j = 0 means odd
        // and j = 1 means odd length
        for (int j = 0; j <= 1; j++) {
            int low = i;
            int high = i + j; 

            // Expand substring while it is a palindrome
            // and in bounds
            while (low >= 0 && high < n && s[low] == s[high]) {
                int currLen = high - low + 1;
                if (currLen > maxLen) {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                high++;
            }
        }
    }

    return s.substr(start, maxLen); 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends