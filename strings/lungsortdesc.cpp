/*
   lungsortdesc.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 23/02/2022 11:59:42 by Pechi
   Updated: 23/02/2022 12:39:19 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char*>> cuvinte;

bool cmp(const pair<const int,const char*> a,const pair<const int,const char*> b)
{
  if(a.first!=b.first)
    return b.first<a.first;
  return strcmp(a.second,b.second);
}
int main()
{
  char x[257];
  cin.getline(x,257);
  char *i;
  for(i= strtok(x," ");i!=NULL;i=strtok(NULL," "))
  {
    int cnt=0,j=0;
    cuvinte.emplace_back(cnt,i);
  }
  sort(cuvinte.begin(),cuvinte.end(),cmp);

  for(auto pereche:cuvinte)
      cout<<*pereche.second<<'\n';

}
