//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*Function to count even and odd elements in the array
     * arr : Array with its elements
     */
    vector<int> countOddEven(vector<int> &arr) {
        // your code here
        int count_even=0,count_odd=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2==0) 
                count_even++;
            else
                count_odd++;
        }
        return {count_odd,count_even};
    }
};

//{ Driver Code Starts.
int main() {

    // Testcase input
    int testcase;
    cin >> testcase;
    cin.ignore();

    while (testcase--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        vector<int> res = ob.countOddEven(arr);
        for (auto t : res) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends