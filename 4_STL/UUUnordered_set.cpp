#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
/*
1. Đặc điểm
   + Các phần tử trong unordered_set đôi một khác nhau
   + unordered_set không duy trì bất kỳ thứ tự nào giữa các phần tử mà nó chứa
   + Không có 2 phần tử giống nhau và khi in ra thì tùy vào hash mà nó in ra thứ tự khác nhau
2. Khai báo
   + Thư viện cần unordered_set 
   + Cú pháp: unordered_set<data_type> name_set;
3. Sự khác nhau với set và multiset
   + Các hàm find(), erase(), insert() của set và multiset có độ phức tạp là O(logN)
   + Các hàm find(), erase(), insert() của unordered_set có độ phức tạp trong trường hợp trung bình là O(1) và trong trường hợp tệ nhất là O(N)
*/


int main(){
   unordered_set<int> st = {2,3,4,32,5,6,8,6,4};
   for(int it : st){
      cout << it << " ";
   }
   if(st.find(3) == st.end()){
      cout << "\nNot Found" << endl;
   } else {
      cout << "\nFound" << endl;
   }
    return 0;
}
