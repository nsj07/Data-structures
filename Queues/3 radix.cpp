#include <iostream>
using namespace std;

struct s1{
	int n;
	char r;
};

class queue{
	public:
		int size;
		int front;
		int rear;
		s1 elements[50];
		
		queue(){
			size=50;
			front=-1;
			rear=-1;
		}
		
		void enqueue(s1 x){
			if((rear+1)%size==front)
			cout<<"full\n";
			else{
				if(rear==-1)front=0;
				rear=(rear+1)%size;
				elements[rear]=x;
			}
		}
		
		s1 dequeue(){
			s1 t;
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
		
		s1 Front(){
			if(front==-1)
			cout<<"Empty\n";
			else
			return elements[front];
		}
};


void conv(s1 s){
	int i=0,n,j,d;
	char a[15];
	n=s.n;
	if(s.r=='b') d=2;
	else if(s.r=='x')d=16;
	else if(s.r=='o')d=8;
	else if(s.r=='p')d=10;
	
	while(n!=0){
		if(n%d>9)
		a[i++]=55+(n%d);
		else
		a[i++]=48+(n%d);	
		n=n/d;
	}
	if(d==2||d==8||d==16){
		cout<<s.n<<"\t"<<s.r<<"\t";
		for(j=i-1;j>=0;j--){
		cout<<a[j];
		
	}cout<<endl;
	}
	
	else{
		cout<<s.n<<"\t"<<s.r<<"\t";
		string str[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
		for(j=i-1;j>=0;j--){
			cout<<str[a[j]-48]<<" ";
		}cout<<endl;
	}
}



int main(){
	queue q;
	
	cout<<"Enter the number of values u want to enter.\n";
	int t,i;
	cin>>t;
	for(i=0;i<t;i++){
		s1 s;
		cout<<"Enter the number.\n";
		cin>>s.n;
		cout<<"Enter the radix.\n";
		cin>>s.r;
		q.enqueue(s);
	}
	while(q.front!=-1){
		conv(q.dequeue());
	}
	return 0;
}
