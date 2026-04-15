class Solution {
  public:
    vector<int> asterCol(vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(int &a : asteroids){
            
            // collision happens when asteroid is -ve and stack top is +ve
            while(!st.empty() && a<0 && st.top()>0){
                
                int sum = a + st.top();
                
                if(sum < 0){
                    //stack's top was destroyed
                    st.pop();
                } else if(sum > 0){
                    // curret asteroid was destroyed
                    a = 0;
                    break;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            
            // push the +ve asteroid into the stack
            if(a != 0){
                st.push(a);
            }
        }
        
        int s = st.size();
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()){
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};