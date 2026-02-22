class Solution {
  public:
    int getFirstSetBit(int n) {
        // code here
        return log2(n & (-n)) + 1;
    }
};