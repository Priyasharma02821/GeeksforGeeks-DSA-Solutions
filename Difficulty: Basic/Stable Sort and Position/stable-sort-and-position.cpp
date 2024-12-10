//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function template in C++

class Solution {

  public:
    // Function to get the index of an element in a sorted array.
    int getIndexInSortedArray(vector<int>& arr, int k) {
        vector<pair<int, int>> indexedArr;
    for (int i = 0; i < arr.size(); i++) {
        indexedArr.push_back({arr[i], i});
    }

    
    stable_sort(indexedArr.begin(), indexedArr.end());

    
    int number = arr[k]; 
    for (int i = 0; i < indexedArr.size(); i++) {
        if (indexedArr[i].first == number && indexedArr[i].second == k) {
            return i;  
        }
    }

    return -1;
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
        Solution obj;
        int res = obj.getIndexInSortedArray(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends