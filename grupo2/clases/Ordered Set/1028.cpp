//problema: https://acm.timus.ru/problem.aspx?space=1&num=1028

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n; scanf("%d",&n);
  vector<pair<int,int>> v(n);
  for(int i=0;i<n;i++) scanf("%d %d",&v[i].first,&v[i].second);
  sort(v.begin(),v.end());

  ordered_set<int> s;
  vector<int> res(n,0);
  for(int i=0;i<n;i++){
    int l=s.order_of_key(v[i].second+1);
    res[l]++;
    s.insert(v[i].second);
  }
  for(auto it : res) printf("%d\n",it);
  
  return 0;
}
