//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // your code here
        int n = arr.size();
        int count = 0;
        int maj = 0;
        
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                maj = arr[i];
                count = 1;
            }
            else if(arr[i]==maj)
                count++;
            else
                count--;
        }
       int freq = 0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==maj)
            freq++;
       }
       if(freq > floor(n/2))
            return maj;
    
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends