#include<bits/stdc++.h>
using namespace std;
ifstream fin("aemi.in");
ofstream fout("aemi.out");

int v[400005];
int n,m,x,y,val;
int mini;

void build(int nod, int left, int right)
{
  if(left==right){
    fin>>x;
    v[nod] = x;
    return;
  }
  int mij = (left+right)/2;;
  build(2*nod,left,mij);
  build(2*nod+1,mij+1,right);
  v[nod] = min(v[2*nod],v[2*nod+1]);
}

void query(int nod,int left,int right,int x,int y)
{
  if(x<= left && y>=right)
  {
    mini = min(mini, v[nod]);
  }
  else
  {
    int mij = (left+right)/2;
    if(x<=mij)
      query(2*nod,left,mij,x,y);
    if(mij<y)
      query(2*nod+1,mij+1,right,x,y);
  }
}

void update(int nod,int left,int right,int pos, int val)
{
  if(left==right)
  {
    v[nod] = val;
    return;
  }
  int mij = (left+right)/2;
  if(x<)
}

int main()
{
  int q;
  fin>>n;
  build(1,1,n);
  fin>>q;
  while(q--)
  {
    int t;
    fin>>t;
    if(t==1)
    {
      int a,b;
      fin>>a>>b;
      mini = INT_MAX;
      query(1,1,n,a,b);
    }
    else
    {
      fin>>a>>b;
      update(1,1,n,a,b);
    }
  }
  return 0;
}
