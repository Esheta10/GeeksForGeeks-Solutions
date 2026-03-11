class Solution {
  public:
    int getLeftMost(vector<int> &arr, int &x, int &n){
        
        int left = 0;
        int right = n-1;
        int leftMost = -1;
        while(left <= right){
            
            int mid = left + (right - left)/2;
            
            if(arr[mid] == x){
                leftMost = mid; //potential answer
                right = mid-1; // search further left
            }
            else if(arr[mid] < x)
                left = mid+1;
            else
                right = mid-1;
        }
        return leftMost;
    }
    int getRightMost(vector<int>& arr, int &x, int &n){
        
        int left = 0;
        int right = n-1;
        int rightMost = -1;
        
        while(left <= right){
            
            int mid = left+(right-left)/2;
            if(arr[mid] == x){
                rightMost = mid; // potential answer
                left = mid+1; // search further right
            } else if(arr[mid] < x)
                left = mid+1;
            else
                right = mid-1;
        }
        return rightMost;
    }
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Code here
        int n = arr.size();
        
        int left_most = getLeftMost(arr, x, n);
        int right_most = getRightMost(arr, x, n);
        
        if (left_most == -1)
            return {-1};
        
        return {left_most, right_most};
    }
};