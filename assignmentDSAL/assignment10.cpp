#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& str) {
    stack<char> st;
    string ans = "";
    
    for (char ch : str) {
        // If the character is an operand (alphanumeric), add it to the output
        if (isalnum(ch)) {
            ans += ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '(' from the stack
        }
        // If the character is an operator
        else {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string expression;
    cout << "Enter the infix expression: ";
    cin >> expression;

    cout << "Required Postfix Expression: " << infixToPostfix(expression) << endl;

    return 0;
}