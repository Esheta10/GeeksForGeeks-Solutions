class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        
        int i=0, j=0;
        vector<int> result;
        
        while(i<n1 && j<n2){
            if(i>0 && a[i] == a[i-1]){
                i++;
                continue;
            }
            if(j>0 && b[j] == b[j-1]){
                j++;
                continue;
            }
            if(a[i] < b[j]){
                result.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j]){
                result.push_back(b[j]);
                j++;
            }
            else{
                result.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i<n1){
            if(i==0 || a[i] != a[i-1])
                result.push_back(a[i]);
                i++;
        }
        while(j<n2){
            if(j==0 || b[j] != b[j-1])
                result.push_back(b[j]);
                j++;
        }
        return result;
    }
};