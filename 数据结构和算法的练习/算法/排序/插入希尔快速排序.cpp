
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
        // �ӵڶ���Ԫ�ؿ�ʼ����
        int key = num[j]; //�������һ��Ԫ��
        int i = j - 1;  //�����Ѿ��Ź����Ԫ�����һ��������
        // printf("%d %d %d\n",key,j,i);
        while (i >= 0 && key < num[i]){
            //�Ӻ���ǰ����Ƚ��Ѿ���������飬�������С����Ѻ�����ǰ�ߴ��棬
            //��ʵ˵���˾�������������ƶ�һλ,Ϊ�ҵ����ʵ�λ��ʱ�����Key�Ĳ���
            num[i + 1] = num[i];
            i--;
        }
        num[i + 1] = key;//�ҵ����ʵ�λ���ˣ���ֵ,��i�����ĺ�������keyֵ��
        // PrintVector(num);
    }
}

// ϣ������:��׷�����Ԫ�ز����������𽥱ƽ�ȫ������

void Shell_Sort1(vector<int> &num){
    // gapΪ������ÿ�μ�Ϊԭ����һ�롣
    for (int gap = num.size() / 2; gap > 0; gap /= 2){
        // ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for (int i = 0 ;i < gap; i++)
            for (int j = i + gap; j < num.size(); j += gap) 
                // ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
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
		int x = arry[low];  //ȡ��һ������Ԫ��Ϊ��ŦԪ�أ����λ�ÿճ��� 
		int index = low;    //��¼�ճ�����λ�� 
		while(low<high)
		{
			while(arry[high]>=x&&high>low)  //�Ӻ���ǰѰ�ұ���ŦԪ��С��Ԫ�� 
	        {
	        	high--;
			}
			arry[index] = arry[high];  //�ҵ�����ŦԪ��С��Ԫ�غ��䲹�䵽��λ�У�������һ���µĿ�λ 
			index = high;
			
			while(arry[low]<=x&&high>low)  //��ǰ����Ѱ�ұ���ŦԪ�ش��Ԫ�� 
			{
				low++;
			}
			arry[index] = arry[low];  //�ҵ���ŦԪ�ش��Ԫ�غ��䲹�䵽��λ�У�������һ���µĿ�λ 
			index = low;
		}
		arry[low] = x;
		QSort(arry,0, index);  //����ŦԪ����벿�ֺ��Ұ벿�ֱַ���п������� 
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
 
// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index�����ӽڵ�
    int right = 2*index + 2;// index�����ӽڵ�
 
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;
 
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
// ������
void heapSort(vector<int> &arr, int size)
{
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    // ���������
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
        adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
    }
}


void Test_Shell(int rand_n,int rand_scope,int test_n){
    for(int i = 0;i < test_n;i++){
        vector<int> num = Create_Vector(rand_n,rand_scope);
        clock_t start,end;  //����clock_t����
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
    // heapSort(num, num.size());//len = 11, ����Լ�� a[0] ����ֵ, �������ֵ�� a[1] ��ʼ
    // end = clock(); 

    // PrintVector(num);
    // cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;  //���ʱ�䣨��λ����
    return 0;
}






















































































































