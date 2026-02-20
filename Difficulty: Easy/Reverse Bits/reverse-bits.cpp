// User function Template for C++

class Solution {
  public:
   unsigned int reverseBits(unsigned int n) {
    if(n == 0) return 0;
    
    unsigned int result = 0;
    
    // pehle count karo kitne bits hain n mein
    unsigned int temp = n;
    int bits = 0;
    while(temp > 0) {
        bits++;
        temp >>= 1;
    }
    
    // sirf utne hi baar loop chalao
    for(int i = 0; i < bits; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    
    return result;
}
};