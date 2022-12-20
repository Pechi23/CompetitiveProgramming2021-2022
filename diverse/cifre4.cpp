#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> frecv;
int n;

bool compara(pair<int,int> a, pair<int,int> b)
{
  if(a.second < b.second)
    return true;
  return a.first < b.first;
}

int main()
{
  cin>>n;
  frecv.resize(11);
  for(int i=1;i<=9;i++)
    frecv[i].first = i;

  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    while(x)
    {
      int cif = x%10;
      frecv[cif].second++;
      x/=10;
    }
  }

  sort(frecv.begin(),frecv.end(),compara);

  for(auto it = frecv.begin();it!= frecv.end(); it++)
    if((*it).second)
      cout<<(*it).first<<' ';
  return 0;
}
