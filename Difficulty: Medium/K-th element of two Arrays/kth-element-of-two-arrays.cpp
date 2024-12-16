//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i = 0, j = 0;
    int count = 0;
    int result = 0;

    // Traverse through both arrays
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result = a[i];
            i++;
        } else {
            result = b[j];
            j++;
        }
        count++;

        if (count == k) {
            return result;
        }
    }

    // If we have exhausted one array, continue with the other array
    while (i < a.size()) {
        result = a[i];
        i++;
        count++;
        if (count == k) {
            return result;
        }
    }

    while (j < b.size()) {
        result = b[j];
        j++;
        count++;
        if (count == k) {
            return result;
        }
    }

    return -1; // Should never reach here if k is valid

    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends