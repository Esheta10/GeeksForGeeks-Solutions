class Solution {
  public:
    vector<vector<int>> result;
    
    void twoSum(vector<int> arr, int newTarget, int i, int j, int first, int second){
        
        while(i<j){
            if(arr[i] + arr[j] < newTarget) 
                i++;
            else if(arr[i] + arr[j] > newTarget)
                j--;
            else{
                while(i<j && arr[i]==arr[i+1]) i++;
                while(i<j && arr[j]==arr[j-1]) j--;
                
                result.push_back({first, second,arr[i],arr[j]});
                i++;
                j--;
                
            }
        }
    }
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        if(n<4)
            return {};
            
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1])
                continue;
            
            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j]==arr[j-1])
                    continue;
                    
                long long first = arr[i];
                long long second = arr[j];
                long long newTarget = target - first - second;
                
                twoSum(arr,newTarget,j+1,n-1,first,second);
            }
        }
        return result;
    }
};