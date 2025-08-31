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

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool Brackets(string a) {
    stack st = init();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
            push(st, a[i]);
        } 
        else if (a[i] == ')' || a[i] == ']' || a[i] == '}') {
            if (isEmpty(st) || !isMatching(topElement(st), a[i])) {
                return false;  
            }
            pop(st);
        }
    }
    return isEmpty(st);  
}

int main() {
    string exp = "[(a+b)*(c+d)]";

    if (Brackets(exp))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}