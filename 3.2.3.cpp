// cp3.2.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cctype>
#include<vector>
using namespace std;

void func1() {
	string str="abcdefg";
	for (char c : str)
		cout << c << endl;
}

void func2() {
	const string s = "Hello world!!!!!";
	decltype(s.size()) sum=0;
	for (auto c : s) {
		if (ispunct(c)) {
			sum++;
		}
	}
		cout << sum;
	
}

void func3() {
	string s = "Hello world!!!!!";
	for (auto& c : s) {
		c = toupper(c);
	}
	cout << s << endl;
}

void func4() {
	string str{ "Hello world" };
	for (auto &c : str) {
		c = 'X';
	}
	cout<<str;
}

void func5() {
	string str{ "Hello world" };
	string::size_type i = 0;
	while (i<str.size()) {
		str[i] = 'X';
		i++;
	}
	cout << str;
}
//3.9在cout<<s[0]之前需要判断s是否是空的，也就是说，即使是s[0],也有可能是空的。
//具体判断方式有以下两种,第一种显得非常low,第二种是书上的,比较高明.
void func6(){
	string str;
	while (str.size() != 0) {
	cout << str[0];
}
	if (!str.empty()) {
		cout << str[0];
	}
}
//练习3.10,答案上的两种方法非常好,我写的总是有问题.
void func7() {
	string str{ "H,,AALFE,," };
	string::size_type i = 0;
	while (i < str.size()) {
		if (ispunct(str[i])) {
			i = i + 1;
		}
	}

}
//这个方式有问题,编译器会报错,但我不知道为何会报错.
void func8() {
	string str{ "H,FAFA,FAFA" };
	for (auto &c : str) {
		if (ispunct(str[c])) {
			str.erase(c);
		}
	}
	cout << str;
}
int main() {
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	func8();
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
