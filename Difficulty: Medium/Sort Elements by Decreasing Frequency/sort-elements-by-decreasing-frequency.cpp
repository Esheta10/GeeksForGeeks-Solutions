//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    typedef pair<int,int> P;
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
         // Step 1: Count frequencies of each number in the input array
        unordered_map<int,int> freq_map;
        for(int &num:arr)
        {
            freq_map[num]++;
        }
        vector<P> freq_vec;
         // Step 2: Move the elements and their frequencies into a vector of pairs
        for(const auto &entry: freq_map)
        {
            freq_vec.push_back({entry.first,entry.second});
        }
        auto lambda = [](const P &p1,const P &p2)
        {
            if (p1.second == p2.second) 
                return p1.first < p2.first;
            return p1.second > p2.second;
        };
        sort(freq_vec.begin(),freq_vec.end(),lambda);
        
        vector<int>result;
        
        for(const auto &p:freq_vec)
        {
            result.insert(result.end(),p.second,p.first);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends