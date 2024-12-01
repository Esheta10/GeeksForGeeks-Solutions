//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int result = 0;
    
    // Loop through all bit positions from 0 to the number of bits in n
    for (int i = 0; (1 << i) <= n; i++) {
        // Total number of pairs of (0, 1) at the ith bit position
        int totalPairs = (n + 1) / (1 << (i + 1));
        
        // Add the contribution of full pairs of (0, 1)
        result += totalPairs * (1 << i);
        
        // Add the remaining set bits for the last partial pair
        int remaining = (n + 1) % (1 << (i + 1));
        if (remaining > (1 << i)) {
            result += remaining - (1 << i);
        }
    }
    
    return result;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends