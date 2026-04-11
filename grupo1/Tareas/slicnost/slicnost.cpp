#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

typedef vector<pair<int,int>> vpi;

#define pb push_back

#define ff first
#define ss second

const int nax = 1e5 + 4;
int L[nax], R[nax], cor[nax];


pair<int,ll> conq(pair<int,ll> a, pair<int,ll> b)
{
  if(a.ff > b.ff)
    return a;
  if(a.ff < b.ff)
    return b;
  return {a.ff, a.ss +  b.ss};
}
vector<pair<int,ll>> st, st2;
vi lazy;
int n, k, Q, sz = 1;
vi p, pcur, q;
vector<pair<int,pair<int,int>>> C[nax];
void build(int p, int l, int r)
{
  lazy[p] =0;
  if(l == r)
    {
      st[p].ff = 0;
      st[p].ss = 1;
      st2[p].ff = 0;
      st2[p].ss = 1;
      return;
    }
  build(2 * p, l, (l + r)/2);
  build(2 * p + 1, (l + r)/2 + 1, r);
  st[p] = conq(st[2 * p], st[2 * p + 1]);
  st2[p] = conq(st2[2 * p], st2[2 * p + 1]);
}
void propagate(int p, int l, int r)
{
  if(lazy[p] != 0)
    {
      if(l != r)
        {
	  lazy[2 * p] += lazy[p];
	  lazy[2 * p + 1] += lazy[p];
        }
      st[p].ff += lazy[p];
      lazy[p] = 0;
    }
}
void update(int p, int l, int r, int i, int j, int val)
{
  propagate(p, l, r);
  if(i > j)
    return ;
  if(l >= i && r <= j)
    {
      lazy[p] += val;
      propagate(p, l, r);
      return ;
    }
  int m = (l + r)/2;
  update(2 * p, l, m, i, min(j, m), val);
  update(2 * p + 1, m + 1, r, max(i, m + 1), j, val);
  pair<int,ll> a = st[2 * p], b = st[2 * p + 1];
  a.ff += lazy[2 * p]; b.ff += lazy[2 * p + 1];
  st[p] = conq(a, b);
}
void ADD(int val)
{
  update(1, 0, sz - 1, L[cor[val]], R[cor[val]], 1);
}
void DEL(int val)
{
  update(1, 0, sz - 1, L[cor[val]], R[cor[val]], -1);
}
void pupd(int i, pair<int,ll> val)
{
  i += sz;
  st2[i] = val;
  i /= 2;
  while(i)
    {
      st2[i] = conq(st2[2 * i], st2[2 * i + 1]);
      i /= 2;
    }
}
vector<pair<int,pair<int,ll>>> CH[nax];
void solve()
{
  cin >> n >> k >> Q;
  p.resize(n);
  q.resize(n);
  while(sz < n- k + 2)
    sz = (sz << 1);
  lazy.assign(2 * sz + 1, 0);
  st.resize(2 * sz + 1);
  st2.resize(2 * sz + 1);
  for(int i = 0; i < n; i++)
    cin >> p[i];
  pcur = p;
  for(int i = 0; i < n; i++)
    {
      cin >> q[i];
      cor[q[i]] = i;
    }
  for(int i= 0; i < n; i++)
    {
      L[i] = max(0, i - k + 1);
      R[i] = min(n - k , i);
    }
  for(int i = 0; i < Q; i++)
    {
      int pos; cin >> pos;
      pos--;
      if(pos + 1 <= n - k)
	C[pos + 1].pb({i,{pcur[pos], pcur[pos + 1]}});
      if(pos - k + 1 >= 0)
	C[pos - k + 1].pb({i, {pcur[pos + 1], pcur[pos]}});
      swap(pcur[pos], pcur[pos + 1]);
    }


  build(1, 0, sz - 1);
  for(int i = 0; i < k; i++)
    {
      ADD(p[i]);
    }
  pupd(0, st[1]);

  for(auto e: C[0])
    {
      int tm = e.ff;
      ADD(e.ss.ff);
      DEL(e.ss.ss);
      CH[tm].pb({0, st[1]});
    }
  for(auto e: C[0])
    {
      DEL(e.ss.ff);
      ADD(e.ss.ss);
    }
  
  for(int i = k; i < n; i++)
    {
      int idx = i - k + 1;
      ADD(p[i]);
      DEL(p[i - k]);
      pupd(idx, st[1]);
      
      for(auto e: C[idx])
        {
	  int tm = e.ff;
	  ADD(e.ss.ff);
	  DEL(e.ss.ss);
	  CH[tm].pb({idx, st[1]});
        }
      for(auto e: C[idx])
        {
	  DEL(e.ss.ff);
	  ADD(e.ss.ss);
        }
      ///SOME OPERATIONS TO NOTE THE CHANGES
      
    }
  
  cout << st2[1].ff << ' ' << st2[1].ss << '\n';

  for(int i = 0; i < Q; i++)
    {
      for(auto e: CH[i])
        {
	  pupd(e.ff, e.ss);
        }
      cout << st2[1].ff << ' ' << st2[1].ss << '\n';
    }
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tt = 1; //cin >> tt;
  while(tt--)
    solve();

}
