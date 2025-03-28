//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        // to store results.
    int ans = 0;

    // Minimum Priority Queue to sort activities in
    // ascending order of finishing time (end[i]).
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    for (int i = 0; i < start.size(); i++)
    {
        p.push(make_pair(finish[i], start[i]));
    }

    // to store the end time of last activity
    int finishtime = -1;

    while (!p.empty())
    {
        pair<int, int> activity = p.top();
        p.pop();
        if (activity.second > finishtime)
        {
            finishtime = activity.first;
            ans++;
        }
    }
    return ans;
}

    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends