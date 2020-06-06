#include <iostream>
using namespace std;

void merging(int a[],int l,int m,int r)
{
	int l1[m-l+1],l2[r-m],i,j,k,f1=m-l+1,f2=r-m;
	for(i=0;i<f1;i++)
	l1[i]=a[l+i];
	for(i=0;i<f2;i++)
	l2[i]=a[m+1+i];
	i=0;j=0;k=l;
	while(i<m-l+1&&j<r-m){
		if(l1[i]<l2[j]){
			a[k++]=l1[i++];
		}
		else{
			a[k++]=l2[j++];
		}
	}	
	while(j<r-m){
		a[k++]=l2[j++];
	}	
	while(i<m-l+1){
		a[k++]=l1[i++];
	}
}
void Merge(int a[],int l,int r)
{
	if(l<r){
		int m=(l+r)/2;
		Merge(a,l,m);
		Merge(a,m+1,r);
		merging(a,l,m,r);	
	}
}

int main()
{
	int a[]={8,1,5,6,4,7,2,9,3},n=9,l=0;
	int i;
	Merge(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
