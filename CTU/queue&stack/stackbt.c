#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*   stack   */
typedef char  elementType;
#define Maxlength 150
typedef struct Stack{
    elementType data[Maxlength];
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

elementType top(Stack s){
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

void push( elementType x,Stack *s){
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
        printf("%c ", s.data[s.top_idx]);
        s.top_idx++;
    }
    printf("\n");
}


// 1. in ra chuỗi ngược
// 2. kiểm tra biểu thức đúng 
int main(){
    Stack s;
    makenullStack(&s);
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '('){
            push(str[i], &s);
        }
        if(str[i] == ')'){
            if(emptyStack(s)){
                printf("bieu thuc loi");
                return 0;
            }
            if(top(s) == '('){
                pop(&s);
            } else {
                printf("Bieu thuc khong hop le");
                return 0;
            }
        }
    }
    if(!emptyStack(s)){
        printf("Bieu thuc loi");
        return 0;
    }
    printf("Bieu thuc dung");
    // printStack(s);
    
    return 0;
}