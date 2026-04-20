class Solution {
  public:
    int precedence(char op){
        if(op == '^')
            return 3;
        else if(op == '*' || op == '/')
            return 2;
        else if(op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    bool isOperator(char c){
        return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string result = "";

        for(char token : s){

            if(isalnum(token))
                result += token;

            else if(token == '(')
                st.push(token);

            else if(token == ')'){
                while(!st.empty() && st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop(); // discard '('
            }

            else if(isOperator(token)){
                while(!st.empty() && st.top() != '(' &&
                      (precedence(st.top()) > precedence(token) ||
                      (precedence(st.top()) == precedence(token) && token != '^'))){
                    result += st.top();
                    st.pop();
                }
                st.push(token);
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};