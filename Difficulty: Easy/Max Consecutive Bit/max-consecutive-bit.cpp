class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        
        int max0 = 0, max1 = 0;
        int count1 = 0, count0 = 0;
        
        for(int num : arr){
            
            if(num == 1){
                count1++;
                max1 = max(max1,count1);
                count0 = 0; // reset zero streak
            } else {
               count0++;
               max0 = max(max0, count0);
               count1 =  0; // reset 1 streak
            }
        }
        
        return max(max0,max1);
    }
};