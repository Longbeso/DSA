#include<iostream>
using namespace std;
// sắp xếp chọn
// tìm index của thằng nhỏ nhất xong hoán đổi vị trí với phần tử hiện tại arr[i]
// độ ổn định kém do có thể đối vị trí tương đối của 2 phần tử bằng nhau như 4(a), 4(b)
// sau khi s sx thì thành a(b), 4(a);

#define N 10
int main(){
    int arr[N] = {1, 6, 8, 3, 5, 2, 20, 12, 8, 14};
    for(int i = 0; i < N - 1; i++){
        int MinIndex = i;
        for(int j = i + 1; j < N; j++){
            if(arr[j] < arr[MinIndex]){
                MinIndex = j;
            }
        }
        if(MinIndex != i){
            int tmp = arr[MinIndex];
            arr[MinIndex] = arr[i];
            arr[i] = tmp;
        }
        
    }
    for(int i = 0; i < N;i++){
        cout << arr[i] << " " ;
    }
    return 0;
}