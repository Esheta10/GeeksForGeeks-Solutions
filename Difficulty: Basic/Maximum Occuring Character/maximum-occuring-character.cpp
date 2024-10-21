//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
         // Array to store frequency of characters, initialized to 0
    int freq[26] = {0};

    // Calculate frequency of each character in the string
    for (char ch : str) {
        freq[ch - 'a']++;
    }

    // Variables to store the result
    int max_freq = 0;
    char result;

    // Find the character with the highest frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            result = 'a' + i;  // Convert index back to character
        }
    }

    return result;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends