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
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<int,ii>
#define vs vector<string>
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
int s[20005][3],t[20005],b[20005],p[305];
void solve()
{
    readi(n);
    fore(i,0,n-1)
        cin>>s[i][0]>>s[i][1]>>s[i][2];
    readi(m);
    fore(i,0,m-1)
    {
        readi(x);
        p[x]=1;
    }
    fore(d,0,299)
    {
        if(p[d])
        {
            vector<int>vec(t,t+n);
            sort(all(vec));
            fore(i,0,n-1)
            {
                if(!b[i])
                {
                    int x=lower_bound(all(vec),t[i])-vec.begin();
                    b[i]=x%20;
                }
            }
        }
        fore(i,0,n-1)
        {
            if(b[i])
                t[i]++,b[i]--;
            else
                t[i]+=s[i][d/100];
        }
    }
    fore(i,0,n-1)
        cout<<t[i]<<endl;
}
signed main()
{
    INI solve();
}
