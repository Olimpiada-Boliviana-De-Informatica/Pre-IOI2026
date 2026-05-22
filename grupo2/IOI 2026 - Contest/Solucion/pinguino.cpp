#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define INI cin.tie(0)->sync_with_stdio(0);cout.tie(0);
#define endl '\n'
#define int ll
#define readi(a) int a;cin>>a;
#define readi2(a,b) int a,b;cin>>a>>b;
#define readi3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define readi4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d;
#define reads(a) string a;cin>>a;
#define query readi(n) while(n--)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
#define aureo (1+sqrt(5))/2
#define fibo(n) (pow(aureo,n)-pow(1-aureo,n))/(sqrt(5))
#define suma(n) (n)*((n)+1)/2
typedef long long ll;
typedef unsigned long long ull;
typedef double long dl;
int mat[25][2][2][2];
int x,y,z;
int bus(int i,int a,int b,int e)
{
    if (i<0) return 1;
    if (mat[i][a][b][e]!=-1) return mat[i][a][b][e];
    int s=0;
    int p=a?1:((x>>i)&1);
    int q=b?1:((y>>i)&1);
    int o=e?1:((z>>i)&1);
    fore(j,0,p)
        fore(l,0,q)
        {
            if (j==1 && l==1) continue;
            int n= j|l;
            if (!e && n>o) continue;
            s+=bus(i-1,a || (j<p),b || (l<q),e || (n<o));
        }
    return mat[i][a][b][e]=s;
}
void solve()
{
    readi3(r,c,k);
    int m=k,d=-1,u,v,t,s=0,p,q;
    fore(i,0,r+c-2)
    {
        u=max(0ll,i-c+1);
        v=min(r-1,i);
        t=max(0ll,v-u+1);
        if (m>=t)
            m-=t;
        else
        {
            d=i;
            break;
        }
    }
    if (d==-1)d=r+c-1;
    if (d>0)
    {
        x=r-1;
        y=c-1;
        z=d-1;
        memset(mat,-1,sizeof(mat));
        s=bus(21,0,0,0);
    }
    if (m>0)
    {
        u=max(0ll,d-c+1);
        v=min(r-1, d);
        p=(d%2==0)?v:u;
        fore(i,0,m-1)
        {
            q=d-p;
            if(!(p&q))s++;
            p+=(d%2==0)?-1:1;
        }
    }
    cout<<s<<endl;
}
signed main()
{
    INI solve();
}
