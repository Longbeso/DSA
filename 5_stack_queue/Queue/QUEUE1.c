#include<stdio.h>

#define MAX 100

typedef struct{
    int queue[MAX];
    int rear;
    int front;
} Queue;

/* Khởi tạo */
void initQueue(Queue *q){
    q->rear = -1;
    q->front = 0;
}

/* empty */

int isEmpy(Queue q){
    if(q.rear < q.front){
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue *q){
    if(q->rear == MAX - 1){
        return 1;
    } else {
        return 0;
    }
}
/* thêm phần tử mới vào queue: thêm từ dưới lên đầu queue; thêm trước thì ở trước*/
void enqueue(Queue *q, int data){
    if(q->rear == MAX - 1){
        printf("Full");
        return;
    } else {
        q->rear++;
        q->queue[q->rear] = data;
    }
}

/* xóa phần tử ở đầu queue: phần tử thêm vào đầu tiên */
void dequeue(Queue *q){
    if(q->front > q->rear){
        printf("Queue empty");
    } else {
        q->front++;
    }
}

void print(Queue q){
    for(int i = q.front; i <= q.rear; i++){
        printf("%d ", q.queue[i]);
    }
}
int main(){
    Queue qu;
    initQueue(&qu);
    if(isEmpy(qu)){
        printf("Empty\n");
    }
    for(int i = 5; i < 19; i++){
        enqueue(&qu, i);
    }
    print(qu);
    if(isFull(&qu)){
        printf("Full");
    } else {
        printf("Not Full");
    }
    return 0;
}