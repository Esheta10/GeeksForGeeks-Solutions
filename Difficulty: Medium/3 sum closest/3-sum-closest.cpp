//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        if (N < 3) return 0;  // Not enough elements for a triplet
        int closestSum=10000000;
        sort(A,A+N);
        for(int k=0;k<=N-3;k++)
        {
            int i=k+1;
            int j=N-1;
            while(i<j)
            {
                int sum=A[i]+A[j]+A[k];
                if(abs(X-sum)<abs(X-closestSum))
                   closestSum=sum;
                   
                if(sum<X)
                    i++;
                else
                    j--;
            }
        }
        return closestSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends