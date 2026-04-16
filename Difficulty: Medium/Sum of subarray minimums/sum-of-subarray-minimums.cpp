typedef unsigned long long ll;
class Solution {
  public:
    vector<int> getNSL(vector<int>& arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            if(st.empty()){
                ans[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                    
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>& arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            if(st.empty()){
                ans[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                    
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); // next smaller to the left
        vector<int> NSR = getNSR(arr, n); // next smaller to the right
        
        ll sum = 0;
        int M = 1e9+7;
        
        for(int i=0; i<n; i++){
            
            ll d1 = i - NSL[i];
            ll d2 = NSR[i] - i;
            
            ll total_ways = d1 * d2;
            ll sum_in_total_ways = arr[i] * total_ways;
            
            sum = (sum  + sum_in_total_ways) % M;
        }
        return sum;
    }
};