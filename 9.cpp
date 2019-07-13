// 9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;



/*vector<int>::iterator v1(int a) {
	vector<int> v1 = { 1,2,3,4,5,6 };
	for (auto it1 = v1.begin(); it1 != v1.end(); ++it1) {
		if (*it1 == a) {
			return it1;
		}
	}
	return v1.end();
}*/

void f2() {
	vector<int> v1;
	auto it = v1.end();

	v1.emplace_back(5);
	for (auto c : v1) {
		cout << c;
	}
	
}

void test1() {
	string s1 = "abcdefg";
	//string::iterator it1 = &s1[2];//错误,不可以从char*向iterator强制转换
	string::iterator it1 = s1.begin();//只能这么写
	auto it2 = s1.begin();//或者这么写
}

void f3() {
	vector<string> v1 = { "aaa","bbb","ccc" };
	auto it1 = v1.begin();
	//只能这么写,然后考虑往后面移动几位,如果是重载了[]运算符的呢?见test1();
	v1.insert(it1, "ggg");
	for (auto c : v1) {
		cout << c << endl;
	}
}

void test2() {
	vector<int> v1 = { 0,1,2,3,4,5,6,7,8,9,10 };
	auto it1 = v1.begin();
	it1 = it1 + 5;
	auto v2 = v1.insert(it1, 3, 5);
	cout << *(v2 - 1) << endl;
	//{0,1,2,3,4,5,5,5,5,6,7,8,9,10}最终结果是4,说明返回的指针是最前面的那个5;
}

//练习9.18,这个和答案基本一样了
void f4() {
	deque<string> sdq;
	string s1;
	char ch = 'y';
	auto it = sdq.end();
	while (cin >> s1) {
		//sdq.push_front(s1);
		//sdq.push_back(s1);
		it = sdq.insert(it, s1);//相当于push_front
		//sdq.insert(it, s1);//libpng warning: iCCP: known incorrect sRGB profile
		cout << "是否要继续输入" << endl;
		cin >> ch;
		if (ch != 'y') {
			break;
		}
		cout << "请继续输入下一个字符串" << endl;
	}
	/*for (auto c : sdq) {
		cout << c << endl;
	}*/
	for (deque<string>::iterator it1 = sdq.begin(); it1 != sdq.end(); ++it1) {
		cout << *it1 << endl;
	}//虽然完全可以这么写,但是这么写显得有问题,显得不符合FIFO的原则了,所以在输入和输出的时候要加以考量
}


//practice 9.19
void f5() {
	list<string> slist;
	string s;
	while (cin >> s) {
		slist.push_back(s);
		slist.push_front(s);
		
		auto itbeg = slist.begin();
		itbeg=slist.insert(itbeg, s);//相当于push_front
		auto itend = slist.end();
		itend=slist.insert(itend, s);//相当于push_front
	}
}

//练习9.20
// 故意用难一些的insert来写,其实用push_back写是最简单的,push_back是会让输出顺序,如果是it从beg到end的话
//而insert和push_front则是逆序的,当然,也可以改变it的顺序,从end到beg;
//答案是用位运算查看最低位
void f6() {
	list<int>ilist{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> idq1, idq2;
	auto it2 = idq1.begin();
	auto it3 = idq2.begin();
	for (auto it1 = ilist.begin(); it1 != ilist.end(); ++it1) {
		if ((*it1) % 2 == 0) {
			it2 = idq1.insert(it2, *it1);
		}
		else {
			it3 = idq2.insert(it3, *it1);
		}
	}
	cout << "偶数为" << endl;
	for (auto c : idq1) {
		cout << c << endl;
	}
	cout << "奇数为:" << endl;
	for (auto c : idq2) {
		cout << c << endl;
	}
}


//9.21
int main()
{
	f6();

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
