class Solution {
public:
    bool isPredecessor(const string& prev, const string& curr) {
        if (curr.length() - prev.length() != 1) return false;
        
        int i = 0, j = 0;
        int diff = 0;
        
        while (i < prev.length() && j < curr.length()) {
            if (prev[i] == curr[j]) {
                i++;
                j++;
            } else {
                diff++;
                j++;
                if (diff > 1) return false;
            }
        }
        
        return true;
    }
    
    int longestStringChain(vector<string>& words) {
        // Sort by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        // Map: word -> longest chain ending at this word
        unordered_map<string, int> dp;
        int maxChain = 1;
        
        for (const string& word : words) {
            int currentMax = 1;
            
            // Try removing each character to find predecessors
            for (int i = 0; i < word.length(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.find(prev) != dp.end()) {
                    currentMax = max(currentMax, dp[prev] + 1);
                }
            }
            
            dp[word] = currentMax;
            maxChain = max(maxChain, currentMax);
        }
        
        return maxChain;
    }
};