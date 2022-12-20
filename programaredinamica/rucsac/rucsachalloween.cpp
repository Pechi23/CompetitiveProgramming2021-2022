#include<bits/stdc++.h>
using namespace std;

int n,g,contor;
priority_queue<int> pq;

int main()
{
  cin>>n>>g;
  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    pq.push(x);
  }

  while(g>0)
  {
    if(pq.empty())
    {
      cout<<"NU";
      return 0;
    }

    g-= pq.top();
    pq.pop();
    contor++;
  }
  cout<<contor;
  return 0;
}
