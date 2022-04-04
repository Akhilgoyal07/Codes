string infixToPostfix(string s)
    {
        stack <char> st;
        s = "(" + s + ")";
        
        string ans = ""; 
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' ) {
                st.push(s[i]);
            }
            else if(s[i] == ')' ) {
                while(st.top() != '(') {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i] == '^') {
                while (st.top() == '^') {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/') {
                while(st.top() == '^' || st.top() == '*' || st.top() == '/') {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                while( st.top() != '(' ) {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else {
                ans = ans + s[i];
            }
        }
        
        return ans;
    }
