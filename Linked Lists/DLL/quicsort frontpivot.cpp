#include <iostream>
using namespace std;
 

struct dnode
{
    int data;
    struct dnode *right;
    struct dnode *left;
};
 typedef dnode* DPTR;

void swap ( int* a, int* b )
{   int t = *a;*a = *b;*b = t;   }
 


 DPTR  partition( DPTR l, DPTR h)
{    
    int x  = l->data;   
    DPTR i = NULL;    
    for (DPTR j = l->right; j != h->right; j = j->right)
    {
    	cout<<"j->data="<<j->data<<endl;
        if (j->data <= x)
        {            
            i = (i == NULL)? l->right : i->right; 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i;
    cout<<".........h->data="<<h->data<<" i->data="<<i->data<<endl;
    swap(&(i->data), &(l->data));
    cout<<"i->data="<<i->data<<endl;
    return i;
}
void quickSort(DPTR  l,DPTR h)
{
    if (l != NULL && l != h && l != h->right)
    {
    	cout<<";;;;;;;;;;\n";
        DPTR p = partition(l, h);
        cout<<".........\n";
        quickSort(l, p->left);
        quickSort(p->right, h);
    }
}
void printList(DPTR P)
{
    while (P!=NULL)
    {
        cout << P->data << "  ";
        P = P->right;
    }
    cout << endl;
}
DPTR Insert()
{
	DPTR D=NULL;
	cout<<"Enter value ,-1 to terminate.\n";
	int n;
	cin>>n;
	while(n!=-1)
	{
		DPTR temp=new(dnode);
		temp->data=n;temp->left=NULL;temp->right=NULL;
		if(D==NULL)D=temp;
		else{
			DPTR X=D;
			while(X->right!=NULL)
			X=X->right;
			X->right=temp;temp->left=X;
		}cout<<"Value=";cin>>n;
	}
	return D;
}
int main()
{
	DPTR D=Insert(),X=D;
 	while(X->right!=NULL)
 	X=X->right;
    cout << "Linked List before sorting \n";
    printList(D);
 	cout<<D->data<<"---"<<X->data<<endl;
    quickSort(D,X);
 
    cout << "Linked List after sorting \n";
    printList(D);
 
    return 0;
}
