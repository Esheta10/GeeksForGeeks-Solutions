// User function Template for C++

class Solution {
  public:
    long long int distinctColoring(int N, int r[], int g[], int b[]) {
        // code here
        vector<long long> dpR(N), dpG(N), dpB(N);
        
        dpR[0] = r[0];
        dpG[0] = g[0];
        dpB[0] = b[0];
        
        for(int i=1;i<N;i++)
        {
            dpR[i] = r[i] + min(dpG[i-1],dpB[i-1]);
            dpG[i] = g[i] + min(dpR[i-1],dpB[i-1]);
            dpB[i] = b[i] + min(dpG[i-1],dpR[i-1]);
        }
        return min({dpR[N-1], dpG[N-1], dpB[N-1]});
    }
};