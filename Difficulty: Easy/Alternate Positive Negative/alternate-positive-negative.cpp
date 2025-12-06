// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> pos;
        vector<int> neg;
       
        
        for(int num:arr){
            if(num<0){
                neg.push_back(num);
            } else {
                pos.push_back(num);
            }
        }
        int i=0;
        int j=0;
        int k=0;
        
        while(i<pos.size() && j<neg.size()){
            
            arr[k++] = pos[i++];    // even index pe +ve
            arr[k++] = neg[j++];    // odd index pe -ve
            
        }
        
        while(i<pos.size()){
            arr[k++] = pos[i++];
        }
        
        while(j<neg.size()){
            arr[k++] = neg[j++];
        }
    }
};