/*根据第二步求得:K1-K2=16,K1-K3=10,K1-K4=3,K1-K5=7,K1-K6=23
所以密钥字的可能形式为：（K1，K1+10，K1+16,K1+23,K1+19,K1+3）*/
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
using namespace std;
char enc[1500];
int enct[1500];
int K[26][6];
int main()
{
	int i,j,x,c;
	cout<<"请输入待解密的字符串：";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    cout<<"请输入待解密字符串的密钥长度：";
	cin>>c;
	for(j=0;j<26;j++)//遍历26个数字，
	{
	    for(i=0;i<strlen(enc);i++)//把字母转换成ASCII码值，初始化enct[]
        {
            enct[i]=(int)enc[i];
	    }
		for(i=0;i<strlen(enc);)//对每另一段加上相同的密钥字长度
		{
			enct[i]=(enct[i]-(j%26)-71)%26+97;
			enct[i+1]=(enct[i+1]-((j+10)%26)-71)%26+97;
			enct[i+2]=(enct[i+2]-((j+16)%26)-71)%26+97;
			enct[i+3]=(enct[i+3]-((j+23)%26)-71)%26+97;
			enct[i+4]=(enct[i+4]-((j+19)%26)-71)%26+97;
			enct[i+5]=(enct[i+5]-((j+3)%26)-71)%26+97;
            i=i+c;
		}
	    cout<<"\n\n当K1="<<j<<"时,解密后的字符串是：\n";
	    for(i=0;i<strlen(enc);i++)//输出解密后的字符串
	    {
	    	cout<<(char)enct[i];
		}
	}
	system("PAUSE");
	return 0;
}
