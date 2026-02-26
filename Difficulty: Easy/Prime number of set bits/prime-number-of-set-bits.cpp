// User function Template for C++
class Solution {
  public:
    int primeSetBits(int L, int R) {
        // code here
        unordered_set<int> primes = {2,3,5,7,11,13,17,19};
        
        int count = 0;
        
        for(int i=L; i<=R; i++){
            
            int set_bits = __builtin_popcount(i);
            
            if(primes.find(set_bits) != primes.end())
                count++;
        }
        return count;
    }
};