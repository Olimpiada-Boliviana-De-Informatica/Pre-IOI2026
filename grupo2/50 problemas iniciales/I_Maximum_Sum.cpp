#include "bits/stdc++.h"
using namespace std;

int main(){
  int n; cin>>n;

  int ma[n+1][n+1];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>ma[i][j];

  int pref[n+1][n+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++) pref[i][j]=0;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      pref[i][j] = ma[i][j] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
    }

    
  
  int res=ma[1][1];
  int a,b,c,d;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      // i,j es una esquina
      for(int k=i;k<=n;k++){
	for(int l=j;l<=n;l++){
	  int actual = pref[k][l] - pref[k][j-1] - pref[i-1][l] + pref[i-1][j-1];
	  if(actual>res){
	    a=i,b=j,c=k,d=l;
	    res=actual;
	  }
	}
      }
    }
  }
  //cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
  cout<<res<<'\n';
  
  return 0;
}
