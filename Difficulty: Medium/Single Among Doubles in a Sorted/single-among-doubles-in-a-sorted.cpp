class Solution {
  public:
    int single(vector<int>& arr) {
        // code here
        int n = arr.size();
        int l=0;
        int r=n-1;
        
        while(l < r){
            int mid = l+(r-l)/2;
            
            if(mid%2 == 0){
                // mid is even
                if(arr[mid] == arr[mid+1])
                    l = mid+1; // single element is on right side
                else
                    r = mid;
            } else {
                // mid is odd
                if(arr[mid] == arr[mid-1])
                    l = mid+1; // single elemnt is on right side
                else
                    r = mid;
            }
        }
        return arr[r];
    }
};