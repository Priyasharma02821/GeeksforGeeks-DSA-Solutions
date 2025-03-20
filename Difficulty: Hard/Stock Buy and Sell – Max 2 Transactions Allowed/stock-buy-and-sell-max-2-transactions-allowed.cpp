//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        // Variables to store the maximum profit 
    // after the first and second transactions
    int firstBuy = INT_MIN;  
    int firstSell = 0;      
    int secondBuy = INT_MIN; 
    int secondSell = 0;      
    
    // Iterate over each day's stock prices
    for (int i = 0; i < prices.size(); i++) {

        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]);
    }
    
    // The result is the maximum 
    // profit after the second sell
    return secondSell;
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
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends