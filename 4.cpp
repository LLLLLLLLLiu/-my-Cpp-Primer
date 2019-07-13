// 4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

//练习4.21
void f1() {
	vector<int> v1 = { 1,2,3,4,5 };
	
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		((*it % 2) == 1 )? *it=((*it) * 2 ): 1000;//最后一个分句可以随便写了,只要不赋值就行
		cout << *it << endl;
	}
}

//练习4.22
void f2() {
	vector<int> v1;
	int grade;
	cin >> grade;
	string finalgrade = (grade > 90) ? "high pass" : (grade > 75 ? "pass" : (grade > 60 ? "low pass" : "fail"));
	cout << finalgrade << endl;
}

//4.22
void f3() {
	vector<int> v1;
	int grade;
	cin >> grade;
	if (grade > 90) {
		cout << "high pass" << endl;
	}
	else if (grade > 75) {
		cout << "pass" << endl;
	}
	else if (grade > 60) {
		cout << "low pass" << endl;
	}
	else {
		cout << "fail" << endl;
	}
}

//4.28
void f4() {
	vector<int> v1 = { 1,2,3,4,5};
	cout << v1.size() << endl;

	int a[10] = { 1,2,3,4,5 };
	cout << sizeof(a) << endl;
	cout << sizeof(a) / sizeof(a[1]) << endl;
	cout << sizeof(int) << sizeof(long) << sizeof(long long) << sizeof(short) << sizeof(char) <<sizeof(bool)<< endl;
}

void f5() {
	int x[10]; int* p = x;
	cout << sizeof(x) / sizeof(*x) << endl;//这是数组的常规使用方法,因为数组没有定义.size()函数
	//cout << sizeof(p) / sizeof(*p) << endl;
}
//所示方法和容器的.size()用途相同;
//说明指针所占也是4个字节,和int类型一样,在我的这个编译环境之下.

void f6() {
	vector<int> ivec;
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;//cnt是count的意思
	for (auto i : ivec) {
		cout << i <<endl;//为何编译不了呢?
	}
}

int main() {
	


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
