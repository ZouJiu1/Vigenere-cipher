#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <cstring>
char enc[1500];
char enct[1500];
using namespace std;
//重合指数法计算密钥字的长度d
class First
{
private:
    int i,j,d,x,c,e,fre;
    double a,b,f=0,Iy=0,summary;
    char*pl;
public:
    int gl(void)
    {
        cout<<"\n输入要分几段（建议在20以内，不超过30）：";
        cin>>fre;
        char encs[fre+1][fre+1][1500];
        double Ix[fre+1][fre+1],ave[fre+1];
        for(d=1;d<=fre;d++)//对字符串依次进行分段
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
        for(i=1;i<=fre;i++)//输出不同d时的重合指数
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
        for(i=1;i<=fre;i++)//输出不同d时的平均重合指数
        {
            cout<<"\n当d="<<i<<"时的平均重合指数是:"<<ave[i];
        }
        cout<<"\n\n\n\t\t对比分成不同段的重合指数，可以得到密钥长度。"<<endl;
        cout<<"请输入密钥长度：";
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
        cout<<"\n\n\n\t\t通过上述结果，可以计算得到密钥字可能的形式（K1，K1+f[1]，K1+f[2],K1+f[3],K1+f[4],K1+f[5],......）"<<endl;
        cout<<"请依次输入f[i]的值，默认f[0]=0。"<<endl;
        for(i=1;i<c;i++)
        {
            cout<<"f["<<i<<"]=";
            cin>>f[i];
        }
	    for(j=0;j<26;j++)//遍历26个数字，
	    {
	         for(i=0;i<strlen(enc);i++)//把字母转换成ASCII码值，初始化enct[]
            {
                enct[i]=(int)enc[i];
	        }
		    for(i=0;i<strlen(enc);)//求出密文的明文
		    {
		        for(a=0;a<c;a++)
                {
                    enct[i+a]=(enct[i+a]-(j+f[a])%26-71)%26+97;
                }
                i=i+c;
		    }
	        cout<<"\n\n当K1="<<j<<"时,解密后的字符串是：\n";
	        for(i=0;i<strlen(enc);i++)//输出解密后的字符串
	        {
	    	    cout<<(char)enct[i];
		    }
	    }
        cout<<"\n\n\t从上述字符串中可以找到有意义的句子。按下Enter键可以退出程序！";
    }
};
int main()
{
	int d;
	First Fir;
	Second Sec;
	Third Thi;
	cout<<"请输入待解密的字符串：";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    strcpy(enct,enc);
    cout<<"待解密的字符的个数是："<<strlen(enc);
    d=Fir.gl();
    Sec.MIi(d);
    Thi.choiceK(d);
    system("PAUSE");
    return 0;
}
