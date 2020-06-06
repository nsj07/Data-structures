#include <iostream>

using namespace std;

struct munode
{
	int data;
	int ctr;
	munode *right;
	munode *left;
	munode *dlink;
};
struct dnode {
	int data;
	dnode *right;
	dnode *left;
};
typedef munode* MPTR;
typedef dnode* DPTR;
void fillList(MPTR m)
{
	cout << "Enter data followed by number of nodes\n";
	cin >> m->data >> m->ctr;
	m->dlink=NULL;m->right=NULL;m->left=NULL;
	if (m->ctr == 0)
	{
		m->right = NULL;
		return ;
	}
	else
	{
		if(m->ctr==1){
			m->right=new(munode);
			fillList(m->right);
			m->right->left=m;
		}
		else if(m->ctr==2){
			cout<<"Enter data followed by no. of nodes for the dlink with data "<<m->data<<endl;
			m->dlink=new(munode);
			fillList(m->dlink);
			cout<<"Continue entering data for sidelink with data value "<<m->data<<endl;
			m->right=new(munode);
			fillList(m->right);
			m->right->left=m;
		}
	}
}
DPTR flatten(MPTR m)
{
	DPTR temp=new(dnode);
	temp->data=m->data;temp->right=NULL;temp->left=NULL;
	if(m->ctr==0)return temp;
	else if(m->ctr==1)
	{
		temp->right=flatten(m->right);
		temp->right->left=temp;
	}
	else if(m->ctr==2)
	{
		temp->right=flatten(m->dlink);
		temp->right->left=temp;
		DPTR D=temp;
		while(D->right!=NULL)D=D->right;
		D->right=flatten(m->right);
		D->right->left=D;
	}
	return temp;
}
void print(DPTR D){
	while(D!=NULL){
		cout<<D->data<<"  ";
		D=D->right;
	}cout<<endl;
}

int main()
{
	cout<<"No. of nodes:\n0-for no links\n1-for sidelink only\n2-for dlink and sidelink.\n";
	MPTR m = new munode;	
	fillList(m);
	DPTR D=flatten(m);
	cout<<"After flattening\n";
	print (D);
	return 0;
}	
