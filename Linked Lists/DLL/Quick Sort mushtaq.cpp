#include <iostream>

using namespace std;
struct dnode{
    dnode *left;
    int data;
    dnode *right;
};
typedef dnode* DPTR;
void creat(DPTR &D){
    DPTR T1,T;
    int n;
    D = new dnode;
    T=D;
    T->left=NULL;
    cout<<"enter data :(enter -1 to exit)\n";
    cin>>n;
    T->data=n;
    cin>>n;
    while(n!=-1){
        T1 =new dnode;
        T1->data=n;
        T1->left=T;
        T->right=T1;
        T=T->right;
        cin>>n;
    }
    T->right=NULL;
}

void print(DPTR &D){
    if(D!=NULL){
        cout<<D->data<<" ";
        print(D->right);
    }
}
void shift(DPTR &D,int x){
    while(x>0){
        D=D->right;
        x--;
    }
}
int part(DPTR D,int low,int high){
    DPTR L=D,H=D,P=D;
    int l=low+1,h=high,f=0;
    shift(P,low);
    shift(L,l);
    shift(H,h);
    while(l<h){f=1;
        while(L->data<P->data && L->right!=NULL)
            {
                L=L->right;l++;
            }
        while(H->data>P->data)
            {
                H=H->left;h--;
            }
        if(l<h)
            swap(L->data,H->data);
    }
    if(P->data>H->data)
    swap(P->data,H->data);
    return h;
}
void quicksort(DPTR D,int low,int high){
    int j;
    if(low<high){
        j=part(D,low,high);
        quicksort(D,low,j-1);
        quicksort(D,j+1,high);
    }
}
int main()
{
    DPTR D,T;
    int l=0,h=0;
    creat(D);
    T=D;
    while(T->right!=NULL)
       {
        h++;
        T=T->right;
       }
    quicksort(D,l,h);
    print(D);
    return 0;
}
