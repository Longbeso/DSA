#include<iostream> 
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;




// prev = previous -> trước đó
int jumb_search(const vector<int>& vt, int target){
    int n = vt.size();
    int step = sqrt(n);
    int prev = 0;
    while(vt[min(step,n) - 1] < target){
        prev = step;
        step += sqrt(n);
        if(prev >= n){
            return -1; // không tìm thấy
        }
        if(step > n){
            step = n;
        }
    }
    while(vt[prev] < target){
        prev++;
        if(prev >= min(step,n)){
            return -1;
        }
    }
    if(vt[prev] == target){
        return prev;
    }
    return -1;
}

int main(){
    vector<int> v ={1,2,3,4,5,6,8,9,12};
    int tar; cout << "Nhap so can tim: "; cin >> tar;
    if(jumb_search(v,tar) != -1){
        cout << "vi tri cua " << tar <<  " trong vector la: " << jumb_search(v,tar) << endl;
    } else {
        cout << "Khong tim thay " << tar << " trong vector" << endl;
    }
    return 0;
}