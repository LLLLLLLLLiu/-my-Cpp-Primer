#include<iostream>
#include<vector>

using namespace std;

void f1() {
	typedef int difference_type;//但是不能用string::difference_type,不能使用限定名
	using p=int;
}

void f2() {
	string s;
	auto it1 = s.begin();
	auto it2 = s.end();
	string::difference_type d = it1 - it2;
	auto d2 = it1 - it2;
}
//用迭代器运算来实现二分搜索
void f3() {
	int tar;
	cout << "请输入需要查找的数字" << endl;
	cin >> tar;
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto beg = v.begin();
	auto end = v.end();
	auto mid = beg + (end - beg) / 2;//初始化mid
	while (mid != end && *mid != tar) {
		if (tar < *mid) {
			end = mid;//end指向的是存在的下一个,所以mid直接赋值给end很合适;
		}
		else{   //*mid<tar
			beg = mid + 1;//因为while确定了,*mid!=tar,所以mid+1赋值给beg
		}
		mid = beg + (end - beg) / 2;//更新mid,这很重要,别忘了
	}
	cout << mid-beg;//可不能<<mid,因为这是iterator类型的,没有重载<<,可以<<mid-beg,
	//因为这是类似于int类型的;
	//这里有一个重大问题:返回什么呢?--参见数据结构
}
//3.24
void f4() {
	vector<int> v;
	char ch = 'y';
	int a;
	while (cin >> a) {
		v.push_back(a);
		cout << "是否要继续输入,是(y),否(n)" << endl;
		cin >> ch;
		if (ch != 'y' && ch != 'Y') {
			break;
		}
		cout << "请输入下一个数字" << endl;
	}
	//由于会使用到end(),我们将其单独写,而不是放在循环里写
	//其实放在for循环里也行
	//因为我们最好不要去改变end()
	for (auto it= v.begin(); it < v.end; it=it+2) {//会不会跳过去,如果是加2的话,所以用<而不用!=
		cout << *it + *(it + 1);
	}
	//一定要注意哪些操作可以,哪些不可以
	for (auto it = v.begin(); it < v.end; it = it + 2) {
		cout << *it + *(v.end() -(v.end() - it));
	}
}

//3.25
void f5() {
	vector<unsigned> scores(11, 0);
	auto it = scores.begin();
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100) {
			++*(it + grade / 10);
		}
	}
}

int main() {
	f3();

	return 0;
}