class Solution {
  public:
    string frequencySort(string &s) {
        // code here
        unordered_map<char, int> mp;// {value, freq}
        for(char c: s){
            mp[c]++;
        }
        
        vector<pair<int, char>> freqVec; // {freq, value}
        
        for(auto it: mp){
            freqVec.push_back({it.second, it.first});
        }
        sort(freqVec.begin(), freqVec.end(), [](auto a, auto b){
           if(a.first != b.first)
                return a.first < b.first;
            
            return a.second < b.second;
        });
        
        int idx = 0;
        for(auto it: freqVec){
            for(int i=0; i<it.first; i++)
                s[idx++] = it.second;
        }
        return s;
    }
};