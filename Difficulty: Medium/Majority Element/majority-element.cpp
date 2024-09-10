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
        int n=arr.size();
        
        if (n == 1) return arr[0];
        if (n == 2) return arr[0] == arr[1] ? arr[0] : -1;
        
        int maj1=INT_MIN;
        int count1=0;
        
        int maj2=INT_MIN;
        int count2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==maj1)
            {
                count1++;
            }
            else if(arr[i]==maj2)
            {
                count2++;
            }
            else if(count1==0)
            {
                maj1=arr[i];
                count1=1;
            }
            else if(count2==0)
            {
                maj2=arr[i];
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        int freq1=0,freq2=0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == maj1) freq1++;
            else if (arr[i] == maj2) freq2++;
        }
        if(freq1>n/2)
            return maj1;
        if(freq2>n/2)
            return maj2;
       
        
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