#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;
ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

unordered_map<int,int> mapa;

int main()
{
  ios::sync_with_stdio(false);
  int n,tip,x;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    fin>>tip>>x;
    switch (tip) {
      case 1: mapa[x]=1; break;
      case 2: mapa.erase(x); break;
      case 3: fout<<(mapa.find(x)!= mapa.end())<<'\n'; break;
    }
  }
  return 0;
}
