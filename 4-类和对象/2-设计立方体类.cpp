//��ϰ����1:�����������
//�����������(Cube)
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
#include <iostream> 
using namespace std;

class Cube
{
public:
	void get_H(int H)
	{
		m_H = H;		
	}
	void get_L(int L)
	{
		m_L = L;		
	}
	void get_W(int W)
	{
		m_W = W;		
	}
	
	int getS()
	{
		return 2*(m_H*m_L + m_H*m_W + m_L*m_W);
	}
	int getV()
	{
		return m_H*m_L*m_W;
	}
private:
	int m_H;
	int m_L;
	int m_W;
};

int main(void)
{
	Cube cube;
	
	cube.get_H(4);
	cube.get_L(5);
	cube.get_W(6);
	cout << cube.getS() << endl;
	cout << cube.getV() << endl;
	return 0;
}

