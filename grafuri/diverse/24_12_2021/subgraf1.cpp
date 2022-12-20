#include<bits/stdc++.h>
using namespace std;
ifstream in("subgraf1.in");
ofstream out("subgraf1.out");

int n,x,y,minim=INT_MAX,contor; //minim e gradul minim din graf iar contor numara cate elemente cu acest grad exista
vector<set<int>> adj; //folosim set pentru ca muchiile se pot repeta
set<pair<int,int>> muchii; //muchiile grafului

int main()
{
  in>>n;
  adj.resize(n+1);
  while(in>>x>>y)
  {
    adj[x].emplace(y);
    adj[y].emplace(x);
    muchii.emplace(make_pair(x,y));
  }
  //gasim gradul minim
  for(int i=1;i<=n;i++)
    if(adj[i].size()<minim)
      minim = adj[i].size();

  //parcurgem toate nodurile grafului iar daca un nod are grad minim eliminam toate muchiile ce il contin
  for(int i=1;i<=n;i++)
    if(adj[i].size()==minim)
      for(auto j:muchii)
          if(j.first==i || j.second==i)
            muchii.erase(j);

  //afisam nr ramas de muchii
  out<<muchii.size();
  return 0;
}
