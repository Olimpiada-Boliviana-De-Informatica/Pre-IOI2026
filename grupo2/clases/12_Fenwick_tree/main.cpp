#include "bits/stdc++.h"
using namespace std;

#define MAXN 2e5+5

// Estructura basica para Fenwick Tree, todos los arreglos tienen indice 1 (para indice 0 ver en C-P algorithms)
//Update en un indice y query en un rango

void init(vector<int> const &A, vector<int> &T){
  T.assign(A.size(),0);
  int n=A.size()-1;
  for(int i=1;i<=n;i++){
    T[i]+=A[i];
    int nxt=i+(i & (-i));
    if(nxt<=n) T[nxt]+=T[i];
  }
}

int prefijo(int i, vector<int> &T){
  int res=0;
  while(i>0){
    res+=T[i];
    i-= i & (-i);
  }
  return res;
}
int sum(int l, int r,vector<int> &T){
  return prefijo(r,T)-prefijo(l-1,T);
}

void update(int i, int delta,vector<int> &T){
  int n=T.size()-1;
  while(i <= n){
    T[i]+=delta;
    i+= i&(-i);
  }
}

// ------------------------------------------------------

//Update en un rango y query en un indice

vector<int> bit(MAXN,0);

int sum_indice(int i, vector<int> const &A){
  return prefijo(i,bit)+A[i];
}

void update_indice(int l, int r, int delta){
  update(l,delta,bit);
  update(r+1,-delta,bit);
}

// ------------------------------------------------------

//Update en un rango y query en un rango

vector<int> pos(MAXN,0),neg(MAXN,0),pref;

void init_rango(vector<int> const &A){
  pref.assign(A.size(),0);
  int n=A.size()-1;
  for(int i=1;i<=n;i++) pref[i]+= pref[i-1]+A[i];
}

int prefijo_rango(int i){
  return prefijo(i,pos)*i - prefijo(i,neg) + pref[i];
}
int sum_rango(int l, int r){
  return prefijo_rango(r)-prefijo_rango(l-1);
}

void update_rango(int l, int r, int delta){
  update(l,delta,pos);
  update(r+1,-delta,pos);
  update(l,delta*(l-1),neg);
  update(r+1,-delta*r,neg);
}

int main(){
  vector<int> A={0,1,2,3,4};
  
  vector<int> T;
  init(A,T);
  printf("%d\n",sum(1,3,T));
  update(2,10,T);
  printf("%d\n\n",sum(2,3,T));

  printf("%d\n",sum_indice(3,A));
  update_indice(2,4,8);
  printf("%d\n\n",sum_indice(4,A));
  
  init_rango(A);
  printf("%d\n",sum_rango(1,3));
  update_rango(1,3,4);
  printf("%d\n",sum_rango(3,4));

  return 0;
}
