// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos,neg;
        
        for(int num : arr){
            
            if(num >= 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }
        
        int i=0, j=0;
        int n1 = pos.size();
        int n2 = neg.size();
        vector<int> ans;
         ans.reserve(arr.size());
        
        while(i<n1 && j<n2){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        
        while(i<n1) // remaining positives
            ans.push_back(pos[i++]);
        
        while(j<n2)
            ans.push_back(neg[j++]);
            
        // Copy back to original array
        for(int k = 0; k < ans.size(); k++)
            arr[k] = ans[k];
    }
};