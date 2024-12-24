//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>> result;
  void twoSum(vector<int> arr,int target,int i,int j)
  {
      while(i<j)
      {
          if(arr[i]+arr[j]>target)
            j--;
          else if(arr[i]+arr[j]<target)
            i++;
          else
          {
             while(i<j && arr[i]==arr[i+1]) i++;
             while(i<j && arr[j]==arr[j-1]) j--;
             
             result.push_back({-target,arr[i],arr[j]});
             i++;
             j--;
          }
      }
  }
    vector<vector<int>> triplets(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n<3)
            return {};
            
        sort(arr.begin(),arr.end());//sort
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
                continue;
            
            int n1 = arr[i];
            int target = -n1;
            
            twoSum(arr,target,i+1,n-1);
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();

        Solution obj;
        vector<vector<int>> res = obj.triplets(arr);
        if (res.size() == 0) {
            cout << endl;
        } else
            Matrix::print(res);
    }
}

// } Driver Code Ends