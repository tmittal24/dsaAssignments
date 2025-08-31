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

void ReverseString(string s) {
    stack st = init();

    for (int i = 0; i < s.length(); i++) {
        push(st, s[i]);
    }

    for (int k = 0; k < s.length(); k++) {
        cout << topElement(st);
        pop(st);
    }
    cout << endl;
}

int main() {
    string sh = "hello";
    ReverseString(sh);
    return 0;
}