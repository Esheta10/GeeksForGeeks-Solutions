//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int originalNumber = N;
        int count=0;
        while(N>0)
        {
            int lastDigit=N%10;
            // Check if the last digit is a divisor of the original number
            if (lastDigit != 0 && originalNumber % lastDigit == 0) {
                count++;
            }
            N=N/10;
        }
       return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends