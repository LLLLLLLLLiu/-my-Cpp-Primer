#include<iostream>
#include<vector>
using namespace std;
//���������ڵ��ó�Ա������ʱ�����();

void f1() {
	vector<int> v;
	auto b = v.begin();//b��������std::vector<int>::iterator,����iterator��һ����
	auto e = v.end();//��auto��һ���ǳ����ǵ�ѡ��;
	//����������������±��������,��һ������ָ��Ķ���;
	//vector����Щ��Ա����?
	//���ص�����ָԪ�ص�����,�������vector������;
}
//f2()����if��䱣֤���ǿ�,Ȼ��ı��˵�һ��
void f2() {
	//toupper()������������char�����,������������string�����;
	string s{ "some string" };
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s;
}
//f3()����ͨ��forѭ��ȥ�ı䲻ȷ������������,ͨ������ϸ�Ĳ������Ըı��������������,
//��֮��stl����Ҳ����ܶ����ƵĲ���
void f3() {
	string s{ "some string" };
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
		*it = toupper(*it);
	}
	cout << s;
}
//��range forֻ����ȥ���һ������,����ÿ������ô����,���޷����ո�ͣ��,
//getline��ʵ�������������ַ�,��ͣ��,Ĭ��Ϊ���з�;
void f31() {
	string s{ "some string" };//����Ҳ������for�����г�ʼ��,Ҳ������iterator���г�ʼ��
	//���ǲ�����range for���г�ʼ��,��Ҫ��while(cin>>char)��ʼ��
	for (auto &i : s) {
		i = toupper(i);
	}
}
//���±������
void f32() {
	string s{ "some string" };
	for (string::size_type i = 0; i < s.size() && s[i] != ' '; i++) {
		s[i] = toupper(s[i]);
	}//����,s[i]!=' 'Ҳ������!isspace(s[i])������,���ߵȼ�;
	cout << s;
}

void f4() {
	vector<int> v;
	const vector<int> cv;
	auto it1 = v.begin();
	auto it2 = cv.begin();//����Ϊvector<int>::const_iterator;
	auto it3 = v.cbegin();//const_iteratorֻ���Զ�,�����Ը�;
}

void f5() {
	vector<string> v{ "abc","gege", "fefe" };
	auto it = v.begin();
	auto it2 = v.end();
	(*it).empty();//���Ӧ������false
	//������(*it2)��Ϊit2ָ���������һ��֮��,��Խ���;
}

void f6() {
	vector<string> text{ "abc","gege", "   ","fefe" };
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
		cout << *it << endl;
	}
}
//��ϰ3.21
void f7() {
	vector<string> v6(10,"a");
	cout << v6.size()<<endl;//���ǿ��Ե�
	auto it1 = v6.begin();
	auto it2 = v6.end();
	cout << it2 - it1 << endl;
	for (; it1 != it2; ++it1) {
		cout << (*it1) << endl;
	}
}
//��ϰ3.22
void f8() {
	vector<string> text{ "abc","gege", "   ","fefe" };
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {//����,Ҫ��cbegin�����,cend����ν
		//��������һ���߼�,text��vector<string>,*it��string,c��char;toupper(c)������char;
		for (auto& c : *it) {
			c = toupper(c);
		}//��һ��Ҳ�����õ����������
		cout << *it << endl;//������ô���,���string,���ǲ��������vector
	}
	//ע��,��������ô���cout << text << endl;
	
}
//��ϰ3.23
void f9() {
	vector<int> v;
	cout << "������10������" << endl;
	int num;
	int i = 0;
	while (cin >> num && i != 10) {
		v.push_back(num);
		++i;
	}//����10������֮���ǿ��Խ��������,���ǲ������vector;��θı���һ����,���
	//����10������֮��ǿ��ֹͣ��?
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = *it * 2;
		cout << *it << endl;
	}
	//����range for,Ҫ��ı�ԭԪ����Ҫ&c,�޷��ı��Ϊc;�����ڵ�����,��Ҫ�ı������
	//����ı���ó�������,const_iterator
	
}
int main() {
	f9();
	return 0;
}