//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
       stack<int> st;

    // Loop through each element in the vector
    for (string token : arr) {
        
        // If it's an operand (number), push it onto
        // the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
        } 
        
        // Otherwise, it must be an operator
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends