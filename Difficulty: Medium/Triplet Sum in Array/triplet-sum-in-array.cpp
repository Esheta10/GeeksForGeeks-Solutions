//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool twoSum(int arr[],int x,int i,int j)
    {
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum<x)i++;
            else if(sum>x)j--;
            else
            {
                while(i<j && arr[i]==arr[i+1])i++;
                while(i<j && arr[j]==arr[j-1])j--;
                return true;
                i++;
                j--;
            }
        }
        return false;
    }
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr,arr+n);
        
        for(int i=0;i<=n-3;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
                continue;
                
           int requiredSum=x-arr[i];
           
            if(twoSum(arr,requiredSum,i+1,n-1)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends