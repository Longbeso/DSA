#include<iostream>
#include<set>
using namespace std;
/*
    Hàm	                   Chức năng
 size()	               Số lượng phần tử trong set
 insert()	           Thêm phần tử vào trong set
 empty()	           Kiểm tra set rỗng, nếu đúng trả về true, ngược lại trả về false
 clear()	           Xóa toàn bộ phần tử trong set
*/

/*
    1. Khai báo
    set<data_type> set_name;
    set<int> st;
    2. duyệt set
       + duyệt bằng iterator 
       + duyệt bằng for each
    3. Một số hàm thông dụng của set trong c++
    Hàm find()  O(log N): tìm phần tử trong set nếu tìm được thì trả về iterator ứng với phần tử đó nếu không thì nó trả về iterator end()   
    Hàm count() O(log N): Hàm count() trả về số lần xuất hiện của phần tử trong set, do đó hàm này sẽ có giá trị trả về là 0 hoặc 1 tùy theo giá trị đếm có xuất hiện trong set hay không.
    Hàm erase() O(log N): Hàm erase() giúp bạn có thể xóa một giá trị ra khỏi set, ngoài ra có thể xóa thông qua iterator trỏ tới giá trị đó trong set.
    Hàm lower_bound()
    Hàm upper_bound()
*/
int main(){
    set<int> st;
    int n;
    cout << "Nhap so phan tu cho set: " ;
    cin >> n;
    cout << "Nhap set!" << endl;
    for(int i = 0; i < n; i++){
        int x;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        st.insert(x);
    }
    cout << "Duyet set!" << endl;
    for(set<int>::iterator it = st.begin() ; it != st.end(); it++){
        cout << *it << " ";
    }

    return 0;
}