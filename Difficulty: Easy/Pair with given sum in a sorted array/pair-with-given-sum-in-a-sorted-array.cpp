//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPair(int k, vector<int> &arr) {
        // Complete the function
        int i=0;
        int j=arr.size()-1;
        int count=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum<k)
                i++;
            else if(sum>k)
                j--;
            else
            {
               count++;
               i++;
               j--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        int k;
        cin >> k;
        string input;
        getline(cin, input);
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.countPair(k, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends