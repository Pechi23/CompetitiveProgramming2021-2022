//generarea permutarilor de ordin n
#include<bits/stdc++.h>

using namespace std;
ifstream fin("permutari2.in");
ofstream fout("permutari2.out");

int sol[10],n;
vector<int> input;

bool ok(int k)
{
  for(int i=0;i<k;i++)
    if(sol[i] == sol[k])
      return false;
  return true;
}

void afisare()
{
  for(int i=0;i<n;i++)
    fout<<sol[i]<<' ';
  fout<<'\n';
}

bool solutie(int k)
{
  if(k==n-1)
    return true;
  return false;
}

void back(int k)
{
  for(auto element:input)
  {
    sol[k] = element;
    if(ok(k))
      if(solutie(k))
        afisare();
      else
        back(k+1);
  }
}

int main()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    input.push_back(x);
  }
  sort(input.begin(),input.end());
  back(0);
  return 0;
}
