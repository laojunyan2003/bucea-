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
//哈夫曼树的顺序储存表示
typedef struct {
    int weight;  //结点的权值
    int parent,lchild,rchild;  //结点的双亲，左孩子，右孩子的下标
} HTNode,*HuffmanTree;  //动态分配数组来储存哈夫曼树的结点
//哈夫曼编码表的储存表示
typedef char **HuffmanCode;  //动态分配数组来储存哈夫曼编码

//在哈夫曼树HT中选择两个双亲域为0且权值最小的两个结点，并返回它们在HT中的序号s1和s2
void Select(HuffmanTree HT,int len,int &s1,int &s2) {  //len代表HT数组的长度
    int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;  //先赋予最大值
    for(i=1; i<=len; i++) {
        if(HT[i].weight<min1 && HT[i].parent==0) {
            min1=HT[i].weight;
            s1=i;
        }
    }
    int temp=HT[s1].weight;  //将原值存放起来，然后先赋予最大值，防止s1被重复选择
    HT[s1].weight=0x3f3f3f3f;
    for(i=1; i<=len; i++) {
        if(HT[i].weight<min2 && HT[i].parent==0) {
            min2=HT[i].weight;
            s2=i;
        }
    }
    HT[s1].weight=temp;  //恢复原来的值
}

