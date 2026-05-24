#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
#define vs vector<string>
#define vii vector<ii>
#define viii vector<int,ii>
#define suma(n) (n)*((n)+1)/2
#define aureo (1+sqrt(5))/2
#define fibo(n) (pow(aureo,n)-pow(1-aureo,n))/(sqrt(5))
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const ll inf=numeric_limits<ll>::max();
const dl PI=acos(-1);
const int base=1e9;
void multi(vi &vec, int x)
{
    int k=0,tam=vec.size();
    fore(i,0,tam-1)
    {
        int w=vec[i]*x+k;
        vec[i]=w%base,k=w/base;
    }
    while(k)
    {
        vec.push_back(k%base);
        k/=base;
    }
}
void sum(vi &vec,vi &u)
{
    int k=0;
    if (vec.size()<u.size())
        vec.resize(u.size(),0);
    int l=max(vec.size(), u.size());
    fore(i,0,l-1)
    {
        int w=vec[i]+k+(i<u.size()?u[i]:0);
        vec[i]=w%base,k=w/base;
    }
    if(k)
        vec.push_back(k);
}
void solve()
{
    reads(p);
    vi s={1},c={1};
    s.reserve(800);
    c.reserve(600);
    for(char x:p)
    {
        if(x=='L')
            multi(s,2);
        else if(x=='R')
            multi(s,2),sum(s,c);
        else if(x=='*')
            multi(s,5),sum(s,c),multi(c,3);
    }
    cout<<s.back();
    int sz=s.size();
    forei(i,sz-2,0)
        cout<<setfill('0')<<setw(9)<<s[i];
    cout<<endl;
}
void solve1()
{
    vi vec={3000};
    multi(vec,ll(100));
    for(auto e:vec)
        cout<<e<<' ';
    cout<<endl;
//    cout<<vec.back();
//    int tam=vec.size();
//    forei(i,tam-2,0)
//        cout<<setfill('0')<<setw(3)<<vec[i];
}
signed main()
{
    INI solve();
}
