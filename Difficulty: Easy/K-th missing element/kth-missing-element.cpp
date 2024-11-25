//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int KthMissingElement(vector<int> &arr, int &k) {
        // Complete the function
        int start=0;
        int end=arr.size()-1;
        int ans;
        int mid;
        int anss;
        if(((arr[end]-arr[0])-end)<k)
        return -1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(((arr[mid]-arr[0])-mid)>=k)
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        anss=(arr[ans-1]+(k-((arr[ans-1]-arr[0])-(ans-1))));
        return anss;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.KthMissingElement(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends