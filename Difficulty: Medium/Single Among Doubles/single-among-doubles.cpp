//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        //Approach-1: XOR Operation: O(n)
       /* int result = 0;
        for(int i=0;i<n;i++)
        {
            result ^= arr[i];
        }
        return result; */
        //Approach-2: Binary Search: O(log(n))
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(mid%2==0)//mid is even
            {
                if(arr[mid]==arr[mid+1])
                    l=mid+2;
                else
                    h=mid;
            }
            else//mid is odd
            {
                if(arr[mid]==arr[mid-1])
                    l=mid+1;
                else
                    h=mid;
            }
        }
        return arr[l];
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t, len;
    cin >> t;
    while (t--) {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(len, arr) << '\n';
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends