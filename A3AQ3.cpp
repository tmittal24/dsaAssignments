#include <stdio.h>

#define MAX 1000

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack *s) { s->top = -1; }
int isEmpty(struct Stack *s) { return s->top == -1; }
int isFull(struct Stack *s) { return s->top == MAX - 1; }
void push(struct Stack *s, int x) { if (!isFull(s)) s->arr[++s->top] = x; }
int pop(struct Stack *s) { return isEmpty(s) ? -1 : s->arr[s->top--]; }
int peek(struct Stack *s) { return isEmpty(s) ? -1 : s->arr[s->top]; }


void nextGreaterElement(int arr[], int n) {
    int result[n];
    struct Stack s;
    init(&s);

    
    for (int i = n - 1; i >= 0; i--) {
        
        while (!isEmpty(&s) && peek(&s) <= arr[i]) {
            pop(&s);
        }

        
        result[i] = isEmpty(&s) ? -1 : peek(&s);

        
        push(&s, arr[i]);
    }

    
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
}


int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}