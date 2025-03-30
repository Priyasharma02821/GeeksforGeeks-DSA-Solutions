//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();  
  
    // Variables to track total and current remaining gas
    int totalGas = 0;
    int currGas = 0;
    int startIdx = 0;

    // Traverse through each station to calculate remaining
    // gas in the tank, and total gas 
    for(int i = 0; i < n; i++) {
      	currGas += gas[i] - cost[i]; 
        totalGas += gas[i] - cost[i];  

        // If currGas is negative, circular tour can't 
      	// start with this index, so update it to next one
        if(currGas < 0) {
            currGas = 0;
            startIdx = i + 1; 
        }
    }

    // No solution exist
    if(totalGas < 0) 
        return -1;

    return startIdx;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends