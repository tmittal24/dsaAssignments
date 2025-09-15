#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == MAX);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX;
        size--;
        return val;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// Function to interleave queue
void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements. Cannot interleave.\n";
        return;
    }

    int half = n / 2;
    Queue firstHalf;

    // Move first half into another queue
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    // Interleave elements
    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue()); // from first half
        q.enqueue(q.dequeue());         // from second half
    }
}

int main() {
    Queue q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.enqueue(arr[i]);
    }

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}