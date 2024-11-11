//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int countSubstringWithEqualEnds(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    int count=0;
	    
	    unordered_map<char,int> freq;
	    
	    for(char &ch:s)
	    {
	        freq[ch]++;
	    }
	    for(auto &pair : freq)
	    {
	        int f = pair.second;
	        count += (f*(f+1))/2;
	        
	    }
	    return count;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   	    Solution ob;

   		cout << ob.countSubstringWithEqualEnds(str) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends