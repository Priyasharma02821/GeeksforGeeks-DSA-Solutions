//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getCount(vector<int> &arr, int num1, int num2) {
        int n = arr.size();
    int left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == num2) {
            right = i;
            break;
        }
    }
    if (left == -1 || right == -1 || left >= right) {
        return 0;
    }
    return right - left - 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int num1, num2;
        cin >> num1 >> num2;
        cin.ignore();
        Solution ob;
        cout << ob.getCount(arr, num1, num2) << "\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends