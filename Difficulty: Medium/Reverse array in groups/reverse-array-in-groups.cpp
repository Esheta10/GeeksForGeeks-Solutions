class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        for(int i=0;i<n;i+=k)
        {
            int left = i;// starting index of current group
            int right = min(i+k-1,n-1);// ending index (handle last group safely)

            
        // reverse current group            
            while(left <= right){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
        }
    }
};
