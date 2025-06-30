#include<stdio.h>
#include<stdlib.h>

/*   Linked List   */
typedef struct Node{
    int data;
    struct Node *Next;
} Node;
typedef Node* Position; //Kiểu vị trí
typedef Position List;

// tạo list rỗng
void makenullList(List *pl){
    (*pl) = (Node*)malloc(sizeof(Node));
    (*pl)->Next = NULL;
}

// kiểm tra List rổng
int emptyList(List L){
    return (L->Next == NULL);
}

// trả về phần tử tại vị trí p
int retrieve(Position p, List L){
    if(p->Next != NULL){
        return p->Next->data;
    }
}

// xen một phần tử vào danh sách
void insertList(int x, Position p, List *l){
    List temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->Next = p->Next;
    p->Next = temp;
}

// xóa một phần tử khỏi danh sách
void deleteList(Position p, List *l){
    if(p->Next != NULL){
        List temp = p->Next;
        p->Next = temp->Next;
        free(temp);
    }
}

// Xác định vị trí phần tử
Position first(List L){ // phần tử đầu
    return L;
}

Position endList(List L){ // vị trí sau phần tử cuối cùng
    Position t = L;
    while(t->Next != NULL){
        t = t->Next;
    }
    return t;
}

Position locate(int x, List L){
    List p = L;
    while (p->Next != NULL){
        if(retrieve(p, L) == x){
            return p;
        } else {
            p = p->Next;
        }
    }
    return p->Next;
}

// in danh sách ra màn hình
void printList(List l){
    Position p = l->Next; // Bỏ phần tử header là con trỏ l dùng để quản lý list
    while(p != NULL){
        printf("%d ", p->data);
        p = p->Next;
    }
}



/*   stack   */
#define Maxlength 150
typedef struct Stack{
    int data[Maxlength];
    int top_idx;
} Stack;

// Khởi tạo ngăn xếp rỗng
void makenullStack(Stack *s){
    s->top_idx = Maxlength;
}

// Kiểm tra ngăn xếp rỗng
int emptyStack(Stack s){
    return s.top_idx == Maxlength;
}

// Kiểm tra ngăn xếp đầy

int fullStack(Stack s){
    return s.top_idx == 0;
}

// trả về phần tử đầu ngăn xếp

int top(Stack s){
    if(emptyStack(s)){
        printf("Errol empty stack");
        return -1;
    } else {
        return s.data[s.top_idx];
    }
}

// xóa phần tử tại đỉnh ngăn xếp

void pop(Stack *s){
    if(emptyStack((*s))){
        printf("Errol empty stack");
    } else {
        s->top_idx++;
    }
}

// thêm một phần tử vòa ngăn xếp

void push(int x,Stack *s){
    if(fullStack(*s)){
        printf("Errol full Stack");
    } else{
        s->top_idx--;
        s->data[s->top_idx] = x;
    }
}

// in ngăn xếp
void printStack(Stack s){
    if(emptyStack(s)){
        printf("Errol empty stack");
    }
    while(s.top_idx != Maxlength){
        printf("%d ", s.data[s.top_idx]);
        s.top_idx++;
    }
    printf("\n");
}


/*   Queue   */

typedef struct Queue{
    int data[Maxlength];
    int front, rear;
} Queue;

// tạo hàng đợi rỗng
void makenullQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

// Kiểm tra hàng đợi rỗng

int emptyQueue(Queue q){
    return q.front == -1;
}

// Kiểm tra hàng đợi đầy 

int fullQueue(Queue q){
    return (q.rear - q.front + 1) == Maxlength;
}

// Trả về phần tử đầu hàng

int front(Queue q){
    if(emptyQueue(q)){
        return 0;
    } else {
        return q.data[q.front];
    }
}

// xóa một phần tử khỏi hàng

void deQueue(Queue *q){
    if(emptyQueue(*q)){
        printf("Errol empty Queue");
    } else {
        q->front++;
        if(q->front > q->rear){
            makenullQueue(q);
        }
    }
}

// thêm một phần tử vào hàng đợi

void enQueue(int x, Queue *q){
    if(fullQueue(*q)){
        printf("Errol Full Queue");
    } else {
        if(emptyQueue(*q)){
            q->front = 0;
        }
        if(q->rear == Maxlength - 1){
            // di chuyển tịnh tiến ra phía trước front - 1 vị trí
            for(int i = q->front; i < q->rear; i++){
                q->data[i - q->front] = q->data[i];
            }
            // xác định vị trí mới
            q->front = 0;
            q->rear = Maxlength - q->front - 1;
        }
        q->rear++;
        q->data[q->rear] = x;
    }
}

// duyệt hàng đợi

void printQueue(Queue q){
    if(!emptyQueue(q)){
        while(q.front <= q.rear){
            printf("%d ", q.data[q.front]);
            q.front++;
        }
    }
}

int main(){
    Queue q;
    makenullQueue(&q);
    for(int i = 1; i < 11; i++){
        enQueue(i, &q);
    }
    printQueue(q);
    return 0;
}