/*
   aemi1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 24/02/2022 16:09:11 by Pechi
   Updated: 24/02/2022 16:50:52 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("aemi.in");
ofstream fout("aemi.out");

int n,queries,minim;
vector<int> v,tree;

void citire()
{
  fin>>n;
  v.resize(n+1);
  tree.resize(4*(n+1));
  for(int i=1;i<=n;i++)
    fin>>v[i];
}

void build(int node,int left,int right)
{
  if(left==right){
    tree[node] = v[left];
    return;
  }
  int mid = left + (right-left)/2;
  build(2*node,left,mid);
  build(2*node+1,mid+1,right);
  tree[node] = min(tree[2*node],tree[2*node+1]);
}

void query(int node,int left,int right,int a,int b)
{
  if(a<=left && right<=b)
    minim = min(minim,tree[node]);
  else
  {
    int mid = left + (right-left)/2;
    if(a<=mid)
    {
      query(2*node,left,mid,a,b);
    }
    if(mid<b)
    {
      query(2*node+1,mid+1,right,a,b);
    }
  }
}

void update(int node,int left,int right,int pos,int val)
{
  if(left==right){
    tree[node]=val;
    return;
  }
  else
  {
    int mid = left+(right-left)/2;
    if(mid>=pos)
      update(2*node,left,mid,pos,val);
    else
      update(2*node+1,mid+1,right,pos,val);
    tree[node] = min(tree[2*node],tree[2*node+1]);
  }
}

void solve()
{
  int t,a,b;
  fin>>t>>a>>b;
  if(t==1){
    minim = INT_MAX;
    query(1,1,n,a,b);
    cout<<minim<<'\n';
  }
  else if(t==2){
    update(1,1,n,a,b);
  }
}

int main()
{
  citire();
  build(1,1,n);

  fin>>queries;
  while(queries--)
    solve();
  return 0;
}
