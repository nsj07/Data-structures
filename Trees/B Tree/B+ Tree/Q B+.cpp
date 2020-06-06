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
	int f;
	for(int pass=1;pass<=T->count-1;pass++){
		f=0;
		for(int i=0;i<T->count-pass;i++){
			if(T->key[i]>T->key[i+1]){
				swap(T->key[i],T->key[i+1]);f=1;
			}			
		}if(f==0)break;
	}
	return T;
}
void k_redis(BDPTR Parent,BDPTR T,int i,char h,int k)
{
	if(h=='l'){
		Parent->ptr[i-1]=put_sort(Parent->ptr[i-1],Parent->key[i-1],NULL);
		Parent->key[i-1]=T->key[0];
		T->key[0]=k;T=sort(T);
	}
	else{
		Parent->ptr[i+1]=put_sort(Parent->ptr[i+1],Parent->key[i],NULL);
		Parent->key[i]=T->key[T->count-1];
		T->key[T->count-1]=k;T=sort(T);
	}
}
BDPTR old_new(BDPTR ovload,BDPTR T,BDPTR &nw,int i)
{
	int j;
	if(i==0){
		for(j=0;j<d;j++){
		T->key[j]=ovload->key[j];
		T->ptr[j]=ovload->ptr[j];
		}T->count=d;T->ptr[j]=ovload->ptr[j];
		for(j=d+1;j<2*d+1;j++){
			nw->key[j-(d+1)]=ovload->key[j];
			nw->ptr[j-(d+1)]=ovload->ptr[j];
		}nw->count=d;
		nw->ptr[j-(d+1)]=ovload->ptr[j];
	}
	else{
		for(j=0;j<d;j++){
		T->key[j]=ovload->key[j];
		T->ptr[j]=ovload->ptr[j];
		}T->count=d;T->ptr[j]=ovload->ptr[j];
		for(j=d;j<2*d+1;j++){
			nw->key[j-(d)]=ovload->key[j];
			nw->ptr[j-(d)]=ovload->ptr[j];
		}nw->count=d+1;
		nw->ptr[j-(d)]=ovload->ptr[j];
		
	}	
	return T;
}
bool leaf(BDPTR T)
{
	if(T->ptr[0]==NULL) return true;
	else return false;
}
void Add(BDPTR T,int &k,BDPTR Parent,int &l,BDPTR &newnod,bool &split)
{
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
			/*if(!split && h!='o'&& Parent!=T){
				i=0;
				while(i<Parent->count&&Parent->ptr[i]!=T)
				i++;
				k_redis(Parent,T,i,h,k);
				l=1;return;
			}*/
		//	cout<<"+===\n";
			if(!leaf(T)){
				BDPTR nw=new bdnode();int j;
				split=true;
				for(j=0;j<2*d+1;j++)
				nw->ptr[j]=0;
				BDPTR ovload=0;
				ovload=overflow(T,k,newnod);
				T=old_new(ovload,T,nw,0);
				newnod=nw;k=ovload->key[d];
				if(Parent==T){
					BDPTR X=new bdnode();
					X->key[0]=ovload->key[d];X->count=1;
					X->ptr[0]=T;X->ptr[1]=nw;
					root=X;l=1;
				}delete(ovload);
			}
			else{
				BDPTR nw=new bdnode();int j;
				split=true;
				for(j=0;j<2*d+1;j++)
				nw->ptr[j]=0;
				BDPTR ovload=0;
				ovload=overflow(T,k,newnod);
				T=old_new(ovload,T,nw,1);
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
				cout<<P->key[i];
				i!=P->count-1?cout<<",":cout<<"";
				if(P->ptr[i]!=0) q.enqueue(P->ptr[i]);
			}
			cout<<"     ";		
			if(P->ptr[i]!=0) q.enqueue(P->ptr[i]);
		}
	}
}
int main()
{
	root=new bdnode();
	cout<<"Enter the dimension=";cin>>d;
	for(int j=0;j<2*d+1;j++)
	root->ptr[j]=0;
	cout<<"Enter the values.\n";
	int n,l=1,m=3;
	BDPTR nw=0;
	cin>>n;root->count=1;
	root->key[0]=n;
	cin>>n;
//	n=3;
	bool split=false;
	while(n!=-1){
		Add(root,n,root,l,nw,split);
		cout<<"\n";printlevelorder(root);cout<<endl;
		split=false;
		l=1;nw=0;
		n=++m;
		cin>>n;
	}
	cout<<"\nLevel order print\n";
	printlevelorder(root);
}

//3 7 9 1 6 4 8 2 5 -1
//7 61 21 59 32 37 52 53 69 67 48 -1
