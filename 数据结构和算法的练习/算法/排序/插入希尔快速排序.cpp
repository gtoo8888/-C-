
#include<iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
#include <stack>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void Insert_Sort(vector<int> &num){
    for (int j = 1; j < num.size(); j++){
        // 从第二个元素开始遍历
        int key = num[j]; //待排序第一个元素
        int i = j - 1;  //代表已经排过序的元素最后一个索引数
        // printf("%d %d %d\n",key,j,i);
        while (i >= 0 && key < num[i]){
            //从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
            //其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
            num[i + 1] = num[i];
            i--;
        }
        num[i + 1] = key;//找到合适的位置了，赋值,在i索引的后面设置key值。
        // PrintVector(num);
    }
}

// 希尔排序:先追求表中元素部分有序，再逐渐逼近全局有序

void Shell_Sort1(vector<int> &num){
    // gap为步长，每次减为原来的一半。
    for (int gap = num.size() / 2; gap > 0; gap /= 2){
        // 共gap个组，对每一组都执行直接插入排序
        for (int i = 0 ;i < gap; i++)
            for (int j = i + gap; j < num.size(); j += gap) 
                // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
                if (num[j] < num[j - gap]){
                    int tmp = num[j];
                    int k = j - gap;
                    while (k >= 0 && num[k] > tmp){
                        num[k + gap] = num[k];
                        k -= gap;
                    }
                    num[k + gap] = tmp;
                }
        // PrintVector(num);
    }
}

void QSort(vector<int> &arry, int low, int size)
{
	int high = size-1;
	if(low<high)
	{
		int x = arry[low];  //取第一个数据元素为枢纽元素，则该位置空出来 
		int index = low;    //记录空出来的位置 
		while(low<high)
		{
			while(arry[high]>=x&&high>low)  //从后往前寻找比枢纽元素小的元素 
	        {
	        	high--;
			}
			arry[index] = arry[high];  //找到比枢纽元素小的元素后将其补充到空位中，出现了一个新的空位 
			index = high;
			
			while(arry[low]<=x&&high>low)  //从前往后寻找比枢纽元素大的元素 
			{
				low++;
			}
			arry[index] = arry[low];  //找到比纽元素大的元素后将其补充到空位中，出现了一个新的空位 
			index = low;
		}
		arry[low] = x;
		QSort(arry,0, index);  //对枢纽元素左半部分和右半部分分别进行快速排序 
		QSort(arry,index+1,size);
	}
}


vector<int> Create_Vector(int rand_n,int rand_scope){
    // vector<int> num = {49, 38 , 65, 97, 78, 13, 27, 49};
    // vector<int> num;
    vector<int> num(rand_n);

    srand((unsigned)time(NULL));
    // for(int i = 0;i < rand_n;i++)
    for(int i = 0;i < rand_n;i++)
        // num.push_back(rand()%rand_scope);
        // num.push_back(rand() & (rand_scope - 1));
        // num[i] = rand()%rand_scope;
        num[i] = rand() & (rand_scope - 1);
        
    return num;
}


int PartSort(vector<int> &pArray, int nLeft, int nRight)
{
    int nKey = pArray[nLeft];
    while (nLeft < nRight)
    {
        while (pArray[nRight] >= nKey && nRight > nLeft)
        {
            nRight--;
        }
        pArray[nLeft] = pArray[nRight];
        while (pArray[nLeft] < nKey && nLeft < nRight)
        {
            nLeft++;
        }
        pArray[nRight] = pArray[nLeft];
    }
    pArray[nLeft] = nKey;
    return nLeft;
}

void QuickSortRecursion(vector<int> &pArray, int nLeft, int nRight)
{
	if (nLeft >= nRight)
	{
		return;
	}
 
    int nMid = PartSort(pArray, nLeft, nRight);
    QuickSortRecursion(pArray, nLeft, nMid - 1);
    QuickSortRecursion(pArray, nMid + 1, nRight);
}


void QuickSortUnrecursion(vector<int> &pArray, int nLeft, int nRight)
{
	if (nLeft >= nRight)
	{
		return;
	}
    stack<int> stackIndex;
    stackIndex.push(nLeft);
    stackIndex.push(nRight);
    int nBegin = 0;
    int nEnd = 0;
    int nMid = 0;
    while (!stackIndex.empty())
    {
        nEnd = stackIndex.top();
        stackIndex.pop();
        nBegin = stackIndex.top();
        stackIndex.pop();
        nMid = PartSort(pArray, nBegin, nEnd);
        if (nBegin < nMid - 1)
        {
            stackIndex.push(nBegin);
            stackIndex.push(nMid - 1);
        }
        if (nEnd > nMid + 1)
        {            
            stackIndex.push(nMid + 1);
            stackIndex.push(nEnd);
        }
    }
}
 
// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点
 
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;
 
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
// 堆排序
void heapSort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}


void Test_Shell(int rand_n,int rand_scope,int test_n){
    for(int i = 0;i < test_n;i++){
        vector<int> num = Create_Vector(rand_n,rand_scope);
        clock_t start,end;  //定义clock_t变量
        start = clock();  
        Shell_Sort1(num);
        end = clock(); 
        cout<<"Shell time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;  
        num.clear();
    }
}

void Test_QuickSort(int rand_n,int rand_scope,int test_n){
    clock_t start,end; 
    for(int i = 0;i < test_n;i++){
        start = clock();
        vector<int> num = Create_Vector(rand_n,rand_scope);
        end = clock(); 
        cout<<"create time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl; 
        start = clock();  
        // QuickSortUnrecursion(num,0,num.size());
        end = clock(); 
        cout<<"QuickSort time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;  
        num.clear();
    }
}


void Test_heapSort(int rand_n,int rand_scope,int test_n){
    for(int i = 0;i < test_n;i++){
        vector<int> num = Create_Vector(rand_n,rand_scope);
        clock_t start,end; 
        start = clock();  
        heapSort(num, num.size());
        end = clock(); 
        cout<<"heapSort time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;  
        num.clear();
    }
}

int main(void) {

    int rand_n = 1000;
    int rand_scope = 1000;
    int test_n = 2;


    // Test_Shell(rand_n,rand_scope,test_n);
    // Test_QuickSort(rand_n,rand_scope,test_n);
    // Test_heapSort(rand_n,rand_scope,test_n);

    // vector<int> num = Create_Vector(rand_n,rand_scope);
    // PrintVector(num);

    // clock_t start,end; 
    // start = clock();  
    // Insert_Sort(num);
    // Shell_Sort1(num);
    // QSort(num,0,num.size());
    // QuickSortRecursion(num,0,num.size());
    // QuickSortUnrecursion(num,0,num.size());
    // heapSort(num, num.size());//len = 11, 但是约定 a[0] 不存值, 有意义的值从 a[1] 开始
    // end = clock(); 

    // PrintVector(num);
    // cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;  //输出时间（单位：ｓ）
    return 0;
}






















































































































