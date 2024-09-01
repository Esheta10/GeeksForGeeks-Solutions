//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    if(N==0)
        return ;
    string binary="";
    while(N>0)
    {
        binary=binary + std::to_string(N%2);
        N=N/2;
    }
    reverse(binary.begin(),binary.end());
    cout<<binary;
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends