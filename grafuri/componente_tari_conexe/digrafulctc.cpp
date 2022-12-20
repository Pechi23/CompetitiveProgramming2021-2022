#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");

vector<vector<int> > adj,adj_trans,adj2;
set<pair<int,int>> muchii; //retinem muchiile aici iar mai apoi vom verifica daca nodurile unei muchii
//fac parte din comp tari conexe diferite (folosim set pentru a nu se repeta muchiile)
vector<set<int>> comp; //pe fiecare element din vector vom stoca nodurile care fac parte din acel element
//comp[0].size() = nr de elemente din prima componenta tare conexa gasita
//dupa vom ordona vectorul dupa primul element din set pentru a forma id-ul componentelor in ordine crescatoare

stack<int>st;
int n,m,x,y;
bitset<100001> viz;
vector<int> id;
int contor=0;


void dfs(int nc)
{
  viz[nc]=1;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);
}

void dfsgt(int nc)
{
  //id[nc]=contor;
  comp[contor].emplace(nc);
  viz[nc]=1;
  for(auto i:adj_trans[nc])
    if(!viz[i])
      dfsgt(i);
}

int main()
{
  //citire nr noduri si muchii
  cin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  id.resize(n+1);

  //citire muchii
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
    muchii.emplace(make_pair(x,y));
  }
  //primul pas din algoritmul lui kosaraju
  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  viz.reset();
  comp.resize(n+1);

  //al doilea pas din algoritmul lui kosaraju
  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!viz[element])
    {
      contor++;
      dfsgt(element);
    }
  }

  adj2.resize(contor+1);
  comp.resize(contor+1);
  //trebuie sa avem indicii componentelor conexe astfel incat componenta primului nod sa aiba id-ul 1 deci componentele sa fie marcate
  //in ordine lexicografica
  sort(comp.begin(),comp.end());
  //parcurgem componentele tari conexe in ordine lexicografica si le dam un id
  int contorord=0;
  for(int i=1;i<=contor;i++){
    contorord++;
    for(auto j:comp[i])
      id[j]=contorord;
  }

  //parcurgem toate muchiile iar daca elementele se afla in comp tari conexe diferite punem muchia in lista de adiacenta a grafului adj2(graful restrans)
  for(auto muchie:muchii)
    if(id[muchie.first]!=id[muchie.second])
      adj2[id[muchie.first]].push_back(id[muchie.second]);


  //afisarea listei de adiacenta
  for(int i=1;i<=contor;i++)
  {
    if(adj2[i].size()==0)
      cout<<0;
    else
      for(auto j:adj2[i])
        cout<<j<<' ';
    if(i!=contorord)
      cout<<'\n';
  }
  return 0;
}
