#include <bits/stdc++.h>
using namespace std;

bitset<200001> c1;
bitset<200001> c2;
string sir;

int main()
{
  if(getline(cin,sir))
  {
    stringstream citire(sir);
    int x;
    while (citire >> x) {
      if(c1[x])
          c2[x]=true;
        else
          c1[x]=true;
    }
  }
  cout << c1.count() - c2.count(); //din nr de elemente distincte care apar le scadem pe cele care apar de mai multe ori

  return 0;
}
