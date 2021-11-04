#include <iostream>
using namespace std;
#include <fstream>
#include <string>
// �ļ����ͷ�Ϊ����:
// 1.�ı��ļ� -�ļ����ı���ASCII����ʽ�洢�ڼ������
// 2.�������ļ�-�ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�����??
// �����ļ���������:
// 1. ofstream:д����
// 2. ifstream:������
// 3. fstream:��д����

// ios:in //Ϊ���ļ������ļ�
// ios:out //Ϊд�ļ������ļ�
// ios:ate//��ʼλ��:�ļ�β
// ios:.app//׷�ӷ�ʽд�ļ�
// ios::trunc//����ļ�������ɾ�����ٴ���
// ios::binary//�����Ʒ�ʽ

// ע��:�ļ��򿪷�ʽ�������ʹ�ã�����|����
// ����:�ö����Ʒ�ʽд�ļ�
// ios: :binary|ios:: out
//д�ļ� 
void test01(){
    //1�� ����ͷ�ļ�fstream
    
    ofstream ofs;//2�� ����������
    ofs.open("text.txt",ios::out);//3��ָ���򿪷�ʽ
    ofs << "����������" << endl;//4�� д����
    ofs << "�Ա���" << endl;
    ofs << "���䣺18" << endl;
    ofs.close();//5���ر��ļ�
}
//�ܽ�:
//�ļ������������ͷ�ļ�fstream
//���ļ���������ofstream ,����fstream��
//���ļ�ʱ����Ҫ֬�������ļ���·�����Լ��򿪷�ʽ������<<�������ļ���д����
//������ϣ�Ҫ�ر��ļ�

//���ļ� 
void test02(){
	ifstream ifs;//2.����������
	ifs.open("text.txt",ios::in);//3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
	if(!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return; 
	}
	//4.������
//	//��һ�� 
//	char buf[1024] = {0};
//	while(ifs >> buf)
//		cout << buf << endl;
//	//�ڶ���
//	char buf[1024] = {0};
//	while(ifs.getline(buf,sizeof(buf)))
//		cout << buf << endl;
//	//������
//	string buf;
//	while(getline(ifs,buf)) 
//		cout << buf << endl;
	//������
	char c;
	while( (c = ifs.get()) != EOF) 
		cout << c;
	//5.�ر��ļ�
	ifs.close();	
}

//�Զ����Ƶķ�ʽ���ļ����ж�д����
//�򿪷�ʽҪָ��Ϊios::binary 
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ��:ostream& write(const char * buffer,int len) ;
//��������:�ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

//�������ļ� д�ļ� 
class Person{
public:
	char m_name[64];
	int m_age;
};
void test03(){
//    ofstream ofs;
//    ofs.open("person.txt",ios::out | ios ::binary);
    ofstream ofs("person.txt",ios::out | ios ::binary);//�ڴ��������ͬʱ���д�
	Person p = {"����",18}; 
	ofs.write((const char *)&p,sizeof(Person));//д�ļ� 
	ofs.close(); 
}


//���ļ�
//�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
//����ԭ��:istream& read(char *buffer,int len);
//��������:�ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

//�����ƶ��ļ� 
void test04(){
	ifstream ifs;
	ifs.open("person.txt",ios::in | ios::binary) ;
	if(!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return; 
	}
	Person p;
	ifs.read((char *) &p,sizeof(Person));
	cout << p.m_age << ' ' << p.m_name << endl;
	ifs.close();
}


int main(){
    test01();
    cout << endl; 
    
    test02();
    cout << endl; 
    
    test03();
    cout << endl; 
    
    test04();
    cout << endl; 
    return 0;
}
























