#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,z,contor;
vector<tuple<int,int,int>> muchiipond;
vector<pair<int,int>> medie;

int main()
{
  cin>>n>>m;
  medie.resize(n+1);
  muchiipond.resize(m);
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y>>z;
    muchiipond[contor++]=make_tuple(x,y,z);
  }
  int a,b,c;
  for(int i=0;i<contor;i++)
  {
    tie(a,b,c)=muchiipond[i];
    medie[a].first+=c;
    medie[b].first+=c;
    medie[a].second+=1;
    medie[b].second+=1;
  }

  double minim =  1000.00001;
  for(int i=1;i<=n;i++)
  {
    double med = double(medie[i].first/medie[i].second);
    if(minim > med)
      minim = med;
  }

  for(int i=1;i<=n;i++){
    double med = double(medie[i].first/medie[i].second);
    if(minim==med){
      cout<<i;
      return 0;
    }
  }
  return 0;
}
