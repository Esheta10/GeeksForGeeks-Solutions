//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
    // complete the function here
    int low = 0, high = arr.size()- 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if the key is at mid
        if (arr[mid] == key) {
            return mid;
        }
        
        // If the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= key && key < arr[mid]) {
                high = mid - 1;  // key is in the left half
            } else {
                low = mid + 1;   // key is in the right half
            }
        }
        // If the right half is sorted
        else {
            if (arr[mid] < key && key <= arr[high]) {
                low = mid + 1;    // key is in the right half
            } else {
                high = mid - 1;   // key is in the left half
            }
        }
    }
    
    return -1;  // key not found
       }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends