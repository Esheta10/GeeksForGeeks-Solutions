class Solution {
  public:
    int t[1001][1001];
    bool solve(string&s, int i,int j){
        
        if(i>=j)
            return t[i][j] = true;

        if(t[i][j] != -1)
            return t[i][j];
            
        if(s[i] == s[j])
            return t[i][j] = solve(s, i+1, j-1);
            
        return t[i][j] = false;
    }
    string getLongestPal(string &s) {
        // code here
        int n = s.length();
        int startingPoint = 0;
        int maxLen = INT_MIN;
        
        memset(t, -1, sizeof(t));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        startingPoint = i;
                    }
                }
            }
        }
        return s.substr(startingPoint, maxLen);
    }
};