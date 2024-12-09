//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isIdentical(vector<int> &arr1, vector<int> &arr2) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        if (arr1==arr2) return true;
        else return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr1, arr2;
        int num;
        while (ss >> num) {
            arr1.push_back(num);
        }
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while (ss >> num) {
            arr2.push_back(num);
        }
        Solution ob;
        bool ans = ob.isIdentical(arr1, arr2);
        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends