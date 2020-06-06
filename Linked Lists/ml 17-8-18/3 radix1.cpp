#include <iostream>
using namespace std;

void swap(int &x,int &y){
	int z=x;
	x=y;
	y=z;
}
int main(){
	int a[20],n,i,j,k,l;
	cout<<"Number of values to sort=";
	cin>>n;
	int per,div,min,loc,flag;
	cout<<"Enter the values.\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<5;i++){
		per=1;
		for(k=0;k<=i;k++){
			per=per*10;
		}div=per/10;
		for(j=0;j<n;j++){
			min=(a[j]%per)/div;flag=0;
			for(l=j+1;l<n;l++){
				if((a[l]%per)/div<min){
					flag=1;loc=l;
					min=(a[l]%per)/div;
				}
			}if(flag==1)
			swap(a[j],a[loc]);
		}
	}	
	cout<<"Radix sort:\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<",";
	cout<<endl;
	return 0;
}//170, 45, 75, 90, 802, 24, 2, 66
