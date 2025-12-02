class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // int temp=0, result=0;
        
        // for(int i=0;i<n;i++){
            
        //     temp=0;
        //     for(int j=i;j<n;j++){
                
        //         temp += arr[j];
        //         result += temp;
        //     }
        // }
        
        // Computing sum of subarray using formula
        
        int result=0;
        for(int i=0;i<n;i++){
            int startChoices = i + 1;     // number of ways arr[i] can be the starting element
            int endChoices = n - i;       // number of ways arr[i] can be the ending element
            result += arr[i] * startChoices * endChoices;
        }
        
        return result;
    }
};