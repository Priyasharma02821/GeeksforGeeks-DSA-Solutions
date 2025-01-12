//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        if (n <= 2) return 0;
       long long  res=0;
       int lmax[n], rmax[n];
       lmax[0]= arr[0];
       for (int i=1; i<n; i++){
           lmax[i]= max(arr[i], lmax[i-1]);
       }
       rmax[n-1]= arr[n-1];
       for (int i=n-2; i>=0; i--){
           rmax[i]= max(arr[i], rmax[i+1]);
       }
       for (int i=1; i<n-1; i++){
           res= res+ max(0,min(lmax[i],rmax[i]) -arr[i]);       
          
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends