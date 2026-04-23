class Solution {
  public:
    vector<int> getPSE(vector<int>& arr){
        
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            ans[i] = st.empty() ? -1 : st.top();
            
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSE(vector<int>& arr){
        
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            ans[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        return ans;
    }
    int getMaxArea(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        vector<int> pse = getPSE(arr);
        vector<int> nse = getNSE(arr);
        
        int largestArea = 0;
        int area;
        
        for(int i=0; i<n; i++){
            
            area = arr[i] * (nse[i] - pse[i] - 1);
            largestArea = max(area, largestArea);
        }
        return largestArea;
    }
};
