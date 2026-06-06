//problema: https://acm.timus.ru/problem.aspx?space=1&num=1439

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;

int main() {
  int n,m; scanf("%d %d",&n,&m);
  ordered_set rotas;

  for (int i = 0;i<m;i++){
    char c;
    int k;
    scanf(" %c %d",&c,&k);

    int l=k,r=n,res=n;
    while (l <= r) {
      int med=l+(r-l)/2;
      if (med-rotas.order_of_key(med+1)>=k){
	res=med;
	r=med-1;
      }
      else{
	l=med+1;
      }
    }
    if (c=='D'){
      rotas.insert(res);
    }
    else{
      printf("%d\n",res);
    }
  }
  return 0;
}
