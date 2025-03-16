//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0; 
        
        int jumps = 0, farthest = 0, current_end = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]); 
            
            
            if (i == current_end) {
                jumps++;            
                current_end = farthest;  
                
                
                if (current_end >= n - 1) {
                    return jumps;
                }
            }
            
            // If we can't move forward
            if (farthest <= i) {
                return -1;
            }
        }
        
        return -1;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends