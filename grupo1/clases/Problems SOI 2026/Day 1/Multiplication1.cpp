#include<bits/stdc++.h>
using namespace std;
#define INI cin.tie(0)->sync_with_stdio(0);cout.tie(0);
#define endl '\n'
#define int ll
#define readi(a) int a;cin>>a;
#define readi2(a,b) int a,b;cin>>a>>b;
#define readi3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define readi4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d;
#define reads(a) string a;cin>>a;
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<int,ii>
#define vs vector<string>
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define max3(a,b,c) max(a,max(b,c))
#define sum(n) (n)*((n)+1)/2
#define aureo (1+sqrt(5))/2
#define fibo(n) (pow(aureo,n)-pow(1-aureo,n))/(sqrt(5))
typedef long long ll;
typedef unsigned long long ull;
typedef double long dl;
const dl PI=acos(-1);
const ll inf=numeric_limits<ll>::max();
const int P[4] = {2, 3, 5, 7};
struct SegTree{
    vector<int>tree;
    SegTree(int s)
    {
        tree.assign(4*s,0);
    }
    void push(int a)
    {
        if(tree[a]!=0)
        {
            tree[2*a]=max(tree[2*a],tree[a]);
            tree[2*a+1]=max(tree[2*a+1],tree[a]);
        }
    }
    void actu(int n,int ini,int fin,int l,int r,int val)
    {
        if(l>fin || r<ini)return;
        if(l<=ini&&fin<=r)
        {
            tree[n]=max(tree[n],val);
            return;
        }
        push(n);
        int mid=(ini+fin)/2;
        actu(2*n,ini,mid,l,r,val);
        actu(2*n+1,mid+1,fin,l,r,val);
    }
    int query(int n,int ini,int fin,int idx)
    {
        if(ini==fin)
            return tree[n];
        push(n);
        int mid=(ini+fin)/2;
        if(idx<=mid)
            return query(2*n,ini,mid,idx);
        else
            return query(2*n+1,mid+1,fin,idx);
    }
};
void factores(int val,int vec[4],ll &r)
{
    fore(i,0,3)
    {
        vec[i]=0;
        while(val>0&&val%P[i]==0)
            vec[i]++,val/=P[i];
    }
    r=val;
}
void solve()
{
    readi2(n,q)
    vector<SegTree>trees;
    fore(i,0,3)
        trees.EB(n);
    int t,vec[4],r;
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            readi3(l,r,x)
            factores(x,vec,r);
            fore(i,0,3)
                if(vec[i]>0)
                    trees[i].actu(1,0,n-1,l,r,vec[i]);
        }
        else
        {
            readi2(idx,y)
            factores(y,vec,r);
            if(r>1)
            {
                cout<<"No\n";
                continue;
            }
            bool ban=1;
            fore(i,0,3)
            {
                if(vec[i]>0)
                {
                    int c=trees[i].query(1,0,n-1,idx);
                    if(c<vec[i])
                    {
                        ban=0;break;
                    }
                }
            }
            if(ban)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
main()
{
    INI solve();
}
