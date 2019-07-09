#include<iostream>
#include<vector>
using namespace std;
//总是忘记在调用成员函数的时候加上();

void f1() {
	vector<int> v;
	auto b = v.begin();//b的类型是std::vector<int>::iterator,其中iterator是一个类
	auto e = v.end();//用auto是一个非常明智的选择;
	//迭代器是用来替代下标运算符的,是一种类似指针的东西;
	//vector有哪些成员函数?
	//返回的是所指元素的引用,而非这个vector的引用;
}
//f2()是用if语句保证不是空,然后改变了第一个
void f2() {
	//toupper()函数是作用在char上面的,而不是作用在string上面的;
	string s{ "some string" };
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s;
}
//f3()则是通过for循环去改变不确定个数的内容,通过更精细的操作可以改变任意个数的内容,
//在之后stl函数也会给很多类似的操作
void f3() {
	string s{ "some string" };
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
		*it = toupper(*it);
	}
	cout << s;
}
//用range for只可以去解决一类问题,就是每个都这么操作,而无法检测空格停下,
//getline其实可以设置特征字符,来停下,默认为换行符;
void f31() {
	string s{ "some string" };//这里也可以用for语句进行初始化,也可以用iterator进行初始化
	//但是不能用range for进行初始化,而要用while(cin>>char)初始化
	for (auto &i : s) {
		i = toupper(i);
	}
}
//用下标运算符
void f32() {
	string s{ "some string" };
	for (string::size_type i = 0; i < s.size() && s[i] != ' '; i++) {
		s[i] = toupper(s[i]);
	}//这里,s[i]!=' '也可以用!isspace(s[i])来代替,两者等价;
	cout << s;
}

void f4() {
	vector<int> v;
	const vector<int> cv;
	auto it1 = v.begin();
	auto it2 = cv.begin();//类型为vector<int>::const_iterator;
	auto it3 = v.cbegin();//const_iterator只可以读,不可以改;
}

void f5() {
	vector<string> v{ "abc","gege", "fefe" };
	auto it = v.begin();
	auto it2 = v.end();
	(*it).empty();//这个应当返回false
	//不可以(*it2)因为it2指向向量最后一个之后,是越界的;
}

void f6() {
	vector<string> text{ "abc","gege", "   ","fefe" };
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
		cout << *it << endl;
	}
}
//练习3.21
void f7() {
	vector<string> v6(10,"a");
	cout << v6.size()<<endl;//这是可以的
	auto it1 = v6.begin();
	auto it2 = v6.end();
	cout << it2 - it1 << endl;
	for (; it1 != it2; ++it1) {
		cout << (*it1) << endl;
	}
}
//练习3.22
void f8() {
	vector<string> text{ "abc","gege", "   ","fefe" };
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {//首先,要把cbegin解除掉,cend无所谓
		//我们来理一下逻辑,text是vector<string>,*it是string,c是char;toupper(c)作用于char;
		for (auto& c : *it) {
			c = toupper(c);
		}//这一步也可以用迭代器来完成
		cout << *it << endl;//可以这么输出,输出string,但是不可以输出vector
	}
	//注意,不可以这么输出cout << text << endl;
	
}
//练习3.23
void f9() {
	vector<int> v;
	cout << "请输入10个数字" << endl;
	int num;
	int i = 0;
	while (cin >> num && i != 10) {
		v.push_back(num);
		++i;
	}//输入10个数字之后还是可以接着输入的,但是不会计入vector;如何改变这一特性,编程
	//输入10个数字之后强行停止呢?
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = *it * 2;
		cout << *it << endl;
	}
	//对于range for,要想改变原元素需要&c,无法改变的为c;而对于迭代器,想要改变就正常
	//不想改变就用常迭代器,const_iterator
	
}
int main() {
	f9();
	return 0;
}