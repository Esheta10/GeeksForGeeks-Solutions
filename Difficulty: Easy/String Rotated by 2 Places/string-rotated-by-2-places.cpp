//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
      if (str1.length() != str2.length() || str1.length() < 2 || str2.length() < 2) {
        return false; // Safely handle cases where rotation isn't possible
    }
    
    // Left rotation of a by 2 places
    string leftRotate = str1.substr(2) + str1.substr(0, 2);
    
    // Right rotation of a by 2 places
    string rightRotate = str1.substr(str1.length() - 2) + str1.substr(0, str1.length() - 2);
    
    // Check if either rotation matches b
    return (leftRotate == str2 || rightRotate == str2);
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends