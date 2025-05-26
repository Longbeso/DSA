#include<stdio.h>

/*
     Queue[3] = { 10 , 20 , 30 };
     thì lúc này front nó ở vị trí của thằng 10;
     còn rear thì ở vị trí của thằng 30;
*/


/* first in first out */

// push: thằng vào sau thì vòa cuối hàng đợi
// pop: lấy ra ở đầu hàng đợi 
// O(1)
// font: lấy phần tử đầu hàng đợii
#define SIZE 10
int queue[SIZE];
int front = 0, rear = -1;
// front là chỉ số phần tử  ở đầu queue
// rear là chỉ số phần tử ở cuối queue
// Nếu front > rear thì queue rỗng
// nếu front == rear thì queue có một phần tử

void enqueue(int data){
    if(rear == SIZE - 1){   // test arr full
        printf("Full");
        return;
    } else {
        rear++;
        queue[rear] = data; // them 1 phan tu vao queue
       
    }
}


void dequeue(){
    if(front > rear){
        printf("Queue empty");
        return;
    } else {
        front++;
    }
}

void print(){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
}
int main(){
    for(int i = 0; i < SIZE; i++){
        enqueue(i);
    }
    print();
    return 0;
}