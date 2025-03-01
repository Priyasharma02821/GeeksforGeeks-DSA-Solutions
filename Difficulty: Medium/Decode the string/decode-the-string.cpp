//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
    stack<int> numStack;
    string currentStr = "";
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Forming the number
        } else if (c == '[') {
            // Push current string and number to stacks
            strStack.push(currentStr);
            numStack.push(num);
            // Reset for next substring
            currentStr = "";
            num = 0;
        } else if (c == ']') {
            // Pop number from stack
            int repeatCount = numStack.top();
            numStack.pop();
            // Build repeated string
            string temp = "";
            for (int i = 0; i < repeatCount; i++) {
                temp += currentStr;
            }
            // Combine with previous part
            currentStr = strStack.top() + temp;
            strStack.pop();
        } else {
            // Append normal characters
            currentStr += c;
        }
    }
    return currentStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends