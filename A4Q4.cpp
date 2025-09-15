#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    char arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(char x) {
        if (isFull()) return;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char val = arr[front];
        front = (front + 1) % MAX;
        size--;
        return val;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};


void firstNonRepeating(string str) {
    Queue q;
    int freq[256] = {0};  

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

       
        if (ch == ' ') continue;

        freq[ch]++;
        q.enqueue(ch);

       
        while (!q.isEmpty() && freq[q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    string input = "aabc";  

    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input);

    return 0;
}