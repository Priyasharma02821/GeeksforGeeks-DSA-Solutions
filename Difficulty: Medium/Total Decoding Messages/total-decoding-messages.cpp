//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.length();

    // If the string is empty or starts with '0',
    // there are no valid decodings.
    if (n == 0 || digits[0] == '0')
    {
        return 0;
    }

    // two variables to store the previous two results.
    int prev1 = 1, prev2 = 0;

    for (int i = 1; i <= n; ++i)
    {
        int current = 0;

        // Check for valid single-digit decoding
        if (digits[i - 1] != '0')
        {
            current += prev1;
        }

        // Check for valid two-digit decoding
        // (previous digit and current digit form a
        // valid number between 10 and 26)
        if (i > 1)
        {
            int twoDigit = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26)
            {
                current += prev2;
            }
        }

        // Update prev1 and prev2 for the next iteration.
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends