#include <iostream>

using namespace std;

struct dnode{
    int data;
    dnode * left;
    dnode * right;
};
typedef dnode * DPTR;

void create(DPTR &D,DPTR &P){
    int n;
    DPTR T;
    cin>>n;
    if(n!=-1){
        D=new dnode;
        T=D;
        T->right=NULL;
        T->left=P;
        T->data=n;
        create(T->right,T);
    }
}

void biotonic(DPTR &L,DPTR &R){
    if(L!=NULL && R!=NULL){
        if(L->data < R->data)
        {
            cout<<L->data<<" ";
            L=L->left;
            biotonic(L,R);
        }
        else{
            cout<<R->data<<" ";
            R=R->right;
            biotonic(L,R);
        }
    }
}
int main()
{
    DPTR D,L,R,P=NULL;
    cout<<"enter data:(enter - to exit)";
    create(D,P);
    L=D;R=D->right;
    while(L->data>R->data){
        L=L->right;R=R->right;
    }
    biotonic(L,R);
    while(L!=NULL){
        cout<<L->data<<" ";
        L=L->left;
    }
    while(R!=NULL){
        cout<<R->data<<" ";
        R=R->right;
    }
}

