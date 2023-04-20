#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// #include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

int SegmentTree[2000001];
int arr[500001] ={0};
// 线段树的主要作用是维护区间信息，比如区间最大值、最小值、区间和等
// 线段树可以实现 O (log n) 的区间修改和区间查询，比普通的数组更高效
// 线段树是一种平衡二叉树，可以用数组或链表来表示。
// https://www.luogu.com.cn/problem/P3374
// 主要作用：区间修改和区间查询


// vector<int> arr = {1,5,4,2,3};
// vector<int> SegmentTree = {0,15,10,5,6,4,2,3,1,5};
// 数组arr对应的线段树SegmentTree
// 1, 2,3,4,5,6,7,8,9
// 15|10 5|6 4 2 3|1 5
// 分别表示每个完全二叉树对应的值,最下面一层表示的是arr的值
// 每上升一层，表述下面两层的和
//             1[15]
//         2[10]    3[5]
//     4[6]   5[4] 6[2]    7[3]
//  8[1]   9[5]



// 已知二叉树的节点数量，求二叉树高度
int GetTreeHeight(int n){
    return ceil(log2(n+1)) - 1;// log2(n+1)表示的是最底层的节点数
}
// int GetTreeHeight(int n){
//     int h = 0;
//     while(n > 0){
//         n = n >> 1;
//         h++;
//     }
//     return h;
// }




// 输出以数组形式存储的二叉树(一般存储完全二叉树)
void PrintVTree(vector<int> v){
    int n = v.size();
    int h = ceil(log2(n+1)) - 1; // log2(n+1)表示求二叉树高度
    vector<int> tree_num(h,1); 
    for(int i = 1;i < h;i++){ // 每层有多少个节点
        tree_num[i] = tree_num[i-1] * 2;
    }
    for(int i = 1;i < h;i++){ // 累加起来，要在哪里分割
        tree_num[i] += tree_num[i-1];
    }
    int tree_index = 0;
    for(int i = 0;i < n;i++){
        if(i == tree_num[tree_index]){
            cout << v[i] << "|";
            tree_index++;
        }else{
            cout << v[i] << " ";
        }
    }
    cout << endl;
}

// root: 根节点，当前的节点的值
// left: 左边界
// right: 右边界
// arr: 原数组
// 线段树的建树过程
void buildtree(int root,int left,int right){
    if(left == right){
        SegmentTree[root] = arr[left]; // 这里是给最底层的树赋值
        return;
    }
    int mid = (left + right) >> 1; // 取中点
    buildtree(2*root,left,mid); // 递归的求解左右子树
    buildtree(2*root+1,mid+1,right);
    SegmentTree[root] = SegmentTree[2*root] + SegmentTree[2*root+1];// 每上升一层，等于下面两层的和
}

// 单点修改
void STree_add(int root,int left,int right,int x,int add_num){
    SegmentTree[root] += add_num;
    if(left == right){
        return;
    }
    int mid = (left + right) >> 1;
    if(x <= mid){
        STree_add(2*root,left,mid,x,add_num);
    }else{
        STree_add(2*root+1,mid+1,right,x,add_num);
    }
}

// 区间和查询
// 如果递归到单点，cal(5,3,3,3,3),cal(9,2,2,2,2)这种时候才返回
// 如果递归到区间，cal(3,4,5,4,5),将区间结果返回
int STree_cal(int root,int left,int right,int x,int y){
    // printf("root:%d left:%d right:%d x:%d y:%d\n",root,left,right,x,y);
    if(left == x && right == y){
        return SegmentTree[root];
    }
    int mid = (left + right) >> 1;
    if(y <= mid)
        return STree_cal(2*root,left,mid,x,y);
    else{
        if(x > mid)
            return STree_cal(2*root+1,mid+1,right,x,y);
        else
            return STree_cal(2*root,left,mid,x,mid) + STree_cal(2*root+1,mid+1,right,mid+1,y);
    }
}


// 用vector,洛谷中会超时
// 需要把所有数组都改成普通数组
// 5 5
// 1 5 4 2 3
// 1 1 3
// 2 2 5
// 1 3 -1
// 1 4 2
// 2 1 4
int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    // SegmentTree = vector<int>(4*(n-1),0);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    // 三个参数，第一个参数是根节点，第二个参数是左边界，第三个参数是右边界
    // 按照完全二叉树的形式建立的
    buildtree(1,1,n);
    // PrintVTree(SegmentTree);
    while(m--){
        int type,x,add_num;
        scanf("%d%d%d",&type,&x,&add_num);
        if(type == 1){
            // printf("x:%d,add_num:%d\n",x,add_num);
            STree_add(1,1,n,x,add_num);
            // PrintVTree(SegmentTree);
        }else{
            int y = add_num;
            // PrintVTree(SegmentTree);
            // printf("x:%d,y:%d\n",x,y);
            printf("%d\n",STree_cal(1,1,n,x,y));
        }
    }
    

	return 0;
}



