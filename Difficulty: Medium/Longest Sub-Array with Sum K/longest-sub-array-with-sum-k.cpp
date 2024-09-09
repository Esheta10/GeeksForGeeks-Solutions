//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int result=0;
        int cumSum=0;
        map<int,int> mp;
        mp.insert({0,-1});
        for(int i=0;i<N;i++)
        {
            cumSum += A[i];
            if(mp.find(cumSum-K)!=mp.end())
            {
                result = max(result,i-mp[cumSum-K]);
            }
            if(mp.find(cumSum)==mp.end())
            {
                mp[cumSum]=i;
            }
            //mp[cumSum]++;
        }
        return result;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends