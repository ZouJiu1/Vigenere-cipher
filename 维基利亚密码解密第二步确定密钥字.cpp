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
	cout<<"����������ܵ��ַ�����";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    cout<<"������������ַ�������Կ���ȣ�";
	cin>>c;
	for(d=1;d<=c;d++)//��6�ηֱ�����غϻ�ָ��
	{
		if(d==c)
		    break;
		for(x=d+1;x<=c;x++)//������һ��
		{
			for(j=0;j<26;j++)//��һ�α���0��26����
			{
				sum1=sum2=0;
				for(i=0;i<strlen(enc);i++)//����ĸת����ASCII��ֵ����ʼ��enct[]
                {
                    enct[i]=(int)enc[i];
	            }
				for(i=(x-1);i<strlen(enc);)//��ÿ��һ�μ�����ͬ����Կ�ֳ���
				{
				    enct[i]=(enct[i]+j-97)%26+97;
				    sum2++;
                    i=i+c;
			    }
				for(a=97;a<=122;a++)//��26����ĸ���μ������������غ�ָ��
				{
					f1=f2=0;
	                for(i=(x-1);i<strlen(enc);)///����һ��ÿ����ĸ���μ���
			        {
				        if(a==enct[i])
				            f2++;
				        i=i+c;
			        }
			        for(i=d-1;i<strlen(enc);)//��ǰһ��ÿ����ĸ���μ���
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
	for(d=1;d<=c;d++)//����غϻ�ָ��
	{
		if(d==c)
		    break;
		cout<<"\n\n\n��i="<<d;
		for(x=d+1;x<=c;x++)
		{
			cout<<"\nj="<<x<<"ʱ���غϻ�ָ����ֵ�ֱ�Ϊ��\n";
			for(j=0;j<26;j++)
			{
				cout<<"\t\t"<<j<<"�� "<<MI[d][x][j];
			}
		}
	}
	system("PAUSE");
	return 0;
}
