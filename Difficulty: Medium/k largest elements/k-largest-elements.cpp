//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>> p;
	  for(int i=0; i<k; i++){
	      p.push(arr[i]);
	  }
	  for(int i=k; i<n; i++){
	      if(arr[i]>p.top()){
	          p.pop();
	          p.push(arr[i]);
	      }
	  }
	vector<int> result;
    while (!p.empty()) {
        result.push_back(p.top());
        p.pop();
    }
    
    
    sort(result.rbegin(), result.rend());
    
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends