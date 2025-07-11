//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
    int left = 0, right = arr.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the current area
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int currentArea = height * width;

        // Update the maximum area
        maxArea = max(maxArea, currentArea);

        // Move the pointer of the smaller height
        if (arr[left] < arr[right])
            left++;
        else
            right--;
    }
    return maxArea;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends