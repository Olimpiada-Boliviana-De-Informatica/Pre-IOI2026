#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);
#define query int n;cin>>n;while(n--)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void solve()
{
    string cad;cin>>cad;
    if(cad.size()>10)
        cout<<cad[0]<<cad.size()-2<<cad[cad.size()-1];
    else
        cout<<cad;
    cout<<'\n';
}
main()
{
    INI query solve();
}
