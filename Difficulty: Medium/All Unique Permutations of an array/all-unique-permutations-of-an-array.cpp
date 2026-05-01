class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(map<int, int> &mp, vector<int>& temp){
        
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }
        
        for(auto &[num, count] : mp){
            
            if(count == 0)
                continue;
                
            temp.push_back(num);    // choose
            mp[num]--;
            
            backtrack(mp, temp);    // recurse
            
            temp.pop_back(); // un-choose
            mp[num]++;
            
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        n = arr.size();
        
        map<int, int> mp;
        
        for(int &num : arr){
            mp[num]++;
        }
        
        vector<int> temp;
        
        backtrack(mp, temp);
        
        return result;
    }
};