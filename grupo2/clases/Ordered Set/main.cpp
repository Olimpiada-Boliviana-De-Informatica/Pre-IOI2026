#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//declaracion para usar con tipos usuales (int,long long,double,pair<-,->, etc...)
//se declara como un set normal: "ordered_set<int> s;"
template<class T> using ordered_set = tree<
  T,
  null_type,
  less<T>, // ordena de mas pequeño a mas grande, greater hace mas grande a mas pequeño
  rb_tree_tag,
  tree_order_statistics_node_update>;

//para ordered_multiset: permite repetidos
template<class T> using ordered_multiset = tree<
  T,
  null_type,
  less_equal<T>, // greater_equal existe tambien
  rb_tree_tag,
  tree_order_statistics_node_update>;

// si queremos un comparador propio hay que declararlo asi
struct compare {
  bool operator()(pair<int,int> a, pair<int,int> b){
    return a.first+a.second < b.first+b.second;
  }
};
//para que funcione bien tiene que tener 3 propriedades
// compare(a,a) = false
// si compare(a,b)=true y compare(b,c)=true entonces compare(a,c)=true
// si a!=b entonces compare(a,b)=true o compare(b,a)=true

//la declaracion del tipo tendra que ser explisita
//aqui uno solo escribe "ordered_set_pares s;"
typedef tree<
  pair<int, int>, 
  null_type, 
  compare, // comparador personalisado
  rb_tree_tag, 
  tree_order_statistics_node_update
  > ordered_set_pares;

int main() {
  ordered_multiset<int> s;

  ordered_set<int> st;

  s.insert(5);
  s.insert(2);
  s.insert(7);
  s.insert(2);
  s.insert(1);
  
  st.insert(5);
  st.insert(2);
  st.insert(7);
  st.insert(2);
  st.insert(1);



  printf("ordered_multiset: ");
  for (auto it : s) printf("%d ",it);
  printf("\n");
  printf("ordered_set: ");
  for (auto it : st) printf("%d ",it);
  printf("\n");

  //order_of_key(k) = numero de elementos estrictamente menores que k
  //si es un "ordred_multiset" se cuenta con repeticion los que aparecen varias veces
  //aunque se use "less_equal" order_of_key sigue contando los que son ESTRICTAMENTE menores
  
  printf("Numero de elementos menor a 5 en multiset: %d\n",(int)s.order_of_key(5));
  printf("Numero de elementos menor a 5 en set: %d\n",(int)st.order_of_key(5));

  //find_by_order(k) devuelve un puntero hacia el elemento k-esimo del ordered_set (indice 0)
  // si k es demasiado grande devuelve el puntero hacia el final (.end())
  
  printf("El elemento numero 2 en el multiset es %d\n",*s.find_by_order(2));
  printf("El elemento numero 2 en el set es %d\n",*st.find_by_order(2));

  //para eliminar un elemento x eliminamos el k-esimo elemento donde k est el numero de elementos estrictamente mas pequeños que x
  auto it = s.find_by_order(s.order_of_key(2));
  if (it != s.end()) {
    s.erase(it);
    printf("Exito\n");
  }
  else printf("Fracaso\n");

  st.erase(st.find_by_order(st.order_of_key(2)));

  printf("ordered_multiset: ");
  for (auto it : s) printf("%d ",it);
  printf("\n");
  printf("ordered_set: ");
  for (auto it : st) printf("%d ",it);
  printf("\n");

  printf("--------------------\n");

  ordered_set_pares ss;
  ss.insert({1,2});
  ss.insert({4,5});
  ss.insert({8,0});
  ss.insert({0,1000});
  ordered_multiset<pair<int,int>> aux;
  aux.insert({1,2});
  aux.insert({4,5});
  aux.insert({8,0});
  aux.insert({0,1000});

  printf("ordered set de pares con comparador personalisado\n");
  for(auto it : ss) printf("%d %d\n",it.first,it.second);
  printf("set de pares con comparador normal\n");
  for(auto it : aux) printf("%d %d\n",it.first,it.second);
  
  return 0;
}
