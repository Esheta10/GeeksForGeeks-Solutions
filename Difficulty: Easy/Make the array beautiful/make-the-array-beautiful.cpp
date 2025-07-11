//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
    vector<int> res;
        for(int i =0;i<arr.size();i++){
            if(res.size() == 0)res.push_back(arr[i]);
            else{
                if((res.back()>0 && arr[i]<0) || (res.back()<0 && arr[i]>0) ||
                (arr[i] == 0 && res.back()<0) || (res.back() == 0 && arr[i]<0))res.pop_back();
                else res.push_back(arr[i]);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends