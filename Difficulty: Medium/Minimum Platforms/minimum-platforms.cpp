class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int result=1,plat_needed=1;
        int i=1,j=0;
        
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j])
            {
                plat_needed++;
                i++;
            }
            else
            {
                plat_needed--;
                j++;
            }
            result = max(result,plat_needed);
        }
        return result;
    }
};
