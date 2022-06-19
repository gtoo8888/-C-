#include <iostream> 
using namespace std;

//ʵ��ͨ�ö������������ĺ���
//����Ӵ�С
//�㷨ѡ��
//����char���顢int����
template<class T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void mySort(T arr[],int len){
    for(int i = 0;i < len;i++){
        int max = i;
        for(int j = i+1 ;j < len;j++)
            if(arr[max] < arr[j])
                max = j;
        if(max != i)
            mySwap(arr[max],arr[i]);  
    }
}
template<class T>
void printArray(T arr[],int len){
    for(int i = 0;i < len;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void test01(){
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr,num);
    printArray(charArr,num);
}

void test02(){
    int intArr[] = {7,6,1,3,34,5,6,7,8};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr,num);
    printArray(intArr,num);
}


int main(){
    test01();
    test02();
    return 0;
}
