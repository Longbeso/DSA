#include<stdlib.h>
#include<stdio.h>
using namespace std;

// con trỏ head thật chất là một con trỏ dùng để lưu địa chỉ của một biến có kiểu dữ liệu là node, bản thân nó không có trường nào hết;



// tạo kiểu dữ liệu node
struct node{
    int data;
    struct node *next;
};
#define node struct node

// hàm đếm số lượng node

int count(node *head){
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        ++cnt;
    }
    return cnt;
}

// tạo node mới
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// đưa một node vào đầu danh sách
void font_node(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head; // *head ở đây là node đầu tiên
    *head = newNode;
}
// in linked list ra
void print_list(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}
// thêm vào cuối danh sách liên kết

void pushBack(node **head, int x){
    /* phải dùng một con trỏ tạm để duyệt nhằm tránh thay đổi vị trí thật sự của con trỏ head*/
    node *temp = *head;
    node *NewNode = makeNode(x); 
    if(temp == NULL){
        *head = NewNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = NewNode;
}

// chèn vào giữa linked list

void insert(node **head,int position, int x){
    // Nếu chèn thì phải chèn vạof ví đầu tới vị trí cuối
    // từ vị trí 1 tới vị trí sau node cuối 
    // nếu là 1 tức là sau khi chèn nó sẽ ở vị trí đầu tiên
    int n = count(*head);
    if(position < 1 || position > n + 1){
        return;
    }
    if(position == 1){
        font_node(head, x);
        return;
    }
    if(position == n){
        pushBack(head, x);
        return;
    }

    node *NewNode = makeNode(x);
    node *temp = *head;
    // 1. Duyệt đến vị trí trước vị trí cần chèn
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }
    // 2. cho NewNode trỏ vào con trỏ phía sau, tức là con trỏ tại vị trí trước khi chèn tại vị trí cần chèn
    NewNode->next = temp->next;
    // 3. cho node trước vị trí cần chèn trỏ vào NewNode.
    temp->next = NewNode;
}

/* xóa ở đầu */

void popFront(node **head){
    /* head là con trỏ trỏ vào list */
    /* *head là giá trị nó trỏ tới ở đây là node đầu tiên */
    /* *head là node đầu tiên trong list */
    if(head == NULL){
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

/* xóa ở cuối */
void popBack(node **head){
    if(head == NULL){
        return;
    }
    node *temp = *head;
    if(temp->next == NULL){
        *head = NULL; 
        free(temp);
        return;
        /* trường hợp chỉ có đúng 1 node */
    }
    /* điều kiện trong thằng while: tham chiếu tới node kế tiếp và kiểm tra xem next của nó có phải là NULL hay không
       Ví dụ có 4 node thì bắt đầu ở node 1 nó sẽ lấy next là tham chiếu cái next đó và lại lấy cái next của node tiếp theo
       tức:
        đang ở node đầu thì nó sẽ kiểm tra node thứ 2 có đang trỏ vào NULL hay không, 
        nếu có thì dừng , không thì chạy */
    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    free(last);
    
}

/* xóa node ở giữa */

void erase(node **head, int k){
    int n = count(*head);
    if(k < 1 || k > n){
        return;
    }
    if(k == 1){
        popFront(head);
        return;
    }
    else {
        node *temp = *head;
        for(int i = 0; i < k - 2; i++){
            temp = temp->next;
        }
        node* positionK = temp->next; // đây là thằng k nhé, để lát xóa bộ nhớ
        temp->next = temp->next->next; // hoặc
        free(positionK);
    }
}
int main(){
    node *f = NULL;
    // while(1){
    //     printf("1. them vao dau danh sach\n");
    //     printf("2. Them vao cuoi danh sach\n");
    //     printf("3. Them vao giua danh sach lien ket\n");
    //     printf("4. Duyet\n");
    //     printf("5. popFront\n");
    //     printf("0. Thoat!\n");
    //     printf("Nhap lua chon: ");
    //     int n, i, pos;
    //     scanf("%d", &n);
    //     switch (n)
    //     {
    //     case 1:
    //     printf("Nhap gia tri can them: ");
    //     scanf("%d", &i);
    //     font_node(&f, i);
    //         break;
    //     case 2:
    //     printf("Nhap gia tri can them: ");
    //     scanf("%d", &i);
    //     pushBack(&f, i);
    //         break;
    //     case 3:
    //     printf("Nhap gia tri can them: ");
    //     scanf("%d", &i);
    //     printf("\nNhap vi tri can them: ");
    //     scanf("%d", &pos);
    //     insert(&f, pos, i);
    //         break;
    //     case 4:
    //     printf("\n");
    //     print_list(f);
    //     printf("\n");
    //         break;
    //     case 0:
    //     return 1;
    //         break;
    //     default:
    //     printf("\nNhap lai lua chon\n");
    //         break;
    //     }
    // }
    // for(int i = 5; i > 0;i--){
    //     font_node(&f, i);
    // }
    // insert(&f, 3, 69);
    // print_list(f);
    for(int i = 0; i < 5; i++){
        font_node(&f,i);
    }
    erase(&f, 3);
    print_list(f);
    return 0;
}