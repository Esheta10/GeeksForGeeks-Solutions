//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

bool checkFreq(string s1)
{
    for(char &ch:s1)
    {
        int arr[26]={0};
        arr[ch-'a']++;
        if(arr[ch-'a']>1)
            return true;
    }
    return false;
}

bool metaStrings (string S1, string S2)
{
    // your code here
    if(S1.length()!=S2.length())
        return false;
        
    if(S1 == S2)//any charcter having more than one freq,just swap it and done
    {
        return checkFreq(S1);
    }
    vector<int> indices;
    for(int i=0;i<S1.length();i++)
    {
        if(S1[i]!=S2[i])
            indices.push_back(i);
    }
    if(indices.size()!=2)
        return false;
    int first=indices[0];
    int second=indices[1];
    
    swap(S1[first],S1[second]);
    return S1==S2;
    
}