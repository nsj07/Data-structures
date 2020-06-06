#include <iostream>
#include<cstring>
using namespace std;

struct lnode{
	int data;
	lnode *next;
};
typedef lnode* LPTR;
struct lstack{
	LPTR top;
};
struct lstack LS;
void print(LPTR L){
	while(L!=NULL){
		cout<<L->data<<"  ";
		L=L->next;
	}cout<<endl;
}
void addfront(LPTR &L,int x){
	LPTR T=new(lnode);
	T->data=x;
	T->next=L;
	L=T;
}
void deletefront(LPTR &P){
	if(P==NULL)
	cout<<"Stack is empty.\n";
	else{
		LPTR T=P;
		P=P->next;
		delete(T);
	}
}
void lpush(lstack &LS,int x){
	addfront(LS.top,x);
}
int lpop(lstack &LS){
	int t=LS.top->data;
	deletefront(LS.top);
	return t;
}
int Top(lstack &LS){
	return LS.top->data;
}
int op(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/')
	return 1;
	else return 0;
}
int calc(int op2,int op1,char x){
	if(x=='+')return op1+op2;
	else if(x=='-')return op1-op2;
	else if(x=='*')return op1*op2;
	else if(x=='/')return op1/op2;
}

int eval(lstack LS,char c[],int n){
	int i=0;
	while(i<n){
		if(c[i]>='0'&&c[i]<='9')
		lpush(LS,c[i]-48);
		else if(op(c[i])){
			int a=calc(lpop(LS),lpop(LS),c[i]);
			lpush(LS,a);
		}i++;
	}
	int b=lpop(LS);
	return b;
}

int main(){
	char c[25];
	cout<<"Enter the postfix string.\n";
	cin>>c;
	LS.top=NULL;
	int n=strlen(c);
	cout<<"length="<<n<<endl;
	int ans=eval(LS,c,n);
	cout<<"Answer="<<ans<<endl;
	return 0;
}
