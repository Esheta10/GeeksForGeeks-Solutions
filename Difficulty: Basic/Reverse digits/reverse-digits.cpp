//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    // Code here
	        long long int rev=0;
		    int sign=n<0?-1:1;
		    n=abs(n);//work with positive value for simplicity
		    while(n>0)
		    {
		        int digit=n%10;
		        
		        rev=rev*10+digit;
		        n=n/10;
		    }
		    return rev*sign;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends