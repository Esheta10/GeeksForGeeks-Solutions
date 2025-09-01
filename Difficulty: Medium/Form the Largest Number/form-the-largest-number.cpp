class Solution {
  public:
  static bool compare(string s1,string s2)
  {
      return s1+s2 > s2+s1;
  }
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> strNums;
        
        for(int num:arr)
        {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(),strNums.end(),compare);
        
        if(strNums[0]=="0")
            return "0";
            
            
        string result="";
        for(string s : strNums)
            result += s;
            
        return result;
        
    }
};