#include <iostream>
#include <cstring>
using namespace std;

union u{
	int i;
	char c;
};
struct btnode{
	btnode* lc;
	int tag;
	u data;
	btnode* rc;
};
typedef btnode* BTPTR;
class stack{
	public:
	int size;
	int top;
	BTPTR elements[25];
	
	void push(BTPTR x){
		if(top==(size-1))
		cout<<"Stack is full\n";
		else
		elements[++top]=x;
	}
	BTPTR pop(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top--];
	}
	BTPTR Top(){
		if(top==-1)
		cout<<"Stack is empty\n";
		else
		return elements[top];
	}
};
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

int isbreak(char x){
	if(x==' '||x=='+'||x=='-'||x=='*'||x=='/')return 1;
	else return 0;
}
BTPTR createextree(char c[]){
	int i=0,n=strlen(c);stack s;
	while(i<n){
		if(!op(c[i])){
			if(c[i]==32){
				i++;continue;
			}
			int j=0,sum=0,k;
			while(!isbreak(c[i])){
				sum=sum*10+(c[i++]-48);				
			};
			BTPTR T=new(btnode);
			T->tag=1;T->data.i=sum;T->lc=NULL;T->rc=NULL;
			s.push(T);
			c[i]!=32?i=i+0:i++;			
			//cout<<"--"<<sum<<endl;
			//s.push(sum);
		}
		else if(op(c[i])) {
			cout<<"op="<<c[i]<<endl;
			//int a=calc(s.pop(),s.pop(),c[i]);
			//s.push(a);
			BTPTR T=new(btnode);
			T->tag=0;T->data.c=c[i];T->rc=s.pop();T->lc=s.pop();
			s.push(T);
			i++;
		}
	}
	return s.pop();
}
int eval(BTPTR T)
{
	if(T!=NULL){
		if(T->tag==0){
			return calc(eval(T->rc),eval(T->lc),T->data.c);
		}else
		return T->data.i;
	}
}
void serialize(BTPTR T)
{
	if(T!=NULL){
		if(T->tag==0)
		cout<<T->data.c<<" ";
		else
		cout<<T->data.i<<" ";
		serialize(T->lc);
		serialize(T->rc);
	}else{
		cout<<".";
	}
}
int main()
{
	cout<<"Enter the postfix string(mutidigit seperated by spaces)\n";
	char c[25];
	cin.getline(c,25,'\n');
	cout<<"c="<<c<<endl;
	BTPTR T=createextree(c);
	serialize(T);cout<<endl;
	int ans=eval(T);
	cout<<"Answer="<<ans<<endl;
	
}
//5 3 4 * + 2 -
