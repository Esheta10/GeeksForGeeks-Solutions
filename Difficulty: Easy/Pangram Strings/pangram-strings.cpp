//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int isPanagram(string S)
	{
	    // Your code goes here 
	    vector<int> arr(26,0);
	    
	    for(char &ch: S)
	    {
	        if(isalpha(ch))
	        {
	            int index=tolower(ch)-'a';
	            arr[index]++;
	        }
	    }
	    for(int &count:arr)
	    {
	        if(count==0)
	            return 0;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		cout << ob.isPanagram(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends