//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		   if(n<0 || (n%10==0 && n!=0))
		        return "No";
		    int rev=0;
		    while(n>rev)
		    {
		        rev=rev*10+n%10;
		        n=n/10;
		    }
		    if(n==rev || n==rev/10)
		        return "Yes";
		        
		    return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends