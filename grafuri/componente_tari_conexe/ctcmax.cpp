#include<bits/stdc++.h>
using namespace std;

int n,m,contor=0,solutie=0;
vector<vector<int>> adj,adj_trans;
stack<int> st;
vector<int>id;
bitset<101> viz;

vector<set<int>> comp; //aici stocam elemntele fiecarei comp conexe
//folosim set pt ca nodurile sa fie ordonate crescator
//maximul nr de componente este redat de maxim = max(maxim,comp[i].size());
//dupa care afisam toate componentele ce au nr de el = maxim


void dfs(int nc)
{
  viz[nc]=true;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);
}

void dfsgt(int nc)
{
  id[nc]=contor;
  comp[contor].emplace(nc);
  viz[nc]=true;
  for(auto i:adj_trans[nc])
    if(!viz[i])
      dfsgt(i);
}

bool compara(set<int> a,set<int> b)
{
  auto first = *a.begin();
  auto second = *b.begin();
  return first < second;
}

int main()
{
  int x,y;
  cin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  id.resize(n+1);

  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
  }

  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  viz.reset();

  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!viz[element])
    {
      contor++;
      comp.resize(contor+1);
      dfsgt(element);
    }
  }
  //id[i] reprezinta nr componentei conexe in care se afla varful i

  //sortam comp conexe dupa cel mai mic nod din fiecare comp conexa (comp[i].begin())
  sort(comp.begin(),comp.end(),compara);

  //aflam maximul de elemnte maxim = max(maxim,comp[i].size());
  int maxim=0;
  for(int i=1;i<=contor;i++){
    if(maxim<comp[i].size())
      maxim=comp[i].size();
  }

  //afiseaza toate comp conexe cu nr maxim de componente
  for(int i=1;i<=contor;i++){
    if(comp[i].size()==maxim){
      for(auto j:comp[i])
        cout<<j<<' ';
      cout<<'\n';
    }
  }



  return 0;
}
