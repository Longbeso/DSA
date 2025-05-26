#include<iostream>
using namespace std;

#define N 10
int main(){
    int arr[N] = {1, 6, 8, 3, 5, 2, 20, 12, 8, 14};
    for(int i = 1; i < N; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){ // khi phân tích thuật toán thì ta thấy thằng cần so sánh là key chứ không phải a[i]
            arr[j + 1] = arr[j];
            j--; 
        }
        arr[j + 1] = key;
    }
    for(int i = 0; i < N;i++){
        cout << arr[i] << " " ;
    }
    return 0;
}