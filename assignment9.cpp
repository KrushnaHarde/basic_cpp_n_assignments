#include <iostream>
#include <stack>
using namespace std;

// Function to check if the given expression has valid parentheses
bool validParenthesis(const string& str) {
    stack<char> st;

    // Iterate through each character in the string
    for (char ch : str) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == ']' || ch == '}') {
            // If the stack is empty, it means there is no matching opening bracket
            if (st.empty()) {
                return false;
            }

            // Check if the top of the stack matches the closing bracket
            char top = st.top();
            if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
                st.pop(); // Valid match found, pop the stack
            } else {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter string to check if valid or not: ";
    cin >> expression;

    if (validParenthesis(expression)) {
        cout << "Given string has valid parentheses." << endl;
    } else {
        cout << "Given string does NOT have valid parentheses." << endl;
    }

    return 0;
}