//构造哈夫曼树HT
void CreatHuffmanTree(HuffmanTree &HT,int n) {
    int s1,s2;
    if(n<=1)
        return;
    int m=2*n-1;  //当n大于1时，n个叶子结点需要2*n-1个结点
    HT=new HTNode[m+1];  //0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根结点
    //将1~m号单元中的双亲、左孩子，右孩子的下标都初始化为0
    for(int i=1; i<=m; ++i) {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
//    cout<<"请输入叶子结点的权值：";
    //输入前n个单元中叶子结点的权值
    for(int i=1; i<=n; ++i) {
       HT[i].weight=int(distrib(rand_gen));
    }
    //通过n-1次的选择、删除、合并来创建哈夫曼树
    for(int i=n+1; i<=m; ++i) {
        //在HT[k](1≤k≤i-1)中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1和s2
        Select(HT,i-1,s1,s2);
        //得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i
        HT[s1].parent=i;
        HT[s2].parent=i;
        //s1,s2分别作为i的左右孩子
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        //i的权值为左右孩子权值之和
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}

//哈夫曼编码
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n) {
    //从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
    HC=new char*[n+1];  //分配n个字符编码的编码表空间（头指针矢量）
    char *cd=new char[n];  //分配临时存放编码的动态数组空间
    cd[n-1]='\0';  //编码结束符
    //从叶子开始逐个字符求哈夫曼编码
    for(int i=1; i<=n; ++i) {
        int start=n-1;  //start开始时指向最后，即编码结束符位置
        int c=i;
        int f=HT[i].parent;  //f是指向结点c的双亲结点
        //从叶子结点开始向上回溯，直到根结点
        while(f!=0) {
            --start;  //回溯一次，start向前指向一个位置
            //判断是结点c是f的左孩子还是右孩子
            if(HT[f].lchild==c) {
                cd[start]='0';  //结点c是f的左孩子，则生成代码0
            } else {
                cd[start]='1';  //结点c是f的右孩子，则生成代码1
            }
            c=f;
            f=HT[f].parent;  //继续向上回溯
        }  //求出第i个字符的编码
        HC[i]=new char[n-start];  //为第i个字符编码分配空间
        strcpy(HC[i],&cd[start]);  //将求得的编码从临时空间cd复制到HC的当前行中
    }
    delete cd;  //释放临时空间
}

//哈夫曼译码
void HuffmanDecoding(HuffmanTree HT,char a[],char zf[],char b[],int n) {
    //a[]用来传入二进制编码，b[]用来记录译出的字符
    //zf[]是与哈夫曼树的叶子对应的字符，n是字符个数相当于zf[]数组的长度
    int q=2*n-1;  //q初始化为根结点的下标
    int k=0;  //记录存储译出字符数组的下标
    for(int i=0; a[i]!='\0'; i++) {  //for循环结束条件是读入的字符是结束符
        //判断读入的二进制字符是0还是1
        if(a[i]=='0') {
            //读入0，把根结点(HT[q])的左孩子的下标值赋给q，
            //下次循环的时候把HT[q]的左孩子作为新的根结点
            q=HT[q].lchild;
        } else if(a[i]=='1') {
            //读入1，把根结点(HT[q])的右孩子的下标值赋给q，
            //下次循环的时候把HT[q]的右孩子作为新的根结点
            q=HT[q].rchild;
        }
        //判断HT[q]是否为叶子结点
        if(HT[q].lchild==0 && HT[q].rchild ==0) {
            //如果读到一个结点的左孩子和右孩子都为0，是叶子结点，
            //说明已经译出一个字符，该字符的下标就是找到的叶子结点的下标
            b[k++]=zf[q];  //把下标为q的字符赋给字符数组b[]
            q=2*n-1;  //初始化q为根结点的下标
        } //继续译下一个字符的时候从哈夫曼树的根结点开始
    }
    //译码完成之后，用来记录译出字符的数组由于没有结束符输出的时候会报错，
    //所以紧接着把一个结束符加到数组最后
    b[k] = '\0';
}

void menu() {
    cout<<"\n\n\n";
    cout<<"\t\t*************************************************"<<endl;
    cout<<"\t\t******                                     ******"<<endl;
    cout<<"\t\t******     欢迎使用哈夫曼编码与译码程序    ******"<<endl;
    cout<<"\t\t******                                     ******"<<endl;
    cout<<"\t\t*************************************************"<<endl;
    cout<<"\n\n\n";
    cout<<"正在为您跳转到主菜单，请稍等..."<<endl;
    system("CLS");
    int n;//记录要编码的字符个数
    char a[MAX_MA];//储存输入的二进制字符
    char b[MAX_ZF];//存储译出的字符
    char zf[MAX_ZF];//储存要编码的字符
    string word ;
    int x=0;
    char z;
    HuffmanTree HT=NULL;//初始化树为空树
    HuffmanCode HC=NULL;//初始化编码表为空表
    system("CLS");
//                    cout<<"请输入字符个数:";
//                    cin>>n;
    n=26;
//                    cout<<"请依次输入"<<n<<"个字符: ";
    for(int i=1; i<=n; i++)
        zf[i]=char('a'-1+i);
    CreatHuffmanTree(HT,n);
    cout<<endl;
    cout<<"创建哈夫曼成功！"<<endl;
    while(1) {
        system("date/t");
        system("time/t");
        cout<<" =============================================================================\n";
        cout<<"||                ★★★★★★★哈夫曼编码与译码★★★★★★★                ||\n";
        cout<<"||============================================================================||\n";
        cout<<"||============================================================================||\n";
//        cout<<"||                     【1】--- 随机生成权值生成哈夫曼树                                  ||\n";
        cout<<"||                     【1】--- 进行哈夫曼编码                                ||\n";
        cout<<"||                     【2】--- 进行哈夫曼译码                                ||\n";
        cout<<"||                     【3】--- 退出程序                                      ||\n";
        cout<<" ==============================================================================\n";
        cout<<"请输入数字来选择对应的功能：";

        int num;
        if(!(cin>>num)) {
            system("CLS");
            cout<<"输入格式错误！请重新输入："<<endl;
            cin.clear();
            cin.sync();
            cin.ignore();
        } else {
            switch(num) {
                case 1:
                    system("CLS");
                    HuffmanCoding(HT, HC, n);
                    cout<<"生成哈夫曼编码表成功！下面是该编码表的输出："<<endl;
                    cout<<endl;
                    cout<<"结点"<<"\t"<<"字符"<<"\t"<<"权值"<<"\t"<<"编码"<<endl;
                    for(int i=1; i<=n; i++) {
                        cout<<i<<"\t"<<zf[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
                    }
//                    cout<<"输出你的文字："<<endl;
//                    while(getline(cin,word)){
//                    }
//                    x=word.length();
//                    cout<<x;
//                    for(int i=0;i<x+1;i++) cout<<word[i]<<" ";
                    for(int i=1; i<=x ; i++) {
                        cout<<i<<"\t"<<zf[i]<<"\t"<<HT[i].weight<<"\t"<<HC[i]<<endl;
                    }
                    std::cout << "请输入一段文字（按回车键结束）: ";
                    std::cin >> word;
                    std::cout << "你输入的文字是: " << word << std::endl;
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
                    cout<<"请输入想要翻译的一串二进制编码：";
                    cin>>a;
                    HuffmanDecoding(HT,a,zf,b,n);
                    cout<<"译码成功！翻译结果为："<<b<<endl;
                    getch();
                    break;
                case 3:
                    cout<<"\n\n\n\n\n";
                    cout<<"\t\t*************************************************"<<endl;
                    cout<<"\t\t******                                     ******"<<endl;
                    cout<<"\t\t******     谢谢使用哈夫曼编码与译码程序    ******"<<endl;
                    cout<<"\t\t******                                     ******"<<endl;
                    cout<<"\t\t*************************************************"<<endl;
                    exit(0);
                default:
                    system("CLS");
                    cout<<"输入错误！没有此功能！请重新输入！"<<endl;
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
