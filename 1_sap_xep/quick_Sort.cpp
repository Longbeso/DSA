#include<iostream>
#define N 10
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right]; // chọn thằng cuối làm chốt(pivot)
    int i = left - 1; // tí nữa sẽ nâng giá trị lên để swap nên không lo nó là -1 
    for(int j = left; j < right;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); // đưa pivot về đúng vị trí sắp xếp và một lát đệ qui ta sẽ không đụng tới pivot này nữa
    return i + 1; // trả về vị trí của pivot để xíu dùng cho việc chia ra và đệ qui tiếp
}

void quickSort(int arr[], int left, int right){
    if(left < right){ // chú ý điều kiện, nếu không còn thằng nào để chia mảng ra làm 2 tức là thằng pivot sau khi đổi chỗ ở hàm 
                      // partition vẫn ở nguyên vị trí cuối thì sẽ không sắp xếp bên phải nó
        int pi = partition(arr, left, right); // lấy vị trí pivot để loại nó khỏi thuật toán, tức không chuyển đổi vị trí nó nữa
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main(){
    int arr[N] = {1, 6, 2, -5, 9, 45, 6, -2 , 4, 19};
    int left = 0, right = N - 1;
    quickSort(arr, left, right);
    for(int i = 0; i < N;i++){
        cout << arr[i] << " " ;
    }
    return 0;
}