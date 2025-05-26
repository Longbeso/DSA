/*    Hàm find()  o(log N): tìm phần tử trong set nếu tìm được thì trả về iterator ứng với phần tử đó nếu không thì nó trả về iterator end()   
    Hàm count() 
    Hàm erase()
    Hàm lower_bound()
    Hàm upper_bound()
*/
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> st = {2,3,6,5,4,2,4,6,7};
    int n = size(st);
    int x;
    cout << "Nhap so can tim: ";
    cin >> x;

    if(st.find(x) != st.end()){
        cout << x << " Co ton tai trong set" << endl;
    } else {
        cout << x << " Khong ton tai trong set!" << endl;
    }

    if(st.count(x) != 0){
        cout << x << " Co ton tai trong set" << endl;
    } else {
        cout << x << " Khong ton tai trong set" << endl;
    }
    st.erase(3);
    for(set<int>::iterator it = st.begin(); it != st.end();it++){
        cout << *it << " ";
    }
    return 0;
}