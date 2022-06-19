#include <stdio.h>
#include <string.h>

//typedef int VRType;//û���õ�����ʾ�ߵ�ֵ
//typedef char InfoType; //����ص�ָ��
typedef char Vertype[5];// �����ַ���
typedef int PathMatrix[25][25];//·������
typedef int ShortTable[25];//��̾����
enum Gkind {DG,DN,UDG,UDN}; // {����ͼ,������,����ͼ,������}

typedef struct {
	int adj;//��Ȩͼ,1(��)��0(��)����Ȩͼ��Ȩֵ
} AdjMatrix[25][25]; //�ڽӾ��������

struct MGraph {
	Vertype vexs[20];// ��������
	AdjMatrix arcs;// �ڽӾ���
	int vexnum,arcunm;// ͼ�ĵ�ǰ�������ͻ���
	Gkind kind;
};//����ͼ�����ݽṹ


void CreateGraph(MGraph &G);
void DisplayGraph(MGraph &G);

int main(void) {
	int i,j;
	MGraph graph;//��������ͼ
	PathMatrix path;
	ShortTable distance;


	CreateGraph(graph);
	DisplayGraph(graph);

	return 0;
}

int LocateVex(MGraph G,Vertype u) { //�������Ķ��㣬�ǲ��������е�����
	int i;
	for(i = 0; i < G.vexnum; i++)
		if(strcmp(u,G.vexs[i])==0)
			return i;
	return -1;
}

void CreateGraph(MGraph &G) {
	int i,j,k,w;
	Vertype va,vb;
	FILE *graphlist;

	graphlist = fopen("1.txt","r");
	fscanf(graphlist,"%d",&G.vexnum);
	fscanf(graphlist,"%d",&G.arcunm);

	for(i = 0; i < G.vexnum; i++)
		fscanf(graphlist,"%s",G.vexs[i]);
	
	for(i = 0; i < G.vexnum; i++) //�ڽӾ����ʼ��
		for(j = 0; j < G.vexnum; j++) 
			G.arcs[i][j].adj = 0;	

	for(k = 0; k < G.vexnum; k++) {
		fscanf(graphlist,"%s%s%d",va,vb,&w);
		i = LocateVex(G,va);
		j = LocateVex(G,vb);
		G.arcs[i][j].adj = 	G.arcs[j][i].adj = w;
	}
		
	fclose(graphlist);
	G.kind = UDN;
}

void DisplayGraph(MGraph &G) {
	int i,j;
	printf("%d������%d���ߣ����������ǣ�\n",G.vexnum,G.arcunm);
	for(i = 0; i < G.vexnum; i++)
		printf("%s",G.vexs[i]);

	printf("\nG.arcs.adj:\n"); // ���G.arcs.adj
	for(i=0; i<G.vexnum; i++) 
	{
		for(j=0; j<G.vexnum; j++)
		{
			printf("%3c",G.vexs[i]);
			printf("%3d",G.arcs[i][j].adj);
		}
		printf("\n");
	}

}

