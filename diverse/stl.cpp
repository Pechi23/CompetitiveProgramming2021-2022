/*
   stl.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 10:44:33 by Pechi
   Updated: 09/02/2022 12:00:04 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> CountNum(vector<int> &a, int S)
{
  vector<int> elemente = a;
  vector<int> sol;
  sort(elemente.begin(),elemente.end());
  for(auto el:elemente)
  {
    if(S-el<0)
      return sol;
    if(S-el>=0)
    {
      S-=el;
      sol.push_back(el);
    }
  }
  return sol;
}

int NrMinMaxAp(vector<int> &a)
{
  map<int,int> mapa;
  for(auto el:a)
  {
    mapa[el]++;
  }

  int maxx = 0,sol;
  for(auto el:mapa)
    if(el.second>maxx){
      maxx = el.second;
      sol = el.first;
    }
    else
      if(el.second == maxx && el.first<sol)
        sol=el.first;
  return sol;
}

string MinLexSwap(string s)
{
  string sol = s;
  set<pair<char,int>> caractere; //pair<litera,prima pozitie unde apare>
  bitset<257> vizitat;

  for(int i=0;i<sol.size();i++)
  {
    if(!vizitat[s[i]])
    {
      caractere.emplace((char)s[i], i);
      vizitat[s[i]] = true;
    }
  }

  for(int i=0;i<sol.size();i++)
  {
     //if(*(sety.begin()).first < s[i])
     //{
    //   char aux = *(sety.begin()).first;
       //s[i] =
     //}
  }

  for(auto el:caractere)
    cout<<el.first<<' '<<el.second<<'\n';
  return sol;
}

long long CountSumS(vector<int> &a, int s)
{
  map<int,int> mapa;
  long long sol=0;
  for(auto el:a)
    mapa[el]++;

  for(auto pereche:mapa)
    if(mapa[s-pereche.first])
      cout<<pereche.second<<' '<<mapa[s-pereche.first]<<'\n';
      //sol = sol + pereche.second * mapa[s- pereche.first];

  return sol;
}

int main()
{
  vector<int> proba = {8,2,3,8,7,5};
  int s = 7;
  string sir = "bdcabe";
  //vector<int> sol = CountNum(proba,s);
  //for(auto el:sol)
    //cout<<el<<' ';
  //cout<<NrMinMaxAp(proba);
  cout<<CountSumS(proba,10);
}
