#include<iostream>
#include<vector>
using namespace std;

//�����vector���Ǵ����ͬ����Ԫ�ص�����,����˵,���ݽṹ
//������ָ������,��string����,�ж�������,�ǲ����еĵط�������string����vector��
//��û��ָ��vector,����vector;��˵����Ҳ���Ե�;
//const ��constexpr��ʲô����,�������ƺ���һ����
/*
unsigned cnt = 42;
const unsigned sz = 42;
int arr[10];
int* parr[sz];
string bad[cnt];
string* strs[sz];
string strs[get_size()];
*/
//����,��һ��������vector�Ķ���.
//��ϰ3.31
//����һ�������д��,����i�ﵽ��10,���������Ӧ����0-9;
/*void f1() {
	int a[11];
	for (auto i : a) {
		a[i] = i;
	}
	cout << a[11] << endl;//
}*/

void f2() {
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i]=i;
	}
	cout << a[10] << endl;
}//������ȴ��-858993460


//���鿽��
void f3() {
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
		cout << i;
	}
	int b[10];
	for (int i = 0; i < 10; i++) {
		b[i] = a[i];
	}
}


void f4() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
}

//�ۼ��ֳ�ʼ��vector�ķ�ʽ
void f5() {
	vector<int> v2;
	for (int i = 0; i < 10; ++i) {
		int m2;
		cin >> m2;
		v2.push_back(m2);
	}

	vector<int> v3;
	int m3;
	while (cin >> m3) {
		v3.push_back(m3);
	}
}

int main() {
	f3();
	

	return 0;
}