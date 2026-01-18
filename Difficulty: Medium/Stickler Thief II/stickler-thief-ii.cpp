class Solution {
  public:
    int t[100001];
    int solve(vector<int>& arr, int i, int n){
        
        if(i>n)
            return 0;
            
        if(t[i] != -1)
            return t[i];
            
        int steal = arr[i] + solve(arr,i+2,n);
        int skip = solve(arr,i+1,n);
        
        return t[i] = max(steal,skip);
        
    }
    int maxValue(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n==1)
            return arr[0];
            
        if(n==2)
            return max(arr[0],arr[1]);
        
        memset(t,-1,sizeof(t));
        
        int take_0th_index_house = solve(arr,0,n-2);
        
        memset(t,-1,sizeof(t));
        
        int take_1st_index_house = solve(arr,1, n-1);
        
        return max(take_0th_index_house, take_1st_index_house);
        
    }
};
