//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
  vector<int> getLeftMax(vector<int>& arr,int n)
    {
        vector<int> leftMax(n);
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],arr[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>&arr,int n)
    {
        vector<int> rightMax(n);
        rightMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],arr[i]);
        }
        return rightMax;
    }
        
    long long trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==0 || n==1)
            return 0;
        vector<int> leftMax=getLeftMax(arr,n);
        vector<int> rightMax=getRightMax(arr,n);
         long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum += min(leftMax[i],rightMax[i]) - arr[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends