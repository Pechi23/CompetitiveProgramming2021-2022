#include <bits/stdc++.h>
using namespace std;

ifstream fin ("instabook.in");
ofstream fout ("instabook.out");

const int dim = 100005;

int a[dim], p[dim], ma[dim], mi[dim];
int n, m;

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
        p[i] = i;
        ma[i] = i;
        mi[i] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        int x;
        fin >> x;
        if (p[x] != 1)
        {
            int a1, a2;
            a1 = a[p[x] - 1];
            a2 = a[p[x]];
            a[p[x] - 1] = a2;
            a[p[x]] = a1;
            p[a1]++;
            p[a2]--;
            ma[a1] = max(ma[a1], p[a1]);
            mi[a2] = min(mi[a2], p[a2]);
        }
    }

    for (int i = 1; i <= n; ++i)
        fout << mi[i] << ' ' << ma[i] << '\n';
}
