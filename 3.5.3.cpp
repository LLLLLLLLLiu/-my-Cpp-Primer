#include <iostream>
#include<iterator>
#include<string>
using namespace std;

void f1() {
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	auto ia2(ia);
	auto ia3 = ia;
	cout << ia2 << ia3;
}

void f2() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pe = &arr[10];
	int* pb = arr;
	for (; pb != pe; ++pb) {
		cout << *pb << endl;
	}
}

void f3() {
	int ia[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* beg = begin(ia);
	int* last = end(ia);
}
//
void f4() {
	string str[10] = { "a","abc","123" };
	string* p1 = str;
	string* p2 = str + 1;
	string* p3 = str + 2;
	cout << p1 << "  " << p2 << "  " << p3 << endl;
	cout << *p1 << "  " << *p2 << "  " << *p3 << endl;//每+1,过16字节

	int a[10] = { 1,2,3 };
	int* p4 = a;
	int* p5 = a + 1;
	int* p6 = a + 2;
	cout << p4 << "  " << p5 << "  " << p6 << endl;
	cout << *p4 << "  " << *p5 << "  " << *p6;//每+1,过4字节
}
//3.35 这个和答案写的差不多
void f5() {
	int ia[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int* pb = begin(ia); pb != end(ia); ++pb) {
		*pb = 0;
	}
	for (auto c : ia) {
		cout << c << endl;
	}
}

//3.36 s2比s1大的情况没法解决呀
void f6() {
	string s1[10] = { "abc","fefef","pepep" };
	string s2[11] = { "abc","fefef","pepep" };
	string* pb2 = begin(s2);
	for (string* pb = begin(s1); pb != end(s1); pb++) {
		if (*pb != *pb2) {
			cout << "不相同" << endl;
			break;
		}
		if (pb2 > end(s2)) {
			cout << "不相同" << endl;
			break;
		}
		pb2++;
	}

}

//这一题答案写的非常好呀
int main()
{
	f6();
}

