class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
        // code here
        unordered_set<int> st;
        
        for(int num: arr){
            
            if(st.find(num) != st.end())
                return true;
            
            st.insert(num);
        }
        return false;
    }
};
