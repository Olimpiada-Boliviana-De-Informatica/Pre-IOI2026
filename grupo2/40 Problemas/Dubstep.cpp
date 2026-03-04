#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);
#define query int n;cin>>n;while(n--)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define dbg(v) cout<<#v<<'='<<v<<endl;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void solve()
{
    string cad;cin>>cad;
    while(true)
    {
        int r=cad.find("WUB");
        if(r<0)break;
        cad[r]=' ';
         cad.erase(r+1,2);
        int r1=cad.find(' ');
        if(r1==0)cad.erase(r1,1);
    }
    fore(i,0,cad.size()-1)
        if(cad[i]==' '&&cad[i+1]==' ')
            cout<<cad[i++];
        else cout<<cad[i];
}
main()
{
    solve();
}
