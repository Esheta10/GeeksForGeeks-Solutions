//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        
        int m=str1.length();
        int n=str2.length();
        if(m!=n)
            return false;
        
            for(int i=0;i<m;i++)
            {
                char ch1=str1[i];
                char ch2=str2[i];
                
                if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2 || 
                mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1)
                    return false;
                    
                mp1[ch1]=ch2;
                mp2[ch2]=ch1;
            }
        
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends