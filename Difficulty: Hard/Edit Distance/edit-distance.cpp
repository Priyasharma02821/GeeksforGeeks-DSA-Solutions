//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.size();
    int n = s2.size();
    
    // Stores dp[i-1][j-1]
    int prev; 
    vector<int> curr(n + 1, 0); 

    for (int j = 0; j <= n; j++)
        curr[j] = j;
  
    for (int i = 1; i <= m; i++) {
        prev = curr[0]; 
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = curr[j];
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev;
            else
                curr[j] = 1 + min({curr[j - 1], prev, curr[j]});
            prev = temp;
        }
    }
    
    return curr[n];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends