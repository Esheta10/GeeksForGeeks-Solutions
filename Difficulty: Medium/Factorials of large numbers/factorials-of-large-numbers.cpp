//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void multiply(vector<int>& nums,int &size,int multiplier)
    {
        int carry=0;
        for(int i=0;i<size;i++)
        {
            int result = (multiplier*nums[i])+carry;
            nums[i]=result%10;
            carry=result/10;
        }
        while(carry)
        {
            nums.push_back(carry % 10);
            carry = carry/10;
            size++;
        }
    }
    vector<int> factorial(int N){
        // code here
        vector<int> nums;
        nums.push_back(1);
        int size=1;
      
        
        for(int multiplier=2;multiplier<=N;multiplier++)
        {
            multiply(nums,size,multiplier);
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends