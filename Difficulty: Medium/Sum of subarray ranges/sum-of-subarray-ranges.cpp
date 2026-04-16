typedef long long ll;
class Solution {
  public:
    // Next Smaller Element to the left
    vector<int> getNSL(vector<int>& arr, int n){ 
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()] > arr[i]) // strictly less
                st.pop();
                
            ans[i] = st.empty() ? -1 : st.top();
            
            st.push(i);
        }
        return ans;
    }
    // Next Smaller Element to the right
    vector<int> getNSR(vector<int>& arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]) // non-strictly less
                st.pop();
                
            ans[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        return ans;
    }
    // Next Greater Element to the left
    vector<int> getNGL(vector<int>& arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()] < arr[i]) // strictly greater
                st.pop();
                
            ans[i] = st.empty() ? -1 : st.top();
            
            st.push(i);
        }
        return ans;
    }
    // Next Greater Element to the right
    vector<int> getNGR(vector<int>& arr, int n){
        
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] <= arr[i]) // non-strictly greater
                st.pop();
                
            ans[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        return ans;
    }
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        int M = 1e9+7;
        
        // Sum of minimums
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        ll sum_min = 0;
        for(int i=0; i<n; i++){
            
            ll d1 = i - NSL[i];
            ll d2 = NSR[i] - i;
            
            ll total_ways_min = arr[i] * d1 * d2;
            sum_min += total_ways_min;
        }
        
        // Sum of maximums
        vector<int> NGL = getNGL(arr, n);
        vector<int> NGR = getNGR(arr, n);
        ll sum_max = 0;
        for(int i=0; i<n; i++){
            
            ll d3 = i- NGL[i];
            ll d4 = NGR[i] - i;
            
            ll total_ways_max = arr[i] * d3 * d4;
            sum_max += total_ways_max;
        }
        return sum_max - sum_min;
    }
};