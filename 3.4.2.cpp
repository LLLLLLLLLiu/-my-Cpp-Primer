#include<iostream>
#include<vector>

using namespace std;

void f1() {
	typedef int difference_type;//���ǲ�����string::difference_type,����ʹ���޶���
	using p=int;
}

void f2() {
	string s;
	auto it1 = s.begin();
	auto it2 = s.end();
	string::difference_type d = it1 - it2;
	auto d2 = it1 - it2;
}
//�õ�����������ʵ�ֶ�������
void f3() {
	int tar;
	cout << "��������Ҫ���ҵ�����" << endl;
	cin >> tar;
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto beg = v.begin();
	auto end = v.end();
	auto mid = beg + (end - beg) / 2;//��ʼ��mid
	while (mid != end && *mid != tar) {
		if (tar < *mid) {
			end = mid;//endָ����Ǵ��ڵ���һ��,����midֱ�Ӹ�ֵ��end�ܺ���;
		}
		else{   //*mid<tar
			beg = mid + 1;//��Ϊwhileȷ����,*mid!=tar,����mid+1��ֵ��beg
		}
		mid = beg + (end - beg) / 2;//����mid,�����Ҫ,������
	}
	cout << mid-beg;//�ɲ���<<mid,��Ϊ����iterator���͵�,û������<<,����<<mid-beg,
	//��Ϊ����������int���͵�;
	//������һ���ش�����:����ʲô��?--�μ����ݽṹ
}
//3.24
void f4() {
	vector<int> v;
	char ch = 'y';
	int a;
	while (cin >> a) {
		v.push_back(a);
		cout << "�Ƿ�Ҫ��������,��(y),��(n)" << endl;
		cin >> ch;
		if (ch != 'y' && ch != 'Y') {
			break;
		}
		cout << "��������һ������" << endl;
	}
	//���ڻ�ʹ�õ�end(),���ǽ��䵥��д,�����Ƿ���ѭ����д
	//��ʵ����forѭ����Ҳ��
	//��Ϊ������ò�Ҫȥ�ı�end()
	for (auto it= v.begin(); it < v.end; it=it+2) {//�᲻������ȥ,����Ǽ�2�Ļ�,������<������!=
		cout << *it + *(it + 1);
	}
	//һ��Ҫע����Щ��������,��Щ������
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