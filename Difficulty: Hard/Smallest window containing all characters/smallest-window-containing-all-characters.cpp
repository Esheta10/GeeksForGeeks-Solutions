class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        int n = s.length();
        
        map<char, int> mp;
        
        for(char &ch : p){
            mp[ch]++;
        }
        
        int i=0, j=0;
        int minStart = 0, minWindow = INT_MAX;
        int requiredCount = p.length();
        
         while(j<n){
            
            char ch_j = s[j];
            
          // j se char liye , agar p mein dikhi toh uski count ghatao
          if(mp[ch_j] > 0)
            requiredCount--;
            
         mp[ch_j]--; // frequency bhi ghatao
        
         // sabhi characters mil gaye, window valid toh ab shrink karo
         while(requiredCount == 0){
            if(minWindow > j-i+1){
                minWindow = j-i+1;
                minStart = i;
            }
            
            char ch_i = s[i];
            mp[ch_i]++;
            if(mp[ch_i] > 0)
                requiredCount++;
            i++;
            
         }
         j++; 
     }
     return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};