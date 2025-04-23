//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        int maxFreq=0,result=INT_MIN;
        for(int &num:arr)
        {
            int count=++mp[num];
            if(count>maxFreq || (count==maxFreq && num>result))
            {
                maxFreq=count;
                result=num;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ele = ob.mostFreqEle(arr);
        cout << ele << endl;
    }
}
// } Driver Code Ends