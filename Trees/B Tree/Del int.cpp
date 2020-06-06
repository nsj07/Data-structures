#include <iostream>
using namespace std;

struct bdnode{
	int count;
	int key[10];
	bdnode *ptr[11];
};
typedef bdnode* BDPTR;
BDPTR root=NULL;
static int d=2;

int del(BDPTR,int,BDPTR);

BDPTR put_sort(BDPTR T,int k,BDPTR nw)
{
	T->key[T->count]=k;int f;
	T->count++;
	for(int pass=1;pass<=T->count-1;pass++){
		f=0;
		for(int i=0;i<T->count-pass;i++){
			if(T->key[i]>T->key[i+1]){
				swap(T->key[i],T->key[i+1]);f=1;
			}			
		}if(f==0)break;
	}
	int i=0;
	while(k!=T->key[i]){
		i++;
	}int j=T->count;
	while(j>i){
		T->ptr[j]=T->ptr[j-1];
		j--;
	}T->ptr[i+1]=nw;
	return T;	
}

BDPTR overflow(BDPTR T,int k,BDPTR nw)
{
	BDPTR ov=new bdnode();
	ov->count=T->count;int i;
	for(i=0;i<T->count;i++){
		ov->key[i]=T->key[i];
		ov->ptr[i]=T->ptr[i];
	}
	ov->ptr[i]=T->ptr[i];
	//ov->key[i]=k;ov->count++;
	ov=put_sort(ov,k,nw);
	return ov;	
}

char has_space(BDPTR P,BDPTR T)
{
	//cout<<"---------\n";
	if(P==T)return 'o';
	int i=0;
	while(i<=P->count&&P->ptr[i]!=T)
	i++;
	if(i>0&&P->ptr[i-1]->count<2*d)
	return 'l';
	else if(i<P->count&&P->ptr[i+1]->count<2*d)
	return 'r';
	else return 'o';
}

