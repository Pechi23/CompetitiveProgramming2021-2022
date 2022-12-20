#include<bits/stdc++.h>
using namespace std;
ifstream fin("lbromana.in");

vector<int> note;
double medie,sum=0;
int nr_note,teza;
int main()
{
  fin>>nr_note;
  for(int i=1;i<=nr_note;i++)
  {
    int x;
    fin>>x;
    if(i!=nr_note)
    {
      note.push_back(x);
    }
    else
      teza = x;
  }
  for(auto el:note)
    sum += el;
  medie = sum / (nr_note-1);


  medie = medie*3 + teza;
  medie/=4;
  cout<<medie;
  return 0;
}
