//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    vector<int> getLeftMax(vector<int> arr,int n)
    {
        vector<int> leftMax(n);
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],arr[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int> arr,int n)
    {
        vector<int> rightMax(n);
        rightMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],arr[i]);
        }
        return rightMax;
    }
    int trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==1 || n==0)
            return 0;
        vector<int> leftMax = getLeftMax(arr,n);
        vector<int> rightMax = getRightMax(arr,n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += min(leftMax[i],rightMax[i])-arr[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends