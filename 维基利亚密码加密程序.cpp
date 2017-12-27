#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
char enc[1500];
char enct[1500];
using namespace std;
class Third
{
private:
    int f[16];
	int i,c,a;
public:
    void choiceK(void)
    {
        cout<<"\n加密该字符串时的密钥形式，例如：（16，13，6，......）"<<endl;
        cout<<"请输入加密时密钥的长度：";
        cin>>c;
        cout<<"请依次输入密钥f[i]的值（0-26以内）"<<endl;
        for(i=0;i<c;i++)
        {
            cout<<"f["<<i<<"]=";
            cin>>f[i];
        }
        for(i=0;i<strlen(enc);i++)//把字母转换成ASCII码值，初始化enct[]
        {
            enct[i]=(int)enc[i];
        }
        for(i=0;i<strlen(enc);)//对明文加上对应的的密钥长度
        {
            for(a=0;a<c;a++)
            {
                enct[i+a]=(enct[i+a]+f[a]%26-71)%26+97;
            }
            i=i+c;
        }
        cout<<"\n\n加密后的字符串是：\n";
        for(i=0;i<strlen(enc);i++)//输出加密后的字符串
        {
            cout<<(char)enct[i];
        }
        cout<<"\n加密已经完成，按下Enter键可以退出程序！";
    }
};
int main()
{
	Third Thi;
	cout<<"请输入待加密的字符串：";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    cout<<"待加密的字符的个数是："<<strlen(enc);
    Thi.choiceK();
    system("PAUSE");
    return 0;
}
