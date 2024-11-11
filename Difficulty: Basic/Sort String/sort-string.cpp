#include <iostream>
#include <algorithm> // Include algorithm header for the sort function
using namespace std;

int main() {
	//code
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        string S;
        cin >> S; // Input string for each test case
        
        sort(S.begin(), S.end()); // Sort the string alphabetically
        
        cout << S << endl; // Print the sorted string
    }
    return 0;
	
}
