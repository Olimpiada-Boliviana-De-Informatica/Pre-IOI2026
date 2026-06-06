//problema: https://acm.timus.ru/problem.aspx?space=1&num=1090

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n,k; scanf("%d %d",&n,&k);
  int jump=-1,res=1e9;
  for(int i=1;i<=k;i++){
    ordered_set<int> s;
    int act=0;
    for(int j=0;j<n;j++){
      int x; scanf("%d",&x);
      act+=s.order_of_key(x);
      s.insert(x);
    }
    if(act>jump){
      jump=act;
      res=i;
    }
  }
  printf("%d\n",res);
  
  return 0;
}
