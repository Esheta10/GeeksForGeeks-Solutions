//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(char &ch:x)
        {
            // If the character is an opening bracket, push it onto the stack
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else
            {
                // If the stack is empty, there's no matching opening bracket
                if(st.empty())
                    return false;
                
                char top=st.top();
                
                if(ch==')' && st.top()!='('
                || ch=='}' && st.top()!='{'
                || ch==']' && st.top()!='[')
                    return false;
                
                 st.pop();    
            }
                
        }
        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends