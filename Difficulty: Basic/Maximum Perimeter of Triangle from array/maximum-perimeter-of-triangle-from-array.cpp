//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
        // code here.
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        for(int i = n-3; i>=0; i--) {
            //nums[i] < nums[i+1] < nums[i+2]
            
            if(arr[i] + arr[i+1] > arr[i+2]) //a + b > c
                return arr[i] + arr[i+1] + arr[i+2];
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Program
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.maxPerimeter(arr) << endl;
    }
}

// } Driver Code Ends