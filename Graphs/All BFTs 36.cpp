#include <iostream>

using namespace std;
struct Queue{
    int size_;
    int f;
    int r;
    int element[5];
};
void eq(Queue &q,int x){
    if(q.f==(q.r+1)%q.size_)
        cout<<"size full\n";
    else{
        if(q.r==-1)
            q.f=0;
        q.r=((q.r+1)%q.size_);
            q.element[q.r]=x;
    }
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
int fact(int n){
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}
int dq(Queue &q){
    int x;
    if(q.f==-1)
        cout<<"empty\n";
    else{
        x=q.element[q.f];
        if(q.f==q.r){
            q.f=-1;q.r=-1;
        }else
        q.f=(q.f+1)%q.size_;
        return x;
    }
}
void BFT(bool G[][10],int n,bool visit[],Queue &Q){
    if(Q.f!=-1){
        int s=dq(Q);
        for(int i=1;i<=n;i++){
            if(G[s][i]&&!visit[i]){
                eq(Q,i);
                cout<<s<<" -> "<<i<<endl;
                visit[i]=1;
            }
        }
        BFT(G,n,visit,Q);
    }
}
void BFT_2(bool G[][10],int n,bool visit[],Queue &Q,int p[],int len){
    if(Q.f!=-1){
        int s=dq(Q),temp_sz=len;
        int a[10],j=0,cnt,sz=0;
        bool temp[10];
        for(int i=1;i<=n;i++)
            temp[i]=visit[i];
        for(int i=1;i<=n;i++){
            if(G[s][i]&&!visit[i])
            {
                a[j]=i;
                j+=1;
            }
        }
        cnt=fact(j);
        string *str;
        str=new string[cnt];
        permute(a,0,j-1,str,sz);
        for(int y=0;y<cnt;y++){
            for(int i=1;i<=n;i++)
                visit[i]=temp[i];
            len=temp_sz;
            for(int i=0;i<j;i++){
                if(!visit[str[y][i]-'0']){
                    eq(Q,str[y][i]-'0');
                    visit[str[y][i]-'0']=1;
                    p[len]=str[y][i]-'0';
                    len+=1;
                }
            }
            BFT_2(G,n,visit,Q,p,len);
        }
    }
    else{
        for(int i=0;i<len;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
}
int all_visited(bool G[][10],int n,bool visit[],int x){
    for(int i=1;i<=n;i++){
        if(i!=x && G[x][i]&&!visit[i])
            return 0;
    }
    return 1;
}
int main()
{
    bool G[10][10]={0};
    bool visit[10]={0};
    int n,p[10];
    Queue Q;
    Q.f=Q.r=-1;
    Q.size_=50;
    cout<<"enter no of vertices:(<10)";
    cin>>n;
    cout<<"enter data for adjacency matrix:";
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<"G["<<i<<"]["<<j<<"] =";
            cin>>G[i][j];
        }
    }
   /* for(int i=1;i<=n;i++){
        if(!visit[i])
        {
            visit[i]=1;
            if(all_visited(G,n,visit,i)==0)
            {
                eq(Q,i);
                BFT(G,n,visit,Q);
                cout<<endl;
            }
            else
                cout<<"("<<i<<")\n";
        }
    }*/
    for(int i=1;i<=n;i++){
        if(!visit[i])
        {
            visit[i]=1;
            eq(Q,i);
            p[0]=i;
            BFT_2(G,n,visit,Q,p,1);
            cout<<endl;
        }
    }
    return 0;
}
// 5 0 1 0 1 0 0 0 1 0 1 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0
