//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        
        int count1 = 0;
        int maj1 = 0;
        
        int count2 = 0;
        int maj2 = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==maj1)
                count1++;
            else if(arr[i]==maj2)
                count2++;
            else if(count1==0)
            {
                maj1 = arr[i];
                count1 = 1;
            }
            else if(count2==0)
            {
                maj2 = arr[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        count1 = 0;
        count2 = 0;
        for(int num:arr)
        {
            if(num == maj1)
                count1++;
            if(num == maj2)
                count2++;
        }
        if(count1 > floor(n/3))
            result.push_back(maj1);
        if(count2 > floor(n/3))
            result.push_back(maj2);
        
        sort(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends