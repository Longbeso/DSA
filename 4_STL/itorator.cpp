#include<iostream>
#include<vector>
using namespace std;

// iterator tương tự như con trỏ, nó trỏ tới các phần tử trong vector

/*
1.begin() : Iterator trỏ tới phần tử đầu tiên trong vector
2.end() : Iterator trỏ tới phần tử sau phần tử cuối cùng trong vector
3.rbegin() : Iterator ngược trỏ tới phần tử cuối cùng trong vector
4.rend() : Iterator ngược trỏ tới phần tử trước phần tử đầu tiên trong vector
*/

// 1. Khai báo

/*
Container     | Kiểu iterator
vector<int>   | vector<int>::iterator
set<string>   | set<string>::iterator
map<int, int> | map<int, int>::iterator
list<char>    | list<char>::iterator
*/
// 2. lưu ý khi dùng
// dùng toán tử * khi tham chiếu 
// dùng như con trỏ bình thường nếu muốn tăng hoặc giảm thì dùng toán tử -- ++
// ta thấy it = v.begin(); tức là it trỏ đến phần tử đầu tiên
// vậy đến phần tử có index 2 là it + 2;
int main(){
    vector<int> v = {1, 2, 3, 4, 6, 7};
    vector<int>::iterator it1 = v.begin();
    vector<int>::reverse_iterator it2 = v.rbegin();
    cout << "v[2]: " << *(it1 + 2) << endl;
    cout << "v[6]: " << *it2 << endl;
    cout << "1. Duyet vector bang iterator!" << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    vector<int> vt = {2,3,4,5,6,7,5,3,2};
    vector<int>::iterator it = vt.begin();
    it += 3;
    cout << endl << "2. Chi so ma it dang tro toi!" << endl;
    cout << "3. Gia tri dang tro toi: " << *it << endl;
    cout << "4. Vi tri hien tai: " << it - vt.begin() << endl;
    cout << "5. Vi tri hien tai dung ham distance " << distance(vt.begin(), it) << endl;
    return 0;
}