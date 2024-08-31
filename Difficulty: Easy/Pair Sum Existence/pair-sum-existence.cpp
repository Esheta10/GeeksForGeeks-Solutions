//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int n, int sum);
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];  //array of size n
            
        for(int i = 0; i < n; i++)
            cin>>arr[i]; //Input the array
             
        int sum; 
        cin>>sum;
          
        cout<< sumExists(arr, n, sum) <<endl;    
            
	}
}
// } Driver Code Ends


//User function Template for C++

int sumExists(int arr[], int n, int sum){
    //code here
    int left=0,right=n-1;
    sort(arr,arr+n);
    while(left<right)
    {
        int add=arr[left]+arr[right];
        if(add==sum)
            return 1;
        else if(add<sum)
            left++;
        else
            right--;
    }
    return 0;
}