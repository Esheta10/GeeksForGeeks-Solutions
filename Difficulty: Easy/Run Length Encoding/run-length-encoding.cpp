//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string encode(string s) {
        // code here
        int n=s.length();
        string result = "";
        int i=0;
        int index=0;
        
        while(i<n)
        {
            char curr_char=s[i];
            int count=0;
            
            //find count of duplicates
            while(i<n && s[i]==curr_char)
            {
                i++;
                count++;
            }
            //append the curr_char to the result
            result += curr_char;
            //add the count 
              result += to_string(count);
            
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        string s;
        getline(cin,s);
        
        Solution obj;
        string res = obj.encode(s);
        
        cout<<res<<"\n";
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends