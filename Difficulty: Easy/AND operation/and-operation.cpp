//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int  find_and(int l, int r ) 
    {
        // Code here.
        int shiftCount=0;
        while(l!=r)
        {
            l = l >> 1;
            r = r >> 1;
            shiftCount++;
        }
        return l << shiftCount;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int  l, r;
    	cin >> l >> r;
    	Solution ob;
    	int ans = ob.find_and(l, r);
    	cout << ans << "\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends