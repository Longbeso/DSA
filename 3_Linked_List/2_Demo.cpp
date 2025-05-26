#include<iostream>
using namespace std;

// Mỗi node là một con trỏ kiểu node và nó quản lý một node khác

struct node {
                 // Có thể lưu nhiều dữ liệu khác nhau với 1 node
    int data;    // dữ liệu của node 
    node* next;  // con trỏ kiểu node dùng để trỏ tới node tiếp theo
};

node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode; // trả về con trỏ
}

void duyet(node *head){
    while(head != NULL){
        cout << head->data << " " << endl;
        head = head->next; // cho con trỏ head trỏ tới node tiếp theo,
                           // cho con trỏ head = con trỏ next;
    }
}

int count(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head->next;
    }
    return cnt;
}

// truyền con trỏ head vào, vì head đã là con trỏ nên ta cần **head
void push_node_head(node** head, int x){
    // lúc này head là một con trỏ kiểu node**
    node *newNode = makeNode(x);
    // Bước 1 : cho next của newNode trỏ vào head
    newNode->next = *head; // *head địa chỉ của node head trong dslk
    // Bước 2 : Cập nhâtk node head => newnode
    *head = newNode;
}
void push_node_head2_cpp(node *&head, int x){
    node *newNode = makeNode(x);
    // Bước 1 : cho next của newNode trỏ vào head
    newNode->next = head; // *head địa chỉ của node head trong dslk
    // Bước 2 : Cập nhâtk node head => newnode
    head = newNode;
}
int main(){
    node *head = NULL;
    for(int i = 1 ; i <= 5; i++){
       push_node_head(&head, i);
    }
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
   
    
    return 0;
}





