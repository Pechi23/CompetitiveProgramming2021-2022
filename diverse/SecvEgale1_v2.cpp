#include<bits/stdc++.h>
using namespace std;

int maxim = INT_MIN;
bitset<1000001> vizitat;
int n,poz1,poz2;
vector<int> v;
vector<vector<int>> elemente; //primul e val elementului, elemente[i][1] e prima aparitie,
//elemente[i][2] ultima aparitie;

//valoarea si prima aparitie le gasim la citire
//ultima aparitie o gasim printr o parcurgere inversa a sirului

int main()
{
  cin>>n;
  v.resize(n+1);
  //aflarea valorii si a primei aparitii a acesteie
  for(int i=1;i<=n;i++)
  {
    cin>>v[i];
    if(!vizitat[v[i]])
    {
      vector<int> pereche = {v[i],i};
      elemente.push_back(pereche);
      vizitat[v[i]]=true;
    }
  }
  vizitat.reset();
  //parcurgere de la final pt a afla ulima aparitie
  for(int i=n;i>=1;i--)
  {
    int val = v[i];
    if(!vizitat[val])
    {
      for(int j=0;j<elemente.size();j++)//parcurgem sirul de elemente
      {
        if(elemente[j][0]==val)
        {
          if(i-elemente[j][1] > maxim) //daca avem o diferenta intre ultima si prima aparitie mai mare decat anterioarele facem update
          {
            maxim = i-elemente[j][1];
            poz1 = elemente[j][1];
            poz2 = i;

            elemente.erase(elemente.begin()+j); // dupa ce aflam ultima aparitie stergem din lista de elemente
          }
        }
        vizitat[val]=true;
      }
    }
  }
  cout<<poz1<<' '<<poz2;

  return 0;
}
