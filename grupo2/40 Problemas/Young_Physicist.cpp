#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);
#define query int n;cin>>n;while(n--)
#define all(v) v.begin(),v.end()
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define forei(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void solve()
{
    vector<int>vec(3,0);
    query
    {
        int a,b,c;cin>>a>>b>>c;
        vec[0]+=a,vec[1]+=b,vec[0]+=c;
    }
    for(int e:vec)
    if(e){cout<<"NO\n";return;}
    cout<<"YES\n";return;
}
main()
{
    INI solve();
}
