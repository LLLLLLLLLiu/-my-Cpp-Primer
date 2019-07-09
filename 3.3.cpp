
#include <iostream>
#include<vector>
using namespace std;


//**vector不可以<<的;
//cout<<v1会报错;
//范围for有哪些用处?可不可以对vector使用?
//3.3.1的内容太简单了就不写了
void f1() {
	vector<int> v;
	for (int i = 0; i != 100; ++i) {
		v.push_back(i);
	}
}
//练习3.14
//答案写的非常好,还有交互
void f2() {
	vector<int> v1;
	int a;
	while (cin >> a) {
		v1.push_back(a);
	}
}
//练习3.15
void f3() {
	vector<string> v1;
	string s1;
	while (cin >> s1) {
		v1.push_back(s1);
	}
}
//验证3.3.3v[n]的重载形式
void f4() {
	vector < string >  v1 {"abc", "qwe", "eee"};
	cout << v1[1] << endl;
}
//3.16,就以3.13中的(f)为例:这个应当输出10个空串,也就是啥也没有
void f5() {
	vector<string> v6{ 10 };
	for (auto i : v6) {
		cout << i;
	}
}
//需要格外注意的是,什么时候需要用range for语句,什么时候用while(cin>>v)语句
//而这两种语句是非常常用的
//3.17,这个我和标准答案差不多但是却无法编译通过,不知道为什么;
void f6() {
	vector<string> v1;
	string word;
	//输入必须要有个停止的办法
	char ch = 'y';
	while (cin >> word) {
		v1.push_back(word);
		cout << "是否要继续输入,如果是,请输入y,否则请输入n" << endl;
		cin >> ch;
		if (ch != 'y' && ch != 'Y') {
			break;
		}
	}
	//这个双重循环费了我一番思考
	for (auto &i : v1) {    //这里auto是string类型的吗?这里对i和j是什么的认识至关重要
		for (auto &j : i) {
			j=toupper(j);//这里我忘了j=toupper(j)了,而不能只写toupper(j)
		}
		cout << i << endl;
	}
}
//3.20
void f7() {
	vector<int> v1;
	int a;
	char ch;
	while (cin >> a) {
		v1.push_back(a);
		cout << "您还需要再输入吗?是(y),否(n)";
		cin >> ch;
		if (ch != 'y' && ch != 'Y') {
			break;
		}
		cout << "请输入下一个数字";
	}
	for (vector<int>::size_type i = 0; i !=v1.size();++i) {
		v1[i] = v1[i] + v1[i + 1];
	}
	for (auto j : v1) {
		cout << j;
	}
}

//3.20是不是需要再增加一个vector来存储运算过的原vector;
void f8() {
	vector<int> v1,v2;//在之前的基础上又增加了v2;
	int a;
	char ch;
	while (cin >> a) {
		v1.push_back(a);
		cout << "您还需要再输入吗?是(y),否(n)";
		cin >> ch;
		if (ch != 'y' && ch != 'Y') {
			break;
		}
		cout << "请输入下一个数字";
	}//以上是初始化一个vector的套路;
	auto s = v1.size();//这里可以用auto,但是下一行的i就不能用,否则就给了一个int,这并不是我们想要的
	for (vector<int>::size_type i = 0; i != s/2; ++i) {//这里其实没有考虑奇偶性,简化起见,就默认为偶数吧;
		v2[i] = v1[i] + v1[s-i];
	}
	for (auto j : v2) {
		cout << j;
	}
}
//答案是直接输出了,没有考虑再把它们放入一个vector中;
//但是我的3.20无法编译通过;
int main()
{
	
	return 0;
}
