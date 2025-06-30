#include<stdio.h>
#include<stdlib.h>

// cây tìm kiếm nhị phân Binary Search Tree
// con trái của nút gốc sẽ nhỏ hơn nút gốc và con phải sẽ lớn hơn nút gốc
// và trong cây không có nút trùng nhau

typedef int KeyType;
typedef struct Node{
    KeyType key;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Tree;

// tìm kiếm trong cây tìm kiếm nhị phân

Tree Search(KeyType x, Tree Root){
    if(Root == NULL){
        return NULL;
    } else if(Root->key == x){
        return Root;
    } else if(Root->key < x){
        return Search(x, Root->right);
    } else {
        return Search(x, Root->left);
    }
}

// thêm một nút có khóa Key = x vào BST
void InsertNode(KeyType x,Tree *Root){
    if(*Root == NULL){
        *Root = (Node*)malloc(sizeof(Node));
        (*Root)->key = x;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
    } else if(x < (*Root)->key){
        InsertNode(x, &(*Root)->left);
    } else if(x > (*Root)->key) {
        InsertNode(x, &(*Root)->right);
    }
}
// hàm cần
KeyType DeleteMin(Tree *Root){
    KeyType k;
    if((*Root)->left==NULL){
    k=(*Root)->key;
    (*Root)=(*Root)->right;
    return k;
    }else DeleteMin(&(*Root)->left);
}

void DeleteNode(KeyType x, Tree *Root) {
    if (*Root != NULL) {
        if (x < (*Root)->key) {
            DeleteNode(x, &((*Root)->left));
        }
        else if (x > (*Root)->key) {
            DeleteNode(x, &((*Root)->right));
        }
        else if ((*Root)->left == NULL && (*Root)->right == NULL) {
            *Root = NULL;
        }
        else if ((*Root)->left == NULL) {
            *Root = (*Root)->right;
        }
        else if ((*Root)->right == NULL) {
            *Root = (*Root)->left;
        }
        else {
            (*Root)->key = DeleteMin(&((*Root)->right));  // Giữ đúng ý bạn
        }
    }
}

int main(){
    Node t;
    return 0;
}