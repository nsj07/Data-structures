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
    int x  = h->data;   
    DPTR i = NULL;    
    for (DPTR j = l; j != h; j = j->right)
    {
        if (j->data <= x)
        {            
            i = (i == NULL)? l : i->right; 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->right;
    swap(&(i->data), &(h->data));
    return i;
}
void quickSort(DPTR  l,DPTR h)
{
    if (h != NULL && l != h && l != h->right)
    {
        DPTR p = partition(l, h);
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
	cout<<"Enter value ,1000 to terminate.\n";
	int n;
	cin>>n;
	while(n!=1000)
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
 
    quickSort(D,X);
 
    cout << "Linked List after sorting \n";
    printList(D);
 
    return 0;
}
