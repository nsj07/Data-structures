#include <iostream>
using namespace std;

void merging(int a[],int b[],int l,int m,int r,int partition,int k,int l1[],int l2[])
{
	int i,j,f1=m-l+1,f2=r-m,t1=0,t2=0;
	for(i=0;i<3;i++)
	l1[i]=a[l+i];
	for(i=0;i<3;i++)
	l2[i]=a[m+1+i];
	t1=t2=3;
	i=0;j=0;
	while(i<3&&j<3){
		if(l1[i]<l2[j]){
			b[k++]=l1[i++];
			if(i==3&&t1<partition){
				for(i=0;i<3;i++)
				l1[i]=a[l+t1+i];
				i=0;t1+=3;
			}
		}
		else{
			b[k++]=l2[j++];
			if(j==3&&t2<partition){
				for(j=0;j<3;j++)
				l2[j]=a[m+1+t2+j];
				j=0;t2+=3;
			}
		}
	}	
	while(j<3){
		b[k++]=l2[j++];
		if(j==3&&t2<partition){
			for(j=0;j<3;j++)
			l2[j]=a[m+1+t2+j];
			j=0;t2+=3;
		}
	}	
	while(i<m-l+1){
		b[k++]=l1[i++];
		if(i==3&&t1<partition){
			for(i=0;i<3;i++)
			l1[i]=a[l+t1+i];
			i=0;t1+=3;
		}
	}
}
void Merge(int a[],int b[],int n,int partition,int &c)
{
	int l1[3],l2[3];
	while(partition!=n){
		int i=0,v=0;
		while(v!=24/(2*partition)){
			if(c%2==0)
			{
				merging(a,b,i,i+partition-1,i+(2*partition)-1,partition,i,l1,l2);
				for(int z=0;z<24;z++);
			//	cout<<"\n0000\n";
			}
			else
			{
				merging(b,a,i,i+partition-1,i+(2*partition)-1,partition,i,l1,l2);
				for(int z=0;z<24;z++);
			//	cout<<"\n1111\n";
			}
			i=i+2*partition;v+=1;
		}
		c+=1;partition*=2;
	}
}

int main()
{
	int a[]={4,8,24,2,18,20,10,11,56,3,13,23,7,12,19,6,9,17,1,21,22,14,15,45},b[24],n=24,l=0;
	int i,c=0;
	Merge(a,b,n,3,c);
	cout<<"Sorted order is:\n";
	for(i=0;i<n;i++)
	{
		if(c%2!=0)
		cout<<b[i]<<" ";
		else
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
