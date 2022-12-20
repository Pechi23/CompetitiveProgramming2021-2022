#include<bits/stdc++.h>
using namespace std;
ifstream fin("alfa.in");
ofstream fout("alfa.out");

vector<int> v;
vector<unsigned int> poz;
int main()
{
  int n,x;
  fin>>n>>x;
  v.resize(n);
  for(int i=0;i<n;i++)
    fin>>v[i];

  //parcurgem vectorul ca sa gasim pozitiile pe care se afla x si le retinem
  for(int i=0;i<=n;i++)
    if(v[i]==x)
      poz.push_back(i);
  for(int i=0;i<poz.size()-1;i++)
    sort(v.begin()+poz[i]+1,v.begin()+poz[i+1]);

  for(auto i:v)
    fout<<i<<' ';
  return 0;
}
