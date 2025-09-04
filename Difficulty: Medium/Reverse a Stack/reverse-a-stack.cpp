
class Solution {
  public:
    void reverse(stack<int> &St) {
        // code here
        
        // base case
        if(St.empty()) return;
        
        int top = St.top();
        St.pop();
        reverse(St);
        
        stack<int> temp;
        while(!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }
        St.push(top);
        while(!temp.empty())
        {
            St.push(temp.top());
            temp.pop();
        }
    }
};