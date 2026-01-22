class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int j=1;
        
        for(int i=1;i<n;i++){
            if(arr[i] != arr[i-1]){
                 arr[j] = arr[i];
                 j++;
            }
        }
        
        return vector(arr.begin(), arr.begin()+j);
    }
};