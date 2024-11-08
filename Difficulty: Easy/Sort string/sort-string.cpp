//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{	public:
        bool isVowel(char ch)
        {
            ch=tolower(ch);
            return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
        }
		string SortedString(string s)
		{
		  // Code here
		  vector<char> vowels,consonants;
		  
		  for(char ch:s)
		  {
		      if(isVowel(ch))
		        vowels.push_back(ch);
		       else
		        consonants.push_back(ch);
		  }
		  sort(vowels.begin(),vowels.end());
		  sort(consonants.begin(),consonants.end());
		  
		  bool firstIsVowel=isVowel(s[0]);
		  int i=0,j=0;
		  string result;
		  while(i<vowels.size() || j<consonants.size())
		  {
		      if(firstIsVowel)
		      {
		          if(i<vowels.size())
		            result.push_back(vowels[i++]);
		           if(j<consonants.size())
		            result.push_back(consonants[j++]);
		      }
		      else
		      {
		          if(j<consonants.size())
		            result.push_back(consonants[j++]);
		           if(i<vowels.size())
		            result.push_back(vowels[i++]);
		      }
		  }
		  return result;
		  
		}

};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    string ans=ob.SortedString(s);
	    cout<<ans<<"\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends