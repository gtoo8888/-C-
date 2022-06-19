#include <stdio.h>
#include <string.h>

//typedef int VRType;//没有用到，表示边的值
//typedef char InfoType; //弧相关的指针
typedef char Vertype[5];// 顶点字符串
typedef int PathMatrix[25][25];//路径矩阵
typedef int ShortTable[25];//最短距离表
enum Gkind {DG,DN,UDG,UDN}; // {有向图,有向网,无向图,无向网}

typedef struct {
	int adj;//无权图,1(是)或0(否)表；带权图，权值
} AdjMatrix[25][25]; //邻接矩阵的数组

struct MGraph {
	Vertype vexs[20];// 顶点向量
	AdjMatrix arcs;// 邻接矩阵
	int vexnum,arcunm;// 图的当前顶点数和弧数
	Gkind kind;
};//整个图的数据结构


void CreateGraph(MGraph &G);
void DisplayGraph(MGraph &G);

int main(void) {
	int i,j;
	MGraph graph;//定义整个图
	PathMatrix path;
	ShortTable distance;


	CreateGraph(graph);
	DisplayGraph(graph);

	return 0;
}

int LocateVex(MGraph G,Vertype u) { //检查输入的顶点，是不是在已有的里面
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
	
	for(i = 0; i < G.vexnum; i++) //邻接矩阵初始化
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
	printf("%d个顶点%d条边，顶点依次是：\n",G.vexnum,G.arcunm);
	for(i = 0; i < G.vexnum; i++)
		printf("%s",G.vexs[i]);

	printf("\nG.arcs.adj:\n"); // 输出G.arcs.adj
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

