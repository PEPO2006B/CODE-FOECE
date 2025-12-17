#include <iostream>
#include <string>
using namespace std;


class Stack {
public:
    int arr[200];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 199;
    }

    void push(int x) {
        if (isFull()) {
            cout << "[Warning] Stack full, can't push." << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "[Warning] Stack empty, can't pop." << endl;
            return -999;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -999;
        return arr[top];
    }
};

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string inf) {
    Stack st; // للعمليات
    string post = "";

    for (int i = 0; i < inf.size(); i++) {
        char c = inf[i];
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            post += c;
            post += ' ';
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                post += (char)st.pop();
                post += ' ';
            }
            st.pop();
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c) && st.peek() != '(') {
                post += (char)st.pop();
                post += ' ';
            }
            st.push(c);
        } else {
            cout << "Invalid character: " << c << endl;
        }
    }

    while (!st.isEmpty()) {
        post += (char)st.pop();
        post += ' ';
    }

    return post;
}

int evaluatePostfix(string p) {
    Stack st;

    for (int i = 0; i < p.size(); i++) {
        char c = p[i];
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();

            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') {
                if (b == 0) {
                    cout << "Division by zero!" << endl;
                    return -1;
                }
                res = a / b;
            }

            st.push(res);
        }
    }

    return st.pop();
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    getline(cin, exp);

    string post = infixToPostfix(exp);
    cout << "Postfix: " << post << endl;

    int r = evaluatePostfix(post);
    cout << "Result: " << r << endl;

    return 0;
}
