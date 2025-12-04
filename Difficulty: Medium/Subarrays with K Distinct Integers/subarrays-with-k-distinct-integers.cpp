class Solution {
  public:
    int slidingWindow(vector<int>& arr, int k){
        
        unordered_map<int,int> mp;
        int n = arr.size();
        
        int i=0;
        int j=0;
        
        int count=0;
        
        while(j<n){
            
            mp[arr[j]]++;
            
                while(mp.size() > k){
                    
                    mp[arr[i]]--;
                    
                    if(mp[arr[i]] == 0)
                    {
                        mp.erase(arr[i]);
                    }
                    i++;
                }
            
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return slidingWindow(arr, k) - slidingWindow(arr, k-1);
    }
};