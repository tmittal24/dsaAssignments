#include <iostream>
using namespace std;

struct stack {
    int arr[100];
    int top;
    int size;

    stack() {
        top = -1;
        size = sizeof(arr) / sizeof(arr[0]);
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    int topElement() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --top;
        }
    }
};

int main() {
    int arr[5] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prevSmaller[5];

    stack s;

    for (int i = 0; i < n; i++) {
        while (!s.isEmpty() && s.topElement() >= arr[i]) {
            s.pop();
        }
        if (s.isEmpty()) {
            prevSmaller[i] = -1;
        } else {
            prevSmaller[i] = s.topElement();
        }
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << prevSmaller[i] << endl;
    }

    return 0;
}