BDPTR sort(BDPTR T)
{
	/*int i=0;
	while(T->key[i]!=k)i++;
	i++;
	while(i<T->count)
	T->ptr[i]=T->ptr[i+1];*/
	int f;
	for(int pass=1;pass<=T->count-1;pass++){
		f=0;
		for(int i=0;i<T->count-pass;i++){
			if(T->key[i]>T->key[i+1]){
				swap(T->key[i],T->key[i+1]);f=1;
			}			
		}if(f==0)break;
	}
}
void k_redis(BDPTR P,BDPTR T,int i,char h,int k,bool split,BDPTR nw)
{
	if(split)
	{
		if(h=='l'){			
			P->ptr[i-1]->key[P->ptr[i-1]->count]=P->key[i-1];P->ptr[i-1]->count++;
		//	cout<<"---------val="<<P->ptr[i-1]->key[P->ptr[i-1]->count]<<endl;
			P->ptr[i-1]->ptr[P->ptr[i-1]->count]=T->ptr[0];
			P->key[i-1]=T->key[0];
			T->key[0]=k;T=sort(T);
			int j=0;
			while(T->key[j]!=k){
				T->ptr[j]=T->ptr[j+1];j++;
			}T->ptr[j]=T->ptr[j+1];
			T->ptr[j+1]=nw;
		}
		else{
			P->ptr[i+1]->key[P->ptr[i+1]->count]=P->key[i];P->ptr[i+1]->count++;
			P->ptr[i+1]=sort(P->ptr[i+1]);
			int j=P->ptr[i+1]->count;
			while(j>=0){
				P->ptr[i+1]->ptr[j]=P->ptr[i+1]->ptr[j-1];
				j--;
			}P->ptr[i+1]->ptr[0]=T->ptr[T->count];
			P->key[i]=T->key[T->count-1];
			T->key[T->count-1]=k;
			T=sort(T);
			j=T->count-1;
			while(T->key[j]!=k){
				T->ptr[j+1]=T->ptr[j];j--;
			}
			T->ptr[j+1]=nw;
		}
	}
	else{
		if(h=='l'){
			P->ptr[i-1]=put_sort(P->ptr[i-1],P->key[i-1],NULL);
			if(T->key[0]>k)
			P->key[i-1]=k;
			else{
				P->key[i-1]=T->key[0];
				T->key[0]=k;T=sort(T);
			}
		}
		else{
			P->ptr[i+1]=put_sort(P->ptr[i+1],P->key[i],NULL);
			if(T->key[T->count-1]>k){
				P->key[i]=T->key[T->count-1];
				T->key[T->count-1]=k;T=sort(T);
			}
			else
			P->key[i]=k;
		}
	}
}
BDPTR old_new(BDPTR ovload,BDPTR T,BDPTR &nw)
{
	int j;
	for(j=0;j<d;j++){
		T->key[j]=ovload->key[j];
		T->ptr[j]=ovload->ptr[j];
	}T->count=d;T->ptr[j]=ovload->ptr[j];
	for(j=d+1;j<2*d+1;j++){
		nw->key[j-(d+1)]=ovload->key[j];
		nw->ptr[j-(d+1)]=ovload->ptr[j];
	}nw->count=d;
	nw->ptr[j-(d+1)]=ovload->ptr[j];
	
	return T;
}
void Add(BDPTR T,int &k,BDPTR Parent,int &l,BDPTR &newnod,bool &split)
{
	if(T==NULL){
		root=new bdnode();
		for(int j=0;j<2*d+1;j++)
		root->ptr[j]=0;
		root->key[0]=k;root->count=1;
	}
	else{
		int i,flag=0;
		for(i=0;i<T->count;i++){
			if(k<T->key[i]){
				if(T->ptr[i]!=0)
				Add(T->ptr[i],k,T,l,newnod,split);
				else
				l=0;
				flag=1;break;
			}
		}if(flag==0){
			if(T->ptr[i]!=0)
			Add(T->ptr[i],k,T,l,newnod,split);
			else  
			l=0;
		}
		
		if(l==0){
			if(T->count<2*d){
				T=put_sort(T,k,newnod);
				l=1;
			}
			else{
				char h=has_space(Parent,T);
				if(h!='o'&& Parent!=T){
					i=0;
					while(i<Parent->count&&Parent->ptr[i]!=T)
					i++;
					k_redis(Parent,T,i,h,k,split,newnod);
					l=1;return;
				}
			//	cout<<"+===\n";
				BDPTR nw=new bdnode();int j;
				split=true;
				for(j=0;j<2*d+1;j++)
				nw->ptr[j]=0;
				BDPTR ovload=0;
				ovload=overflow(T,k,newnod);
				T=old_new(ovload,T,nw);
				newnod=nw;k=ovload->key[d];
				if(Parent==T){
					BDPTR X=new bdnode();
					X->key[0]=ovload->key[d];X->count=1;
					X->ptr[0]=T;X->ptr[1]=nw;
					root=X;l=1;
				}delete(ovload);
			}
		}
	}
}
class queue{
	public:
		int size;
		int front;
		int rear;
		BDPTR elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(BDPTR x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		BDPTR dequeue(){
			BDPTR t;
			if(front==-1)cout<<"Empty\n";
			else{
				t=elements[front];
				if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				else front =(front+1)%size;
				return t;
			}
		}
		
		BDPTR Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
		int isempty(){
			if(front==-1)
			return 1;
			else return 0;
		}
};
void printlevelorder(BDPTR T)
{
	queue q;
	q.enqueue(T);
	BDPTR L=NULL;
	q.enqueue(L);
	while(!q.isempty())
	{
		BDPTR P=q.dequeue();
		if(P==NULL){
			cout<<endl;
			if(!q.isempty())
			q.enqueue(P);
		}
		else{
			int i=1;
			for(i=0;i<P->count;i++){
				cout<<P->key[i]<<",";
				if(P->ptr[i]!=0) q.enqueue(P->ptr[i]);
			}
			cout<<"     ";		
			if(P->ptr[i]!=0) q.enqueue(P->ptr[i]);
		}
	}
}

bool leaf(BDPTR T)
{
	if(T->ptr[0]==NULL) return true;
	else return false;
}
bool underflow(BDPTR T)
{
	if(T->count>d) return false;
	else return true;
}
BDPTR rearrange(BDPTR T,int k)
{
	int i=0;
	while(T->key[i]!=k)i++;
	for(;i<T->count-1;i++)
	T->key[i]=T->key[i+1];
	T->count--;
	return T;
}
char can_distri(BDPTR Parent,BDPTR T){
	if(Parent==T)return 'o';
	else{
		int i=0;
		while(Parent->ptr[i]!=T)i++;
		if(i>0&&Parent->ptr[i-1]->count>d)
		return 'l';
		else if(i<T->count&&Parent->ptr[i+1]->count>d)
		return 'r';
		else return 'o';
	}
}
BDPTR k_redis_del(BDPTR P,BDPTR T,int i,char h,int k)
{
	int j;
	while(T->key[j]!=k)j++;
	if(h=='l'){
		T->key[j]=P->key[i-1];
		T=sort(T);
		P->key[i-1]=P->ptr[i-1]->key[P->ptr[i-1]->count-1];
		P->ptr[i-1]->count--;
	}
	else{
		T->key[j]=P->key[i];
		T=sort(T);
		P->key[i]=P->ptr[i+1]->key[0];
		for(j=0;j<P->ptr[i+1]->count-1;j++)
		P->ptr[i+1]->key[j]=P->ptr[i+1]->key[j+1];
		P->ptr[i+1]->count--;
	}
	return T;
}
char can_subs(BDPTR T,int k)
{
	int i=0;
	while(T->key[i]!=k)i++;
	BDPTR D=T->ptr[i];
	while(D->ptr[D->count]!=NULL)
	D=D->ptr[D->count];
	if(D->count>d) return 'l';
	D=T->ptr[i+1];
	while(D->ptr[0]!=NULL)
	D=D->ptr[0];
	if(D->count>d) return 'r';
	return 'o';
}
int mx(BDPTR T){
	if(T!=0){
		if(T->ptr[T->count]==0)
		return T->key[T->count-1];
		else 
		return mx(T->ptr[T->count]);
	}
}
int mn(BDPTR T){
	if(T!=0){
		if(T->ptr[0]==0)
		return T->key[0];
		else return mn(T->ptr[0]);
	}
}
BDPTR sub(BDPTR T,char s,int k)
{
	int i=0;
	while(T->key[i]!=k)i++;
	if(s=='l'){
		T->key[i]=mx(T->ptr[i]);
		int h=del(T->ptr[i],T->key[i],T);
	}
	else{
		T->key[i]=mn(T->ptr[i+1]);
		int h=del(T->ptr[i+1],T->key[i],T);
	}
	return T;
}

int del(BDPTR T,int k,BDPTR Parent)
{
	if(T!=NULL){
		int i=0;
		while(k>T->key[i]&&i<T->count)
		i++;
		if(k==T->key[i]){
		//	cout<<"--------\n";
			if(leaf(T)&&!underflow(T)){
				T=rearrange(T,k);
			}
			else if(leaf(T)&&underflow(T)){
				char h=can_distri(Parent,T);
				i=0;
				while(Parent->ptr[i]!=T)
				i++;
				if(h!='o'){
					T=k_redis_del(Parent,T,i,h,k);
				}
				else{
				//	T=nod_com(Parent,T,i,k);
				}
			}
		  	else if(!leaf(T)){
				char s=can_subs(T,k);
				if(s!='o'){
					T=sub(T,s,k);
				}
				else{
				//	T=node_com(Parent,T,k);
				}
			}
		}
		else{
			return del(T->ptr[i],k,T);
		}
	}
	return k;
}

int main()
{
	cout<<"Enter the dimension=";cin>>d;
	int arr[]={4,7,22,21,35,12,23,39,16,32,29,46,28,43,64,9,49,53,40,42,24,60};
	cout<<"Enter the values.\n";
	int n=0,l=1,m=3;
	BDPTR nw=0;
//	cin>>n;
	bool split=false;
	while(n!=22){
		Add(root,arr[n],root,l,nw,split);
		cout<<"\n";printlevelorder(root);cout<<endl;
		split=false;
		l=1;nw=0;
	//	cin>>n;
		n++;
	}
	cout<<"\nLevel order print\n";
	printlevelorder(root);
	cout<<"\nEnter values to delete=";
	cin>>n;
	while(n!=-1){
		int h=del(root,n,root);
		cout<<"h="<<h<<endl;
		cout<<"\n";printlevelorder(root);cout<<endl;
		cin>>n;
	}
}

//3 7 9 1 6 4 8 2 5 -1
//7 61 21 59 32 37 52 53 69 67 48 -1
