// User function Template for C++
class Solution {
  public:
    int trailingZeroes(int n) {
        // Write Your Code here
        
        int count = 0;
        
        while(n >= 5){
            n /= 5;
            count += n;
        }
        return count;
    }
};