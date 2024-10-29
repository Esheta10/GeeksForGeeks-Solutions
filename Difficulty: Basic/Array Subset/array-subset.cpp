//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    // Step 1: Create frequency map for elements in a1
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[a1[i]]++;
    }

    // Step 2: Check if each element in a2 has sufficient occurrences in a1
    for (int i = 0; i < m; i++) {
        if (frequencyMap[a2[i]] > 0) {
            frequencyMap[a2[i]]--;
        } else {
            // Element not found in a1 with required count
            return "No";
        }
    }
    
    return "Yes";
}