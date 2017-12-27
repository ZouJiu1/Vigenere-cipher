#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
char enc[1500];
char enct[1500];
void gl(void);
using namespace std;
int main()
{
	int length;
	cout<<"请输入待解密的字符串：";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    length=strlen(enc);
    strcpy(enct,enc);
    cout<<"待解密的字符的个数是："<<length;
    gl();
    system("PAUSE");
    return 0;
}
//重合指数法计算密钥字的长度d
void gl(void)
{
	int i,j,d,x,c;
	double Ix[16][16];
	double a,b,f=0,Iy=0,summary,ave[16];
	char encs[16][16][1500];
	char*pl;
	for(d=1;d<=15;d++)//对字符串依次进行分段
	{
		for(x=1;x<=d;x++)//统计每个分段的重合指数
		{
			for(i=0;i<=688;i++)//复制字符串到相应数组中，初始化
            {
    	        encs[d][x][i]=enc[i];
	        }
			b=0;
			for(j=97;j<=122;j++)//对26个字母依次检索计数计算
			{
				for(i=x-1;i<strlen(enc);)//对分段每个字母依次检索
				{
					if(j==encs[d][x][i])
				        f++;
				    i=i+d;
				}
				a=f*(f-1);
				b=b+f;
		        Iy+=a;
		        f=0;
			}
			Ix[d][x]=Iy/(b*(b-1));
			Iy=0;
		}
	}
	for(i=1;i<=15;i++)//输出不同d时的重合指数
	{
		summary=0;
		cout<<"\n\n\n当密钥长度设为d="<<i<<"时的重合指数是：";
		for(j=1;j<=i;j++)
		{
			cout<<Ix[i][j]<<"\t";
			summary+=Ix[i][j];
		}
		ave[i]=summary/(j-1);
	}
	for(i=1;i<=15;i++)//输出不同d时的平均重合指数
	{
		cout<<"\n当d="<<i<<"时的平均重合指数是:"<<ave[i];
	}
}
