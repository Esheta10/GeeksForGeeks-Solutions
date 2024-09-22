//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> nextPermutation(vector<int> arr) {
        // code here
        int n=arr.size();
        int gola_index=-1;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                gola_index=i-1;
                break;
            }
        }
        if(gola_index != -1)
        {
            int swap_index=gola_index;
            for(int j=n-1;j>=gola_index;j--)
            {
                if(arr[j]>arr[gola_index])
                    {
                        swap_index=j;
                        break;
                    }
            }
            swap(arr[gola_index],arr[swap_index]);
        }
        reverse(arr.begin()+gola_index+1,arr.end());
        return arr;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        vector<int> ans = ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends