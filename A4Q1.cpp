#include <iostream>
using namespace std;

struct queue{
    int arr[100];
    int front;
    int rear;


};

queue init(){
    queue a;
    a.front = -1;
    a.rear = -1;
    return a;
}

bool isEmpty(queue &a){
    if (a.front==-1||a.front>a.rear){
        return true;
    }
    else {
        return false;
    }
}

bool isFull(queue &a){
    if (a.rear==99){
        return true;
    }
    else {
        return false;
    }
}

int front(queue &a){
    return a.arr[a.front];
}

queue enqueue(queue &a,int item){
    if (isFull(a)){
        cout<<"overflow"<<endl;

    }
    else if(isEmpty(a)){
        a.front = a.rear = 0;
        a.arr[a.front]=item;
    }
    else{
        a.rear++;
        a.arr[a.rear]=item;
    }
    return a;
}

queue dequeue(queue &a){
    if (isEmpty(a)){
        cout << "underflow"<<endl;

    }
    else{
        a.front ++;
        
    }
    return a;
}

void print(queue a){
    for (int i = a.front;i<=a.rear;i++){
        cout<<a.arr[i]<<endl;
    }

}

int main(){
    queue a = init();
    enqueue(a,20);
    enqueue(a,30);
    enqueue(a,40);
    enqueue(a,50);
    print(a);
    dequeue(a);
    print(a);

}

