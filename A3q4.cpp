#include <iostream>
using namespace std;

struct stack {
    char arr[100];   
    int top;
    int size = sizeof(arr) / sizeof(char);
};

stack init() {
    stack s;
    s.top = -1;
    return s;
}

bool isFull(stack &s) {
    return s.top == s.size - 1;
}

bool isEmpty(stack &s) {
    return s.top == -1;
}

char topElement(stack &s) {
    if (isEmpty(s)) return '\0';
    return s.arr[s.top];
}

void push(stack &s, char x) {
    if (!isFull(s)) {
        ++s.top;
        s.arr[s.top] = x;
    }
}

void pop(stack &s) {
    if (!isEmpty(s)) {
        --s.top;
    }
}


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}


string infixToPostfix(string exp) {
    stack st = init();
    string ans = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            ans += c;
        }
        
        else if (c == '(') {
            push(st, c);
        }
        
        else if (c == ')') {
            while (!isEmpty(st) && topElement(st) != '(') {
                ans += topElement(st);
                pop(st);
            }
            if (!isEmpty(st) && topElement(st) == '(')
                pop(st);
        }
        
        else {
            while (!isEmpty(st) && precedence(topElement(st)) >= precedence(c)) {
                ans += topElement(st);
                pop(st);
            }
            push(st, c);
        }
    }

    
    while (!isEmpty(st)) {
        ans += topElement(st);
        pop(st);
    }

    return ans;
}

int main() {
    string exp = "a+b*(c^d-e)";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
    return 0;
}