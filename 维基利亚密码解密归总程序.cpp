#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
char enc[1500];
char enct[1500];
using namespace std;
//�غ�ָ����������Կ�ֵĳ���d
class First
{
private:
    int i,j,d,x,c,e,fre;
    double a,b,f=0,Iy=0,summary;
    char*pl;
public:
    int gl(void)
    {
        cout<<"\n����Ҫ�ּ��Σ�������20���ڣ�������30����";
        cin>>fre;
        char encs[fre+1][fre+1][1500];
        double Ix[fre+1][fre+1],ave[fre+1];
        for(d=1;d<=fre;d++)//���ַ������ν��зֶ�
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
        for(i=1;i<=fre;i++)//�����ͬdʱ���غ�ָ��
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
        for(i=1;i<=fre;i++)//�����ͬdʱ��ƽ���غ�ָ��
        {
            cout<<"\n��d="<<i<<"ʱ��ƽ���غ�ָ����:"<<ave[i];
        }
        cout<<"\n\n\n\t\t�Աȷֳɲ�ͬ�ε��غ�ָ�������Եõ���Կ���ȡ�"<<endl;
        cout<<"��������Կ���ȣ�";
        cin>>e;
        return e;
    }
};
class Second
{
private:
    double MI[26][26][26],Mi;
	int i,j,length,d,x,a,sum1,sum2,f1,f2,c;
public:
    void MIi(int c)
    {
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
    }

};
class Third
{
private:
    int K[26][6],f[16];
	int i,j,x,c,a;
public:
    void choiceK(int c)
    {
        cout<<"\n\n\n\t\tͨ��������������Լ���õ���Կ�ֿ��ܵ���ʽ��K1��K1+f[1]��K1+f[2],K1+f[3],K1+f[4],K1+f[5],......��"<<endl;
        cout<<"����������f[i]��ֵ��Ĭ��f[0]=0��"<<endl;
        for(i=1;i<c;i++)
        {
            cout<<"f["<<i<<"]=";
            cin>>f[i];
        }
	    for(j=0;j<26;j++)//����26�����֣�
	    {
	         for(i=0;i<strlen(enc);i++)//����ĸת����ASCII��ֵ����ʼ��enct[]
            {
                enct[i]=(int)enc[i];
	        }
		    for(i=0;i<strlen(enc);)//������ĵ�����
		    {
		        for(a=0;a<c;a++)
                {
                    enct[i+a]=(enct[i+a]-(j+f[a])%26-71)%26+97;
                }
                i=i+c;
		    }
	        cout<<"\n\n��K1="<<j<<"ʱ,���ܺ���ַ����ǣ�\n";
	        for(i=0;i<strlen(enc);i++)//������ܺ���ַ���
	        {
	    	    cout<<(char)enct[i];
		    }
	    }
        cout<<"\n\n\t�������ַ����п����ҵ�������ľ��ӡ�����Enter�������˳�����";
    }
};
int main()
{
	int d;
	First Fir;
	Second Sec;
	Third Thi;
	cout<<"����������ܵ��ַ�����";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    strcpy(enct,enc);
    cout<<"�����ܵ��ַ��ĸ����ǣ�"<<strlen(enc);
    d=Fir.gl();
    Sec.MIi(d);
    Thi.choiceK(d);
    system("PAUSE");
    return 0;
}
