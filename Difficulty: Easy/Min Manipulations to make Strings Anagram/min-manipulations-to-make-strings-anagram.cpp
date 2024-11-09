//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
int minManipulation (int N, string S1, string S2)
{
    // your code here
    int count_s[26]={0};
    int count_t[26]={0};
    
    for(int i=0;i<N;i++)
    {
        count_s[S1[i]-'a']++;
        count_t[S2[i]-'a']++;
    }
    int result=0;
    for(int i=0;i<26;i++)
    {
        int freq_s=count_s[i];
        int freq_t=count_t[i];
        
        if(freq_s > freq_t)
            result += freq_s - freq_t;
    }
    return result;
}