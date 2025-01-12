//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
   	vector<int>  common_digits(vector<int>nums){
   	   unordered_set<int> digitSet; 
    for (int num : nums) {
        while (num > 0) {
            int digit = num % 10; 
            digitSet.insert(digit); 
            num /= 10;
        }
    }

    vector<int> result(digitSet.begin(), digitSet.end());
    sort(result.begin(), result.end()); 

    return result;
   	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		vector<int> ans = ob.common_digits(nums);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends