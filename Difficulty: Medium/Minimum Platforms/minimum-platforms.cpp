//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       int n = arr.size();
    int res = 0;

    // Find the max Departure time 
    int maxDep = dep[0];
    for (int i=1; i<n; i++) {
        maxDep = max(maxDep, dep[i]);
    }

    // Create a vector to store the count of trains at each
    // time
    vector<int> v(maxDep + 2, 0);
    
    // Increment the count at the arrival time and decrement
    // at the departure time
    for (int i = 0; i < n; i++) {
        v[arr[i]]++;
        v[dep[i] + 1]--;
    }
    
    int count = 0;
    
    // Iterate over the vector and keep track of the maximum
    // sum seen so far
    for (int i = 0; i <= maxDep + 1; i++) {
        count += v[i];
        res = max(res, count);
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
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends