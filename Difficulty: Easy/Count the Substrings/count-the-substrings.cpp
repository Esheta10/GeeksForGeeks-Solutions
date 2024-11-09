//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int n=S.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int upperCount=0,lowerCount=0;
            for(int j=i;j<n;j++)
            {
                if(isupper(S[j]))
                    upperCount++;
                else if(islower(S[j]))
                    lowerCount++;
                    
                if(upperCount==lowerCount)
                    count++;
            }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    
cout << "~" << "\n";
}
}  
// } Driver Code Ends