//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    // Create a stack to hold the characters
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;  // Initialize top of stack
    
    // Push all characters of the string into the stack
    for (int i = 0; i < len; i++) {
        stack[++top] = S[i];
    }
    
    // Pop characters from the stack and put them back into the string in reverse order
    for (int i = 0; i < len; i++) {
        S[i] = stack[top--];
    }
    
    // Free the allocated memory for stack
    free(stack);
    
    return S;  // Return the reversed string
}