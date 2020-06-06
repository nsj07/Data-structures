#include <iostream>
#include<string>
using namespace std;

typedef
struct lnode{
    int data;
    lnode* next;
}*LPTR;
int all_visited(bool G[][10],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(G[i][j])
            return 0;
    }
    return 1;
}
void permute(int a[],int l,int r,string s[],int &j){
    int i;
    if(l==r){
        for(int i=0;i<=r;i++)
            s[j]+=a[i]+'0';
            j+=1;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(a[l],a[i]);
            permute(a,l+1,r,s,j);
            swap(a[i],a[l]); //backtrack
        }
    }
}
int visited(int x,int p[],int n){
    for(int i=0;i<n;i++)
        if(p[i]==x)
        return 1;
    return 0;
}
void DFT(bool G[][10],int v,int p[],int n,int s){
    p[n]=s;
    n+=1;
    if(all_visited(G,v))
    {
        for(int i=0;i<n;i++){
            cout<<p[i];
            if(i+1!=n)
                cout<<"->";
        }
        cout<<endl;
    }
    else{
    	cout<<"ppp\n";
        for(int i=1;i<=v;i++){
            if(G[s][i]==1){
                G[s][i]=G[i][s]=0;
                DFT(G,v,p,n,i);
            }
        }
    }
}
int fact(int n){
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}
void print(string s[],int n){
    cout<<"print\n";
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
}

void print_(int p[],int n){
    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
    cout<<endl;
}

bool all_visit(int p[],int sz,bool G[][10],int n,bool visit[]){
    for(int i=0;i<sz;i++){
        for(int j=1;j<=n;j++){
            if(G[p[i]][j]&&!visit[j])
                return 0;
        }
    }
    return 1;
}
void DFT_2(bool G[][10],int v,bool visit[],int s,int p[],int &sz,int &mx){
    p[sz]=s;
    sz+=1;
    int temp_sz=sz;
    bool temp_visit[20];
    for(int i=1;i<=v;i++)
        temp_visit[i]=visit[i];
    if(mx<sz)
        mx=sz;
    int a[10],n=0,x=0;
    for(int i=1;i<=v;i++){
        if(G[s][i] && !visit[i])
        {
         a[n]=i;n+=1;
        }
    }
    string str[fact(n)];
 //   cout<<"permute\n";
    permute(a,0,n-1,str,x);
 //   print(str,fact(n));
    for(int j=0;j<fact(n);j++){
      //  cout<<"\n"<<s<<" str="<<str[j]<<endl;
        for(int i=0;i<n;i++){
            if(!visit[str[j][i]-'0']){
                visit[str[j][i]-'0']=1;
                DFT_2(G,v,visit,str[j][i]-'0',p,sz,mx);
            }
        }
       // if(j<fact(n)-1)
       if(all_visit(p,sz,G,v,visit)&& n!=0){
            for(int i=1;i<=v;i++)
                visit[i]=temp_visit[i];
            print_(p,sz);
            sz=temp_sz;
       }
    }
}

int check(string out[],string s,int n){
    for(int i=0;i<n;i++)
        if(out[i]==s)
        return 1;
    return 0;
}
void DFT_3(bool G[][10],int v,bool visit[],int s,string a,string &p){
    char x=s+'0';
    p+=x;
    visit[s]=1;
    for(int i=0;i<v;i++)
        if(G[s][a[i]-'0'] && !visit[a[i]-'0'])
        DFT_3(G,v,visit,a[i]-'0',a,p);
}
int main()
{
    bool G[10][10]={0};
    bool visit[10]={0};
    int p[10];
    LPTR L=0;
    int n,mx=0,sz=0,ct,out_size=0;
    cout<<"enter no of vertices:(<10)";
    cin>>n;
    cout<<"enter data for adjacency matrix:";
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<"G["<<i<<"]["<<j<<"] =";
            cin>>G[i][j];
        }
    }
  /*  ct=fact(n-1);
    string *str,out[20],s;
    str =new string[ct];
    for(int i=0;i<n-1;i++)
        p[i]=i+2;
    permute(p,0,n-2,str,sz);
    for(int i=0;i<ct;i++)
        str[i]='1'+str[i];
    //DFT(G,n,p,0,1);
 /*   for(int i=1;i<=n;i++){
        if(!visit[i])
        {   visit[i]=1;
            DFT_2(G,n,visit,i,p,sz,mx);
            mx=0;
           // cout<<endl;
        }
    }

    for(int i=0;i<ct;i++){
        for(int j=1;j<=n;j++)
            visit[j]=0;
        for(int j=0;j<n;j++){
            if(!visit[str[i][j]-'0'])
                DFT_3(G,n,visit,str[i][j]-'0',str[i],s);
            if(check(out,s,out_size)==0&& s.length()!=0)
            {
                out[out_size]+=s;
                out_size+=1;
            }
            s.erase(0,s.length());
        }
    }
    cout<<endl;
    for(int i=0;i<out_size;i++)
        cout<<out[i]<<endl;
        */
    cout<<endl;
        DFT(G,n,p,0,0);
    return 0;
}
//5 0 1 1 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0
