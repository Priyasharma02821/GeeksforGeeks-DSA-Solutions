//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int maxVolume= 0;
        int volume=0;
        int l=0, r=n-1;
        while(l<r){
            volume = min(arr[l],arr[r])* (r-l);
            maxVolume = max(maxVolume, volume);
            if(arr[l]<arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxVolume;
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