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
	cout<<"����������ܵ��ַ�����";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    length=strlen(enc);
    strcpy(enct,enc);
    cout<<"�����ܵ��ַ��ĸ����ǣ�"<<length;
    gl();
    system("PAUSE");
    return 0;
}
//�غ�ָ����������Կ�ֵĳ���d
void gl(void)
{
	int i,j,d,x,c;
	double Ix[16][16];
	double a,b,f=0,Iy=0,summary,ave[16];
	char encs[16][16][1500];
	char*pl;
	for(d=1;d<=15;d++)//���ַ������ν��зֶ�
	{
		for(x=1;x<=d;x++)//ͳ��ÿ���ֶε��غ�ָ��
		{
			for(i=0;i<=688;i++)//�����ַ�������Ӧ�����У���ʼ��
            {
    	        encs[d][x][i]=enc[i];
	        }
			b=0;
			for(j=97;j<=122;j++)//��26����ĸ���μ�����������
			{
				for(i=x-1;i<strlen(enc);)//�Էֶ�ÿ����ĸ���μ���
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
	for(i=1;i<=15;i++)//�����ͬdʱ���غ�ָ��
	{
		summary=0;
		cout<<"\n\n\n����Կ������Ϊd="<<i<<"ʱ���غ�ָ���ǣ�";
		for(j=1;j<=i;j++)
		{
			cout<<Ix[i][j]<<"\t";
			summary+=Ix[i][j];
		}
		ave[i]=summary/(j-1);
	}
	for(i=1;i<=15;i++)//�����ͬdʱ��ƽ���غ�ָ��
	{
		cout<<"\n��d="<<i<<"ʱ��ƽ���غ�ָ����:"<<ave[i];
	}
}
