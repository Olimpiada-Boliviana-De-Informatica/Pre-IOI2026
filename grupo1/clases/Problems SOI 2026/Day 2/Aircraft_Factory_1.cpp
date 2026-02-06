#include<bits/stdc++.h>
using namespace std;
#define INI cin.tie(0)->sync_with_stdio(0);cout.tie(0);
#define int ll
#define readi(a) int a;cin>>a;
#define readi2(a,b) int a,b;cin>>a>>b;
#define readi3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define readi4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d;
#define reads(a) string a;cin>>a;
#define query readi(a) while(a--)
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
#define endl '\n'
#define aureo (1+sqrt(5))/2
#define fibo(n) (pow(aureo,n)-pow(1-aureo,n))/(sqrt(5))
#define sum(n) (n)*((n)+1)/2
#define readv(vec,a) readi(a) vi vec(a);for(auto &e:vec)cin>>e;
#define printv(vec) for(auto e:vec)cout<<e<<' ';cout<<endl;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const ll inf=numeric_limits<ll>::max();
const dl PI=acos(-1);
void solve()
{
    readi(n)
    vector<ii>vec(n);
    int Ei=0,Si=0;
    fore(i,0,n-1)
    {
        cin>>vec[i].first;
        Si+=vec[i].first;
    }
    fore(i,0,n-1)
    {
        cin>>vec[i].second;
        Ei+=vec[i].second;
    }
    if(n==1)
    {
        cout<<vec[0].second<<endl;
        return;
    }
    int b=2*(Ei-Si),men=-1;
    sort(all(vec));
    fore(i,0,n-1)
    {
        int S0=(i==0?vec[1].first:vec[0].first);
        int may=b+2*S0-vec[i].second;
        men=min(men,may);
    }
    cout<<men;
}
main()
{
    INI solve();
}
