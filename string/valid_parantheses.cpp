class Solution {
public:
    bool isValid(string s) {
        stack<char> st;   // use char stack
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // if opening bracket, push
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // if closing bracket
                if (!st.empty()) {
                    char top = st.top();
                    if ((ch == ')' && top == '(') || 
                        (ch == '}' && top == '{') || 
                        (ch == ']' && top == '[')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        // if stack is empty → all brackets matched
        return st.empty();
    }
};
