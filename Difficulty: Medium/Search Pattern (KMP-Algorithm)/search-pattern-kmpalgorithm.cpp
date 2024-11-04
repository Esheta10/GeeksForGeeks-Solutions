//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void computeLPS(string &pat, vector<int> &LPS,int M)
    {
        int len=0;//length of previous longest prefix and suffix which were equal
        LPS[0]=0;
        int i=1;
        while(i<M)
        {
            if(pat[i]==pat[len])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len != 0)
                {
                    len=LPS[len-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
        
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int N = txt.length();
        int M = pat.length();
        
        vector<int> result;
// Create an LPS array to store the longest proper prefix
//which is also a suffix
//lps[i] = the longest proper prefix of pat[0..i]
//which is also a suffix of pat[0..i]. 
        vector<int> LPS(M,0);
        computeLPS(pat,LPS,M);
        
        //apply KMP code
        int i=0;
        int j=0;
       while(i<N)
       {
            if(txt[i]==pat[j])
            {
            i++;
            j++;
            }
            if(j==M)
            {
                    result.push_back(i-M);
                    j=LPS[j-1];
            }
            else if(txt[i]!=pat[j])
            {
                if(j!=0)
                    j = LPS[j-1];
                else
                    i++;
            }
         }
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends