#include<bits/stdc++.h>

using namespace std;
ifstream fin("b.in");
ofstream fout("b.out");
int n,q;

vector<int> lungime,latime; // <lungime, latime>

void query(int a,int b)
{
  long long sol=0;
  int minn = INT_MAX;
  long long sum = 0;
  for(int i=a; i<=b; i++)
  {
    minn = min(latime[i], minn);
    sum += lungime[i];
  }
  sol = minn * sum;
  cout<<sol<<'\n';
}

void citire()
{
  cin>>n;
  lungime.resize(n+1);
  latime.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int a,b;
    cin>>a>>b;
    lungime[i] = a;
    latime[i] = b;
  }
  cin>>q;
  for(int i=1;i<=q;i++)
  {
    int a,b;
    cin>>a>>b;
    query(a,b);
  }
}

int main()
{
  citire();
  return 0;
}
