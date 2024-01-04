#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
};
typedef Node* Tree;
Tree insert(Tree BT,int x){//创建树
    if(!BT){
        BT=new(Node);
        BT->data=x;
        BT->left=BT->right=NULL;
    }
    else if(x<BT->data)
        BT->left=insert(BT->left,x);
    else if(x>BT->data)
        BT->right=insert(BT->right,x);
    return BT;
}
bool judgeidentical(Tree a,Tree b){//判断两棵树是否一致
    if(a==NULL&&b==NULL)
        return true;
    else if((a!=NULL&&b==NULL)||(a==NULL&&b!=NULL))
        return false;
    else if(a->data==b->data)
        return judgeidentical(a->left,b->left)&&judgeidentical(a->right,b->right);
    return false;
}
int main(){
    int n,l,x;
    while(cin>>n&&n){
        cin>>l;
        Tree BT=NULL;
        for(int i=0;i<n;i++){
            cin>>x;
            BT=insert(BT,x);
        }
        for(int i=0;i<l;i++){
            Tree temp=NULL;
            for(int i=0;i<n;i++){
                cin>>x;
                temp=insert(temp,x);
            }
            judgeidentical(temp,BT)?cout<<"Yes"<<endl:cout<<"No"<<endl;
        }
    }
    return 0;
}
