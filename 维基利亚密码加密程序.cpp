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
        cout<<"\n���ܸ��ַ���ʱ����Կ��ʽ�����磺��16��13��6��......��"<<endl;
        cout<<"���������ʱ��Կ�ĳ��ȣ�";
        cin>>c;
        cout<<"������������Կf[i]��ֵ��0-26���ڣ�"<<endl;
        for(i=0;i<c;i++)
        {
            cout<<"f["<<i<<"]=";
            cin>>f[i];
        }
        for(i=0;i<strlen(enc);i++)//����ĸת����ASCII��ֵ����ʼ��enct[]
        {
            enct[i]=(int)enc[i];
        }
        for(i=0;i<strlen(enc);)//�����ļ��϶�Ӧ�ĵ���Կ����
        {
            for(a=0;a<c;a++)
            {
                enct[i+a]=(enct[i+a]+f[a]%26-71)%26+97;
            }
            i=i+c;
        }
        cout<<"\n\n���ܺ���ַ����ǣ�\n";
        for(i=0;i<strlen(enc);i++)//������ܺ���ַ���
        {
            cout<<(char)enct[i];
        }
        cout<<"\n�����Ѿ���ɣ�����Enter�������˳�����";
    }
};
int main()
{
	Third Thi;
	cout<<"����������ܵ��ַ�����";
    fgets(enc,sizeof(enc),stdin);
    enc[strlen(enc)-1]='\0';
    cout<<"�����ܵ��ַ��ĸ����ǣ�"<<strlen(enc);
    Thi.choiceK();
    system("PAUSE");
    return 0;
}
