#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
using namespace std;
char enc[1500];
int enct[1500];
double MI[10][10][26];
int main()
{
	int i,j,length,d,x,a,sum1,sum2,f1,f2,c;
	double Mi;
	cout<<"请输入待解密的字符串：";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    cout<<"请输入待解密字符串的密钥长度：";
	cin>>c;
	for(d=1;d<=c;d++)//对6段分别计算重合互指数
	{
		if(d==c)
		    break;
		for(x=d+1;x<=c;x++)//遍历另一段
		{
			for(j=0;j<26;j++)//另一段遍历0到26计算
			{
				sum1=sum2=0;
				for(i=0;i<strlen(enc);i++)//把字母转换成ASCII码值，初始化enct[]
                {
                    enct[i]=(int)enc[i];
	            }
				for(i=(x-1);i<strlen(enc);)//对每另一段加上相同的密钥字长度
				{
				    enct[i]=(enct[i]+j-97)%26+97;
				    sum2++;
                    i=i+c;
			    }
				for(a=97;a<=122;a++)//对26个字母依次检索计数计算重合指数
				{
					f1=f2=0;
	                for(i=(x-1);i<strlen(enc);)///对另一段每个字母依次检索
			        {
				        if(a==enct[i])
				            f2++;
				        i=i+c;
			        }
			        for(i=d-1;i<strlen(enc);)//对前一段每个字母依次检索
			        {
			    	    if(a==enct[i])
				            f1++;
				        i=i+c;
				    }
				    sum1=sum1+f1;
				    Mi=(f1*f2)+Mi;
			    }
			    MI[d][x][j]=Mi/(sum1*sum2);
			    Mi=0;
		   }
		}
	}
	for(d=1;d<=c;d++)//输出重合互指数
	{
		if(d==c)
		    break;
		cout<<"\n\n\n当i="<<d;
		for(x=d+1;x<=c;x++)
		{
			cout<<"\nj="<<x<<"时，重合互指数的值分别为：\n";
			for(j=0;j<26;j++)
			{
				cout<<"\t\t"<<j<<"： "<<MI[d][x][j];
			}
		}
	}
	system("PAUSE");
	return 0;
}
