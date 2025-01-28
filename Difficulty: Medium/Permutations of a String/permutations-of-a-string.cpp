//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void backtrack(string &s, vector<string> &result, string &current, vector<bool> &visited) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        // Skip already visited characters
        if (visited[i]) continue;
        
        // Skip duplicates: if the current character is the same as the previous one
        // and the previous one hasn't been visited in this recursive path.
        if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;
        
        // Choose the character
        visited[i] = true;
        current.push_back(s[i]);
        
        // Explore further
        backtrack(s, result, current, visited);
        
        // Undo the choice
        current.pop_back();
        visited[i] = false;
    }
}

vector<string> findPermutation(string &s) {
    vector<string> result;
    string current;
    vector<bool> visited(s.size(), false);
    
    // Sort the string to handle duplicates
    sort(s.begin(), s.end());
    
    // Start backtracking
    backtrack(s, result, current, visited);
    
    return result;
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends