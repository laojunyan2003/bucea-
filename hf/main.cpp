#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include <random>

#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
std::default_random_engine rand_gen;
std::uniform_int_distribution<int> distrib(1, 100);
//����������˳�򴢴��ʾ
typedef struct {
    int weight;  //����Ȩֵ
    int parent,lchild,rchild;  //����˫�ף����ӣ��Һ��ӵ��±�
} HTNode,*HuffmanTree;  //��̬����������������������Ľ��
//�����������Ĵ����ʾ
typedef char **HuffmanCode;  //��̬�����������������������

//�ڹ�������HT��ѡ������˫����Ϊ0��Ȩֵ��С��������㣬������������HT�е����s1��s2
void Select(HuffmanTree HT,int len,int &s1,int &s2) {  //len����HT����ĳ���
    int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;  //�ȸ������ֵ
    for(i=1; i<=len; i++) {
        if(HT[i].weight<min1 && HT[i].parent==0) {
            min1=HT[i].weight;
            s1=i;
        }
    }
    int temp=HT[s1].weight;  //��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
    HT[s1].weight=0x3f3f3f3f;
    for(i=1; i<=len; i++) {
        if(HT[i].weight<min2 && HT[i].parent==0) {
            min2=HT[i].weight;
            s2=i;
        }
    }
    HT[s1].weight=temp;  //�ָ�ԭ����ֵ
}

