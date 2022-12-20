#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj,adj_transpus,adj2;
vector<pair<int,int>> muchii;//muchiile grafului in ordine cresc (set)

int n,m,x,y,contor;
stack<int> stiva;
bitset<101>vizitat;
vector<int> id,id_nou;

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  stiva.push(nodcurent);
}

void dfsGT(int nodcurent)
{
  id[nodcurent]=contor;
  vizitat[nodcurent] = true;
  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfsGT(vecin);
}

void citire()
{
  cin>>n>>m;
  adj.resize(n+1);
  adj_transpus.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj_transpus[y].push_back(x);
    muchii.push_back(make_pair(x,y));
  }
}

void id_comp_tari_conexe()
{
  id.resize(n+1);

  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      dfs(i);

  vizitat.reset();

  while(!stiva.empty())
  {
    int element = stiva.top();
    stiva.pop();

    if(!vizitat[element]){
      contor++;
      dfsGT(element);
    }
  }
}

bool compara(pair<int,int> a,pair<int,int> b)
{
  if(a.first == b.first)
    return a.second<b.second;
  return a.first<b.first;
}

int main()
{
  citire();
  id_comp_tari_conexe();//formam un vector id pentru a vedea in ce componenta conexa se afla fiecare element
  adj2.resize(contor+1);
  //aranjarea id-ului pentru a fi in ordine de la primul nod la ultimul
  int modif=0;
  id_nou.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    if(id[i]!=id[i-1])
      modif++;
    id_nou[i]= modif;
  }
  //formam lista de adiacenta a noului graf format din muchiile ce se afla in comp diferite
  for(auto it = muchii.begin();it!=muchii.end();it++)
  {
    int nod1 = (*it).first;
    int nod2 = (*it).second;
    if(id_nou[nod1]!=id_nou[nod2])
      adj2[id_nou[nod1]].push_back(id_nou[nod2]);
  }
  //sortam lista de adiacenta
  for(int i=1;i<=n;i++)
    if(!adj2[i].empty())
      sort(adj2[i].begin(),adj2[i].end(),compara);

  //afisarea listei de adiacenta
  for(int i=1;i<=contor;i++)
  {
    if(!adj2[i].empty())
      for(auto vecin:adj2[i])
        cout<<vecin<<' ';
    else
      cout<<0;
    cout<<'\n';
  }

  return 0;
}
