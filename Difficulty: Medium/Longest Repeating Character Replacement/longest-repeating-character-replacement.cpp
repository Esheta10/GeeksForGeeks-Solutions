class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        unordered_map<char, int> count;
        int left = 0;
        int result = 0;
        int maxFreq = 0;
        
        for(int right=0; right<s.size(); right++){
            
            count[s[right]]++;
            
            maxFreq = max(maxFreq, count[s[right]]);
            
            while((right-left+1) - maxFreq > k){
                count[s[left]]--;
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};