//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canEatAll(vector<int>& arr,int mid,int k)
    {
        int actualHours=0;
        for(int &x:arr)
        {
            actualHours += x/mid;
            
            if(x%mid!=0)
                actualHours++;
        }
        return actualHours <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int l=1;
        int r=*max_element(arr.begin(),arr.end());
        
        while(l<r)
        {
            int mid=l+(r-l)/2;
            
            if (canEatAll(arr,mid,k))
                r=mid;
            else
                l=mid+1;
        }
        return l;
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

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends