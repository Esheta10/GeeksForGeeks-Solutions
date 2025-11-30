class Solution {
  public:
    int mergeSort(vector<int> &arr, int left, int right){
        
        if(left >= right)
            return 0;
            
        int count = 0;
        int mid = left + (right - left)/2;
        
        count += mergeSort(arr,left,mid);
        count += mergeSort(arr,mid+1,right);
        
        int j = mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && (long long)arr[i] > 2LL * arr[j]){
                j++;
            }
            count += j - (mid+1);
        }
        
        vector<int> temp;
        int i = left;
        j = mid+1;
        while(i<=mid && j<=right){
            
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }else {
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=mid)
            temp.push_back(arr[i++]);
        while(j<=right)
            temp.push_back(arr[j++]);
            
        for(int k = 0;k<temp.size();k++){
            arr[left + k] = temp[k];
        }
        return count;
        
    }
    int countRevPairs(vector<int> &arr) {
        // Code here
        return mergeSort(arr,0,arr.size()-1);
    }
};