class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string result = "";
        
        for(string str: s){
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string& s) {
        
        // code here
        vector<string> result;
        int i=0;
        
        while(i < s.length()){
            int j = i;
            while(s[j] != '#')
                j++;
                
            int length = stoi(s.substr(i, j-i)); // length nikalo
        
            string word = s.substr(j+1, length);  // string nikalo
            result.push_back(word);
            
            i = j+1+length; // next position pe jaa
        }
        return result;
    }
};