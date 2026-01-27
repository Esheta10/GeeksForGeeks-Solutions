class Solution {
  public:
    int findFirst(vector<int>& arr, int x, int n){
        
        int leftMost = -1;
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(arr[mid]==x){
                leftMost = mid;
                right = mid - 1; // search more on left
            } else if(arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1 ;
        }
        return leftMost;
    }
    int findLast(vector<int>& arr, int x, int n){
        int rightMost = -1;
        int left = 0;
        int right = n-1;
        while(left <= right){
            
            int mid = left + (right - left)/2;
            
            if(arr[mid]==x){
                rightMost = mid;
                left = mid +1; // search more on right half
            } else if(arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return rightMost;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        
        int first = findFirst(arr, x, n);
        int last = findLast(arr, x, n);
        
        return {first, last};
    }
};