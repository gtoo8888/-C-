#include <iostream>
#include <vector>                                                                //��̬���鱣��������������
using std::cin;
using std::cout;
using std::endl;
using std::vector;
#define max 100
 
/*�ڽӾ����㷨*/	
/*˼·����ʼ�������붥����ϵ���й�ϵ�Ĵ�ʼ�㵽�յ�Ϊ1��ѭ����⣬��ȫΪ���һ��������󽫾�����ض����
ż����Ϊ�㣬Ȼ��ѭ����飬�������ȫ�����㣬����������붥������ͬ����˵���л�*/
int main() {
	int vertexnum=0,edgenum=0;
	int i=0,j=0,count=0;	
	vector<int>order;							//��̬����order���ڴ��������������� 
	int edge[max][max];
	int visit[max];
	cout<<"�����붥�����ͱ���"<<endl;
	cin>>vertexnum>>edgenum;		
	for(i=0;i<vertexnum;i++){						//��ʼ�� 
		for(j=0;j<vertexnum;j++)
			edge[i][j]=0;	
		visit[i]=0;
	}
	while(edgenum--)						        //��ʼ�������Ĺ�ϵ 
	{
		cout<<"�����붥��i��j��i��ʾʼ�㣬j��ʾ�յ㣩:"<<endl;
		cin>>i>>j;
		edge[i][j]=1;
	}
	cout<<"��ÿ������Ϊ���ȵ��ڽӾ����ʾΪ��"<<endl; 
	cout<<'\t';
	for(i=0;i<vertexnum;i++)						//�����ʼ������ڽӾ��� ���ڽӾ���ÿһ�д�����һ������Ϊ���ȣ�������������Ĺ�ϵ�� 
		cout<<i<<'\t';
	cout<<endl;
	for(i=0;i<vertexnum;i++){			
		cout<<i<<'\t';
		for(j=0;j<vertexnum;j++)
		{
			cout<<edge[i][j]<<'\t';	
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"��ÿ������Ϊ��ȵ��ڽӾ����ʾΪ��"<<endl;
	cout<<'\t';
	for(i=0;i<vertexnum;i++)						//�����ʼ������ڽӾ��� ���ڽӾ���ÿһ�д�����һ������Ϊ���ȣ�������������Ĺ�ϵ�� 
		cout<<i<<'\t';
	cout<<endl;
	for(i=0;i<vertexnum;i++){			
		cout<<i<<'\t';
		for(j=0;j<vertexnum;j++)
		{
			cout<<edge[j][i]<<'\t';	
		}
		cout<<endl;
	}
	int targetVertex,check,judge=0;
	for(i=0;i<vertexnum;i++)						//��ѭ���������������Ķ��� 
	{	
		for(targetVertex=0;targetVertex<vertexnum;targetVertex++)	
		{
			for(j=0;j<vertexnum;j++)
			{
				if(targetVertex==j)				//���������������������������䲻���ڹ�ϵ�� 
					continue;
				if(visit[targetVertex]||edge[j][targetVertex])	//��kΪ��������������kΪ��ȵıߴ��� 
				{
					judge=1;				// �����ֵ��Ϊ1���������ֱ������ 
					break;
				}
			}	
			if(judge)						//������judgeΪ1��������������������������˴�ѭ������Ϊ�Ѿ���������������Ϊ1�������� 
			{	
				judge=0;					//����ʼ��judgeֵ�������´��ж� 
				continue;
			}
			else							//����Ϊδ��������Ϊ��Ķ��� 
			{
				order.push_back(targetVertex);			//���������������� 
				count++;
				visit[targetVertex]=1;				//����Ϊ����� 
				break;						//���� 
			}
		}
		for(check=0;check<vertexnum;check++)		                //��������k����Ϊ���ȵ���ر���Ϊ0����ɾ��k��	
			edge[targetVertex][check]=0;
		judge=0;							//�ж�ֵ��ʼ�� 
	}
	if(count!=vertexnum)
		cout<<"ͼ�д��ڻ��������������������Ϊ��"<<endl;
	else
		cout<<"�������������Ϊ��"<<endl;
	for(i=0;i<order.size();i++)					        //�����������  
	{
		cout<<order[i]<<'\t';
	}
	return 0;
}