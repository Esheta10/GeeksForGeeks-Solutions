class Solution {
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        
        int n = arr.size();
        
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int prefixSum = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            
            prefixSum += arr[i];
            
            int alreadyPresent = prefixSum - target;
            
            if(mp.find(alreadyPresent) != mp.end())
                count += mp[alreadyPresent];
                
                
            mp[prefixSum]++;
        }
        return count;
    }
};