//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i,int n)
    {
        // code here such that selectionSort() sorts arr[]
        int temp=arr[i];
        int min=i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        return min;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
           for(int i=0;i<=n-2;i++)
           {
              int min=select(arr,i,n);
              
           int temp=arr[min];
           arr[min]=arr[i];
           arr[i]=temp;
           }
       
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends