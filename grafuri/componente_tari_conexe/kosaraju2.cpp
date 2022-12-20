#include<bits/stdc++.h>

using namespace std;

int n,m,x,y,contor=0;
vector<vector<int>> adj,adj_trans,legatura;
vector<pair<int,int>> muchii;
vector<int>id;
stack <int>st;
bitset<101>vizitat;


void dfs(int nodcurent)
{
  vizitat[nodcurent]=true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  st.push(nodcurent);
}

void dfsgt(int nodcurent)
{
  id[nodcurent] = contor;
  vizitat[nodcurent]=true;
  for(auto vecin: adj_trans[nodcurent])
    if(!vizitat[vecin])
      dfsgt(vecin);
}

int main()
{
  cin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  id.resize(n+1);

  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
    muchii.push_back(make_pair(x,y));
  }

  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      dfs(i);

  vizitat.reset();

  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!vizitat[element])
    {
      contor++;
      dfsgt(element);
    }
  }
  legatura.resize(contor+1);

  for(auto muchie:muchii)//parcurgem toate muchiile grafului
  {
    if(id[muchie.first] != id[muchie.second])//daca exista o muchie intre doua noduri ce apartin unor componente tari diferite
      legatura[id[muchie.first]].push_back(id[muchie.second]);//exista un drum de la componenta tare conexa a la b
  }

  for(int i=1;i<=contor;i++)
  {
    if(legatura[i].size()==contor - 1) //daca componenta tare conexa se leaga cu toate celelalte componente tari conexe
    {
      for(int j=1;j<=n;j++)
        if(id[j]==i)
          cout<<j<<' '; //afisam elementele componentei tare conexe ce are id ul id
      return 0;
    }
  }
  return 0;
}
