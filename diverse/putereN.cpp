#include <bits/stdc++.h>
using namespace std;

vector<int> putere(int a,int b)
{
  vector<int> puteri(10001);
  int termeni = 0;
  puteri[1] = 1; //puterea va fi 1 initial
  int elemente = 1; //avem un singur element din nr puterii initial
  for(int i=1;i <= elemente;i++)
  {
    int cifra = puteri[i] * a + termeni;
    puteri[i] = cifra%10;
    cifra/=10;
  }
  while(termeni)
  {
    puteri[++elemente] = termeni%10;
    termeni /= 10;
  }
  puteri.resize(elemente+1);
  puteri.erase(puteri.begin());
  reverse(puteri.begin(),puteri.end());
  return puteri;
}

int main()
{
  int n,p;
  cin>>n>>p;
  vector<int> sol = putere(n,p);
  for(auto el: sol)
    cout<<el;
  return 0;
}
