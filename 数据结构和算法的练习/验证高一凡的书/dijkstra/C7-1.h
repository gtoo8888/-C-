 // c7-1.h 图的数组(邻接矩阵)存储表示
 #define INFINITY INT_MAX // 用整型最大值代替∞
 #define MAX_VERTEX_NUM 26 // 最大顶点个数
 enum GraphKind{DG,DN,UDG,UDN}; // {有向图,有向网,无向图,无向网}
 typedef struct
 {
   VRType adj; // 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否；对带权图，则为权值
   InfoType *info; // 该弧相关信息的指针(可无)
 }ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 二维数组
 struct MGraph
 {
   VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
   AdjMatrix arcs; // 邻接矩阵
   int vexnum,arcnum; // 图的当前顶点数和弧数
   GraphKind kind; // 图的种类标志
 };
