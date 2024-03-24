/*
Approach:
    1. Initialize a stack, say temp.
    2. Keep popping from the given stack S and pushing the popped elements into temp, until the stack S becomes empty.
    3. Push N into the stack S.
    4. Now, keep popping from the stacktemp and push the popped elements into the stack S, until the stack temp becomes empty.
*/

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        // Initialize a stack,
        stack<int> temp;
        // push all element from current stack to temp stack
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        // push new element to the stack
        st.push(x);
        // push all elements from temp stack to current stack
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
        return st;
    }
};
