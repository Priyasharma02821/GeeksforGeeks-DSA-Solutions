//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        // Monotonic Queue to store maximum and minimum elements
    deque<int> minQueue, maxQueue;
    
    // Pointers to mark the range of current subarray
    int n = arr.size(), start = 0, end = 0;
    
    // Pointers to mark the range of maximum subarray
    int resStart = 0, resEnd = 0;
    while (end < n) {
        
        // Pop the elements greater than current element
        // from min Queue
        while (!minQueue.empty()
               && arr[minQueue.back()] > arr[end])
            minQueue.pop_back();
            
        // Pop the elements smaller than current element
        // from max Queue
        while (!maxQueue.empty()
               && arr[maxQueue.back()] < arr[end])
            maxQueue.pop_back();
            
        // Push the current index to both the queues
        minQueue.push_back(end);
        maxQueue.push_back(end);
        
        // Check if the subarray has maximum difference less
        // than X
        while (arr[maxQueue.front()] - arr[minQueue.front()]
               > x) {
                   
            // Reduce the length of sliding window by moving
            // the start pointer
            if (start == minQueue.front())
                minQueue.pop_front();
            if (start == maxQueue.front())
                maxQueue.pop_front();
            start += 1;
        }
        
        // Maximize the subarray length
        if (end - start > resEnd - resStart) {
            resStart = start;
            resEnd = end;
        }
        end += 1;
    }

    // Return the longest sub-array
    vector<int> res;
    for (int i = resStart; i <= resEnd; i++)
        res.push_back(arr[i]);
        
    return res;
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
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends