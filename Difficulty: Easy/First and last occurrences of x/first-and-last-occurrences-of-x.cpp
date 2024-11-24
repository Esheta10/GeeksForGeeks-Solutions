//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findLeftMost(vector<int> arr,int x,int n)
    {
        int l=0,r=n-1;
        int left_most=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]==x)
            {
                left_most=mid;//possibly the answer
                r=mid-1;//look on the left side
            }
            else if(arr[mid]<x)
                l=mid+1;
            else
                r=mid-1;
        }
        return left_most;
    }
    int findRightMost(vector<int>arr,int x,int n)
    {
        int l=0,r=n-1;
        int right_most=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]==x)
            {
                right_most=mid;//possibly the answer
                l=mid+1;//look on the right side
            }
            else if(arr[mid]<x)
                l=mid+1;
            else 
                r=mid-1;
        }
        return right_most;
    }
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Code here
        int n=arr.size();
        
        int left_most = findLeftMost(arr,x,n);
        int right_most = findRightMost(arr,x,n);
        
         // Handle the case when x is not present in the array
        if (left_most == -1) return {-1};
    
        return {left_most,right_most};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends