#include<stdio.h>

// ---- Cài đặt queue bằng mảng tịnh tiến ----

#define MaxLength 100
                 //chiều dài tối đa của mảng
typedef int ElementType;
                //Kiểu dữ liệu của các phần tử trong hàng
typedef struct {
    ElementType Elements[MaxLength];
                //Lưu trữ nội dung các phần tử
    int Front, Rear;
                //chỉ số đầu và cuối hàng
} Queue;
/* Khởi tạo hàng rỗng */

void makenullQueue(Queue *q){
    q->Front = -1;
    q->Rear = -1;
}

/* kiểm tra Queue rỗng */

int emptyQueue(Queue q){
    if(q.Front == -1){
        return 1;
    }
    return 0;
}

/* Kiểm tra Queue đầy */

int fullQueue(Queue q){
    if(q.Rear - q.Front + 1 == MaxLength){
        return 1;
    }
    return 0;
}

ElementType front(Queue q){
    if(emptyQueue(q)){
        printf("empty Queue");
        return;
    } else {
        return q.Elements[q.Front];
    }
}

/* Xóa phần tử đầu Queue khỏi queue */

void deQueue(Queue *q){
    if(emptyQueue(*q)){
        printf("empty queue");
        return;
    } else {
        q->Front++;
    }
    if(q->Front > q->Rear){
        makenullQueue(q);
    }
}


/* thêm một phần tử vào queue */

void enQueue(ElementType X,Queue *pQ){
    if (!fullQueue(*pQ)){  
        if (emptyQueue(*pQ)) pQ->Front=0;
        if (pQ->Rear==MaxLength-1){
//Di chuyen tinh tien ra truoc Front (-1) vi tri
            for(int i=pQ->Front;i<=pQ->Rear;i++)
                pQ->Elements[i-pQ->Front]=pQ->Elements[i];
//Xac dinh vi tri Rear moi
            pQ->Rear=MaxLength - pQ->Front-1;
            pQ->Front=0;
        }
//Tang Rear de luu noi dung moi
        pQ->Rear=pQ->Rear+1;
        pQ->Elements[pQ->Rear]=X;
    } else {
        printf("Loi: Hang day!");
    }
}

/*  Dùng mảng vòng để cài đặt  */

void deQueue2(Queue *q){
    if(emptyQueue(*q)){
        return;
    } else {
        if(q->Front == q->Rear){
            makenullQueue(q);
        } else {
            q->Front = (q->Front + 1) % MaxLength;
        }
    }
}

void enQueue2(int x, Queue *q){
    if(fullQueue(*q)){
        printf("Hang day");
        return;
    } else {
        if(emptyQueue(*q)){
            q->Front = 0;
        } else {
            q->Rear = (q->Rear + 1) % MaxLength;
            q->Elements[q->Rear] = x;
        }
    }
}