//�����������HT
void CreatHuffmanTree(HuffmanTree &HT,int n) {
    int s1,s2;
    if(n<=1)
        return;
    int m=2*n-1;  //��n����1ʱ��n��Ҷ�ӽ����Ҫ2*n-1�����
    HT=new HTNode[m+1];  //0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ�����
    //��1~m�ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
    for(int i=1; i<=m; ++i) {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
//    cout<<"������Ҷ�ӽ���Ȩֵ��";
    //����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
    for(int i=1; i<=n; ++i) {
       HT[i].weight=int(distrib(rand_gen));
    }
    //ͨ��n-1�ε�ѡ��ɾ�����ϲ���������������
    for(int i=n+1; i<=m; ++i) {
        //��HT[k](1��k��i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2
        Select(HT,i-1,s1,s2);
        //�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
        HT[s1].parent=i;
        HT[s2].parent=i;
        //s1,s2�ֱ���Ϊi�����Һ���
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        //i��ȨֵΪ���Һ���Ȩֵ֮��
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}

//����������
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n) {
    //��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
    HC=new char*[n+1];  //����n���ַ�����ı����ռ䣨ͷָ��ʸ����
    char *cd=new char[n];  //������ʱ��ű���Ķ�̬����ռ�
    cd[n-1]='\0';  //���������
    //��Ҷ�ӿ�ʼ����ַ������������
    for(int i=1; i<=n; ++i) {
        int start=n-1;  //start��ʼʱָ����󣬼����������λ��
        int c=i;
        int f=HT[i].parent;  //f��ָ����c��˫�׽��
        //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
        while(f!=0) {
            --start;  //����һ�Σ�start��ǰָ��һ��λ��
            //�ж��ǽ��c��f�����ӻ����Һ���
            if(HT[f].lchild==c) {
                cd[start]='0';  //���c��f�����ӣ������ɴ���0
            } else {
                cd[start]='1';  //���c��f���Һ��ӣ������ɴ���1
            }
            c=f;
            f=HT[f].parent;  //�������ϻ���
        }  //�����i���ַ��ı���
        HC[i]=new char[n-start];  //Ϊ��i���ַ��������ռ�
        strcpy(HC[i],&cd[start]);  //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
    }
    delete cd;  //�ͷ���ʱ�ռ�
}

//����������
void HuffmanDecoding(HuffmanTree HT,char a[],char zf[],char b[],int n) {
    //a[]������������Ʊ��룬b[]������¼������ַ�
    //zf[]�������������Ҷ�Ӷ�Ӧ���ַ���n���ַ������൱��zf[]����ĳ���
    int q=2*n-1;  //q��ʼ��Ϊ�������±�
    int k=0;  //��¼�洢����ַ�������±�
    for(int i=0; a[i]!='\0'; i++) {  //forѭ�����������Ƕ�����ַ��ǽ�����
        //�ж϶���Ķ������ַ���0����1
        if(a[i]=='0') {
            //����0���Ѹ����(HT[q])�����ӵ��±�ֵ����q��
            //�´�ѭ����ʱ���HT[q]��������Ϊ�µĸ����
            q=HT[q].lchild;
        } else if(a[i]=='1') {
            //����1���Ѹ����(HT[q])���Һ��ӵ��±�ֵ����q��
            //�´�ѭ����ʱ���HT[q]���Һ�����Ϊ�µĸ����
            q=HT[q].rchild;
        }
        //�ж�HT[q]�Ƿ�ΪҶ�ӽ��
        if(HT[q].lchild==0 && HT[q].rchild ==0) {
            //�������һ���������Ӻ��Һ��Ӷ�Ϊ0����Ҷ�ӽ�㣬
            //˵���Ѿ����һ���ַ������ַ����±�����ҵ���Ҷ�ӽ����±�
            b[k++]=zf[q];  //���±�Ϊq���ַ������ַ�����b[]
            q=2*n-1;  //��ʼ��qΪ�������±�
        } //��������һ���ַ���ʱ��ӹ��������ĸ���㿪ʼ
    }
    //�������֮��������¼����ַ�����������û�н����������ʱ��ᱨ��
    //���Խ����Ű�һ���������ӵ��������
    b[k] = '\0';
}

void menu() {
    cout<<"\n\n\n";
    cout<<"\t\t*************************************************"<<endl;
    cout<<"\t\t******                                     ******"<<endl;
    cout<<"\t\t******     ��ӭʹ�ù������������������    ******"<<endl;
    cout<<"\t\t******                                     ******"<<endl;
    cout<<"\t\t*************************************************"<<endl;
    cout<<"\n\n\n";
    cout<<"����Ϊ����ת�����˵������Ե�..."<<endl;
    system("CLS");
    int n;//��¼Ҫ������ַ�����
    char a[MAX_MA];//��������Ķ������ַ�
    char b[MAX_ZF];//�洢������ַ�
    char zf[MAX_ZF];//����Ҫ������ַ�
    string word ;
    int x=0;
    char z;
    HuffmanTree HT=NULL;//��ʼ����Ϊ����
    HuffmanCode HC=NULL;//��ʼ�������Ϊ�ձ�
    system("CLS");
//                    cout<<"�������ַ�����:";
//                    cin>>n;
    n=26;
//                    cout<<"����������"<<n<<"���ַ�: ";
    for(int i=1; i<=n; i++)
        zf[i]=char('a'-1+i);
    CreatHuffmanTree(HT,n);
    cout<<endl;
    cout<<"�����������ɹ���"<<endl;
    while(1) {
        system("date/t");
        system("time/t");
        cout<<" =============================================================================\n";
        cout<<"||                ������������������������������                ||\n";
        cout<<"||============================================================================||\n";
        cout<<"||============================================================================||\n";
//        cout<<"||                     ��1��--- �������Ȩֵ���ɹ�������                                  ||\n";
        cout<<"||                     ��1��--- ���й���������                                ||\n";
        cout<<"||                     ��2��--- ���й���������                                ||\n";
        cout<<"||                     ��3��--- �˳�����                                      ||\n";
        cout<<" ==============================================================================\n";
        cout<<"������������ѡ���Ӧ�Ĺ��ܣ�";

        int num;
        if(!(cin>>num)) {
            system("CLS");
            cout<<"�����ʽ�������������룺"<<endl;
            cin.clear();
            cin.sync();
            cin.ignore();
        } else {
            switch(num) {
                case 1:
                    system("CLS");
                    HuffmanCoding(HT, HC, n);
                    cout<<"���ɹ����������ɹ��������Ǹñ����������"<<endl;
                    cout<<endl;
                    cout<<"���"<<"\t"<<"�ַ�"<<"\t"<<"Ȩֵ"<<"\t"<<"����"<<endl;
                    for(int i=1; i<=n; i++) {
                        cout<<i<<"\t"<<zf[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
                    }
//                    cout<<"���������֣�"<<endl;
//                    while(getline(cin,word)){
//                    }
//                    x=word.length();
//                    cout<<x;
//                    for(int i=0;i<x+1;i++) cout<<word[i]<<" ";
                    for(int i=1; i<=x ; i++) {
                        cout<<i<<"\t"<<zf[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
                    }
                    std::cout << "������һ�����֣����س���������: ";
                    std::cin >> word;
                    std::cout << "�������������: " << word << std::endl;
                    for(int i=0; i<= word.length()-1 ; i++) {
                        cout<<int(word[i]-'a'+1)<<"\t"<<word[i]<<"\t"<<HT[int(word[i]-'a'+1)].weight<<"\t"<<HC[int(word[i]-'a'+1)]<<endl;
                    }
                    for(int i=0; i<= word.length()-1 ; i++) {
                        cout<<HC[int(word[i]-'a'+1)];
                    }
                    getch();
                    system("CLS");
                    break;
                case 2:
                    system("CLS");
                    cout<<"��������Ҫ�����һ�������Ʊ��룺";
                    cin>>a;
                    HuffmanDecoding(HT,a,zf,b,n);
                    cout<<"����ɹ���������Ϊ��"<<b<<endl;
                    getch();
                    break;
                case 3:
                    cout<<"\n\n\n\n\n";
                    cout<<"\t\t*************************************************"<<endl;
                    cout<<"\t\t******                                     ******"<<endl;
                    cout<<"\t\t******     ллʹ�ù������������������    ******"<<endl;
                    cout<<"\t\t******                                     ******"<<endl;
                    cout<<"\t\t*************************************************"<<endl;
                    exit(0);
                default:
                    system("CLS");
                    cout<<"�������û�д˹��ܣ����������룡"<<endl;
                    cout<<endl;
            }
        }
    }
}

int main() {
//    system("color 3A");
    menu();
    return 0;
}
