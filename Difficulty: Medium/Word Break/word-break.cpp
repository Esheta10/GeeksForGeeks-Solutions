class Solution {
public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        // Find max word length for optimization
        int maxLen = 0;
        for(const string &word : dictionary) {
            maxLen = max(maxLen, (int)word.length());
        }
        
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        
        for(int i = n - 1; i >= 0; i--) {
            // Only check up to maxLen characters
            for(int len = 1; len <= min(maxLen, n - i); len++) {
                if(st.count(s.substr(i, len)) && dp[i + len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};