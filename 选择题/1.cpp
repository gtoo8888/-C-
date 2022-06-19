#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;



typedef enum
{
    Char ,
    Short,
    Int,
    Double,
    Float,
    T,
    T2,
    T3,
    T4,
    T5,
    T6,
    T7,
}TEST_TYPE;


int main ()
{
    if(0){
        string a,b;
        // cin>>a>>b; 
        a = "ATTTAA";
        b = "TTAATT";
        string a1(a.size(),' '),b1(a.size(),' ');
        // cout << a1 << endl;
        int a_num=0;
        for(int i = 0;i < a.size();i++) {
            
            if(a[i] == b[i])
                continue;
            else{
                a1[a_num] = a[i];
                b1[a_num] = b[i];
                // cout << a1[a_num] << " " << b1[a_num] << endl;
                a_num++;
            }
        }

        int a1_A=0,a1_T=0;
        for(int i = 0;i < a1.size();i++) {
            if(a1[i] == 'A') a1_A++;
            if(a1[i] == 'T') a1_T++;
        }
        int b1_A=0,b1_T=0;
        for(int i = 0;i < b1.size();i++) {
            if(b1[i] == 'A') b1_A++;
            if(b1[i] == 'T') b1_T++;
        }
    // cout << a1_A << " " << a1_T << endl;
    // cout << b1_A << " " << b1_T << endl;
        int res2 = max(a1_A,a1_T);   
        int res1 = max(b1_A,b1_A);
        int ans = max(res1,res2);

        printf("%d",ans);


        char p1[10] = "abcd", *p2, str[10] = "xyz";  
        // p2 = "ABCD";
        // cout << p1 + 2 << endl;
        // cout << p2 + 1 << endl;
        // cout << strcat(p1 + 2, p2 + 1) << endl;
        // cout << str + 2 << endl;
        strcpy(str + 2, strcat(p1 + 2, p2 + 1));
        printf(" %s", str);

        TEST_TYPE val;  //枚举类型不管多大都是int大小，是4
        cout<< sizeof(val)<<endl;
        cout << Char << endl;

        int i;
        for(i=0;i<5;i++)
            int a = 0;
        cout << i << endl;

    }


    char ch;
    ofstream file2("test.txt",ios::binary);//以二进制方式打开
    file2<<"一二三";
    file2.seekp(ios::beg);  //对输入流进行重定向
    file2<<"四";
    file2.close();

}
