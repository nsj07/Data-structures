#include <iostream>
#include <cstring>
using namespace std;

struct lnode{
	char data[20];
	int size;
	lnode *next;
};
typedef lnode* LPTR;
LPTR L=NULL;

LPTR Insert(){
	LPTR P=NULL;
	cout<<"Enter word, 0 to terminate list.\n";
	char c[20];
	cin>>c;
	while(c[0]!='0'){
		LPTR temp=new(lnode);
		strcpy(temp->data,c);
		temp->next=NULL;
		temp->size=strlen(c);
		cout<<temp->data<<"---"<<temp->size<<endl;
		if(P==NULL)
		P=temp;
		else{
			LPTR X=P;
			while(X->next!=NULL)
			X=X->next;
			X->next=temp;
		}
		cout<<"Enter next word:";
		cin>>c;
	}
	return P;
}
void print(LPTR P){
	while(P!=NULL){
		cout<<P->data<<" ";
		P=P->next;
	}cout<<endl;
}
int main(){
	LPTR L=Insert();
	print(L);
	LPTR F=L,R=L,prev;
	while(R->next!=NULL){
		prev=R;
		R=R->next;
	}
	int i=0,j=R->size-1,flag=0;
	while(R->next!=F){
	//	cout<<"F="<<F->data<<endl;
	//	cout<<"R="<<R->data<<endl;
	//	cout<<"i="<<i<<" j="<<j<<endl;
		
		while(i<F->size&&j>=0)
		{
			if(F->data[i]==R->data[j]){
				i++;j--;
			}else{
				flag=1;break;
			}
		}if(flag==1)break;		
		if(i==F->size&&j==-1){
			LPTR P=L;
			while(P->next!=R){
				prev=P;
				P=P->next;
			}R=P;F=F->next;
			i=0;j=R->size-1;
		}
		else if(i==F->size){
			F=F->next;
			i=0;
		}
		else if(j==-1){
			LPTR P=L;
			while(P->next!=R){
				prev=P;
				P=P->next;
			}R=P;
			j=R->size-1;
		}
	}
	if(flag==0)
	cout<<"String is palindrome.\n";
	else
	cout<<"Not palindrome.\n";
	return 0;
}
/*Eva, Can I Stab Bats In A Cave? (8 words, 22 letters) ...
A Man, A Plan, A Canal-Panama! (8 words, 21 letters) ...
Madam In Eden, I'm Adam (5 words, 17 letters) ...
Mr. Owl Ate My Metal Worm (6 words, 19 letters) ...
A Santa Lived As a Devil At NASA (8 words, 25 letters) ...
Dammit, I'm Mad! ...
Was It A Rat I Saw? ...
Do Geese See God?*/
