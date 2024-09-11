//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    int maxProduct(vector<int>& arr) {
        // code here
        int largest=0;
        int s_largest=0;
        for(int &num:arr)
        {
            if(num>largest)
            {
                s_largest=largest;
                largest=num;
            }
            else
            {
                s_largest=max(s_largest,num);
            }
        }
        return (largest)*(s_largest);
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
        Solution obj;
        int res = obj.maxProduct(arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends