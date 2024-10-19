//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       // Handle signs
    bool negative = false;
    if (s1[0] == '-') {
        negative = !negative;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        negative = !negative;
        s2 = s2.substr(1);
    }
    
    // Remove leading zeros
    s1.erase(0, s1.find_first_not_of('0'));
    s2.erase(0, s2.find_first_not_of('0'));
    
    // Edge case: if any string becomes empty (i.e., was zero), return "0"
    if (s1.empty() || s2.empty()) {
        return "0";
    }
    
    int n1 = s1.size(), n2 = s2.size();
    vector<int> result(n1 + n2, 0); // Result array to store intermediate values
    
    // Reverse both strings to make the multiplication easier (from right to left)
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    // Multiply each digit of s1 with each digit of s2
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            result[i + j] += (s1[i] - '0') * (s2[j] - '0');  // Multiply digits
            result[i + j + 1] += result[i + j] / 10;         // Carry to next position
            result[i + j] %= 10;                             // Remainder stays in the current position
        }
    }

    // Remove leading zeros in the result array
    int size = result.size();
    while (size > 1 && result[size - 1] == 0) {
        size--;
    }

    // Convert the result array back to a string
    string product;
    for (int i = size - 1; i >= 0; --i) {
        product += (result[i] + '0');
    }

    // Add negative sign if needed
    if (negative) {
        product = "-" + product;
    }

    return product;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends