//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum element from array a[] and
    // the minimum element from array b[] and return their product.
    long long find_multiplication(vector<int> &arr1, vector<int> &arr2) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.rbegin(), arr2.rend());
        int n=arr1.size();
        int m= arr2.size();
        int product = arr1[n-1]*arr2[m-1];
        return product;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.find_multiplication(arr1, arr2);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends