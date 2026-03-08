class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        int i=0, j=0, k=0;
        int n = a.size();
        vector<int> result;
        
        int minDiff = INT_MAX;
        
        while(i<n && j<n && k<n){
            
            int mn = min({a[i], b[j], c[k]});
            int mx = max({a[i], b[j], c[k]});
            
            if(mx - mn < minDiff){
                minDiff = mx - mn;
                result = {a[i], b[j], c[k]};
            }
            
            // move the smallest pointer forward
            if(a[i] == mn)
                i++;
            else if(b[j] == mn)
                j++;
            else
                k++;
        }
        sort(result.begin(), result.end(), greater<int>());
        return result;
        
    }
};