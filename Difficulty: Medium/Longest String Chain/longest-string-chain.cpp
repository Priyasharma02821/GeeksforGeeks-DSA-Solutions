//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Custom comparison function to sort strings by their lengths
bool static cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

// Function to find the length of the longest string chain
int longestStringChain(vector<string>& words) {
  
    // Sort the words by length
    sort(words.begin(), words.end(), cmp);

    // Create an unordered map to store the 
    // maximum chain length for each word
    unordered_map<string, int> dp;

    int res = 1;

    // Iterate through each word in the sorted list of words
    for (const string& w : words) {
      
        dp[w] = 1; // Initialize length for the current word
      
        // Try removing one character at a time to 
       // check if it forms a valid predecessor
        for (int i = 0; i < w.size(); ++i) {
            string pred = w.substr(0, i) + w.substr(i + 1);
            if (dp.find(pred) != dp.end()) {
                dp[w] = max(dp[w], dp[pred] + 1);
            }
        }
      
        res = max(res, dp[w]);
    }

    return res;  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends