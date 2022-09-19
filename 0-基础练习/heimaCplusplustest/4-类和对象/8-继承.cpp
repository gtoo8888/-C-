#include <iostream>
using namespace std;
// ���Ƿ��֣�������Щ��ʱ���¼���ĳ�Ա����ӵ����һ���Ĺ��ԣ������Լ������ԡ�
// ���ʱ�����ǾͿ��Կ������ü̳еļ����������ظ�����
class Java{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "JAVA" << endl;
    }
};

class Python{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "Python" << endl;
    }
};

class CPP{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "CPP" << endl;
    }
};

void test01(){
    cout << "java page" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "---------------------" << endl;
    cout << "Python page" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "---------------------" << endl;
    cout << "CPP page" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

class BasePage{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    } 
};

// ���Ƿ��֣�������Щ��ʱ���¼���ĳ�Ա����ӵ����һ���Ĺ��ԣ������Լ������ԡ�
// ���ʱ�����ǾͿ��Կ������ü̳еļ����������ظ�����5
//�̳еĺô�: �����ظ�����
//�﷨: class ����:�̳з�ʽ ����
//���� Ҳ��Ϊ ������
//���� Ҳ��Ϊ����

class Java2:public BasePage{
public:
    void content(){
        cout << "Java2" << endl;
    }
};
class Python2:public BasePage{
public:
    void content(){
        cout << "python2" << endl;
    }
};
class CPP2:public BasePage{
public:
    void content(){
        cout << "CPP2" << endl;
    }
};

void test02(){
    cout << "java page" << endl;
    Java2 ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "---------------------" << endl;
    cout << "Python page" << endl;
    Python2 py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "---------------------" << endl;
    cout << "CPP page" << endl;
    CPP2 cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

//�̳з�ʽһ��������:
class Base1{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;		
};
//�����̳�
class Son1:public Base1{
public:
	void func(){
		m_a = 10;//�����еĹ���Ȩ�޳�Ա�� ��������Ȼ�ǹ���Ȩ��
		m_b = 10;//�����еı���Ȩ�޳�Ա�� ��������Ȼ�Ǳ���Ȩ��;
//		m_c = 10;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
//�����̳�
class Son2:protected Base1{
public:
	void func(){
		m_a = 10;//�����й�����Ա���������б�Ϊ����Ȩ��
		m_b = 10;//�����б�����Ա���������б�Ϊ����Ȩ��
//		m_c = 10;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
//˽�м̳�
class Son3:private Base1{
public:
	void func(){
		m_a = 10;//�����й�����Ա���������б�Ϊ˽��Ȩ��
		m_b = 10;//�����б�����Ա���������б�Ϊ˽��Ȩ��
//		m_c = 10;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
class GrandSon3:public Son3{
public:
	void func(){
//		m_a = 1000;
//		m_b = 1000;
	}
};

void test03(){
	Son1 s1;
	s1.m_a = 100;
	//s1.m_b = 100;//��Son1��m_B�Ǳ���Ȩ��������ʲ���
	
	Son2 s2;
	//s2.m_a = 1000;//��Son2�� m_A��Ϊ����Ȩ�ީo���������ʲ���
	//s2.m_b = 1000;//��Son2�� m_B����Ȩ�޲����Է���

	Son2 s3;
	//s3.m_a = 1000;//��Son3�� m_A��Ϊ˽�г�Ա ���ⲻ���Է���
	//s3.m_b = 1000;//��Son3�� m_B��Ϊ˽�г�Ա ���ⲻ���Է���
} 

//����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
//����:���������Ĺ��������˳����˭��˭��?
class Base2{
public:
	Base2(){
		cout << "Base2 �Ĺ��캯��" << endl; 
	}
	~Base2(){
		cout << "Base2 ����������" << endl; 
	}
};

class Son10:public Base2{
public:
	Son10(){
		cout << "Son10 �Ĺ��캯��" << endl; 
	}
	~Son10(){
		cout << "Son10 ����������" << endl; 
	}
};
void test04(){
	//�̳��еĹ��������˳������:
	//�ȹ��츸�࣬�ٹ�������,������˳���빹���˳���෴
	Base2 b; 
	cout << endl;
	Son10 s;
} 


//�̳�ͬ����Ա����ʽ
//����:�������������ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ����������ͬ����������?
//��������ͬ����Աֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա��Ҫ��������
class Base3{
public:
	Base3(){
		m_a = 100;
	}
	void func(){
		cout << "Base3 - func()����" << endl; 
	}
	void func(int a){
		cout << "Base3 - func(int a)����" << endl; 
	}
	int m_a;
};
class Son20 :public Base3{
public:
	Son20(){
		m_a = 200;
	}
	void func(){
		cout << "Son - func()����" << endl; 
	}
	int m_a;
};

void test05(){
	Son20 s;
	cout << s.m_a << endl;
	cout << s.Base3::m_a << endl;//���ͨ�����������ʵ�������ͬ����Ա����Ҫ��������
} 
void test06(){
	Son20 s;
	s.func();//ֱ�ӵ��õ����������е�ͬ����Ա
	s.Base3::func();//��ε��õ�������ͬ����Ա����?
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	s.Base3::func(100);
} 
//�ܽ�:
//1.����������ֱ�ӷ��ʵ�������ͬ����Ա
//2.����������������Է��ʵ�����ͬ����Ա
//3.�������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������


//�̳�ͬ����̬��Ա����ʽ
//����:�̳���ͬ���ľ�̬��Ա�������������ν��з���?
//��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
//��������ͬ����Աֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա��Ҫ��������
class Base4{
public:
	static int m_a;
	
	static void func(){
		cout << "Base4 - static void func()" << endl;
	} 
	static void func(int a){
		cout << "Base4 - static void func(int a)" << endl;
	} 
};
int Base4::m_a = 100;

class Son30:public Base4{
public:
	static int m_a;
	
	static void func(){
		cout << "Son30 - static void func()" << endl;
	}
};
int Son30::m_a = 200;

void test07(){
	cout <<"ͨ���������:"<< endl;
	Son30 s;
	cout << "Son30 ��m_a = " << s.m_a << endl;
	cout << "Base4  ��m_a = " << s.Base4::m_a << endl;
	
	cout <<"ͨ����������:" << endl;
	cout << "Son30 ��m_A = "  << Son30::m_a << endl ;
	//��һ��::����ͨ��������ʽ���� �ڶ���::������ʸ�����������
	cout << "Base4 �� m_A = " << Son30::Base4::m_a<< endl;	
} 

void test08(){
	cout <<"ͨ���������:"<< endl;		
	Son30 s;
	s.func();
	s.Base4::func();
	
	cout <<"ͨ����������:" << endl;
	Son30::func();
	Son30::Base4::func();
	//������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
	//�������ʸ����б�����ͬ����Ա����Ҫ��������[
	Son30::Base4::func(10);
}
//�ܽ�:ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ(ͨ�������ͨ������)

//��̳��﷨
//C++����һ����̳ж����
//��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
//C++ʵ�ʿ����в������ö�̳�
class Base5{
public:
	Base5(){
		m_a = 100;
	}
	int m_a;
};

class Base6{
public:
	Base6(){
		m_a = 200;
	}
	int m_a;
};

//������Ҫ�̳�Base1��Base2 I
//�﷨:class���� : �̳з�ʽ ����1,�̳з�ʽ ����2 ..... 
class Son40:public Base5,public Base6{
public:
	Son40(){
		m_c = 300;
		m_d = 400;
	}
	int m_c;
	int m_d;
};

void test09(){
	Son40 s;
	cout << sizeof(s) << endl;
	//�������г���ͬ����Ա����Ҫ������������
	cout << s.Base5::m_a << endl;
	cout << s.Base6::m_a << endl;
}

//���μ̳и���:
//����������̳�ͬһ������
//����ĳ����ͬʱ�̳�������������
//���ּ̳б���Ϊ���μ̳У�������ʯ�̳�


int main(){
    test01();
    cout << endl;

    test02();
    cout << endl;
    
    test03();
    cout << endl;
    
    test04();
    cout << endl;
    
    test05();
    test06();
    cout << endl;
    
    test07();
    test08();
    cout << endl;
    
    test09();
    cout << endl;
    return 0;
}



















