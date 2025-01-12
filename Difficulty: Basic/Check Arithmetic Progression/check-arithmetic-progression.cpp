//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkIsAP(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int r= arr[n-1]-arr[n-2];
        for(int i=1; i<arr.size(); i++){
            if((arr[i]- arr[i-1]) != r){
                return false;
            }
        }
        return true;
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
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        bool ans = ob.checkIsAP(arr);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends