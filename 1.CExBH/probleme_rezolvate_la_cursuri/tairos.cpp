#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

ifstream in("tairos.in");
ofstream out("tairos.out");

#define MOD 1000000007

vector<int> adj[101];
bitset<101> vis;
int N, D;
int  f[101]; // nr de frunze din arborele initial aflate la nivelul i
int nf[101]; // nr de ne-frunze din arborele initial aflate la nivelul i
int  dpf[100001];
int dpnf[100001];
int H; // inaltimea arborelui initial
int nMin = 100004; // nivelul minim la care gasim o frunza

void citire() {
	in >> N >> D;
	int u, v;
	for(int i = 0; i < N - 1; ++i) {
		in >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

void dfs(int nc, int niv) {
	H = max(H, niv);
	vis[nc] = true;
	bool sons = false;
	f[niv]++;
	for(auto nv : adj[nc]) {
		if(vis[nv]) continue;
		sons = true;
		dfs(nv, niv + 1);
	}
	if(sons) f[niv]--, nf[niv]++;
	else nMin = min(nMin, niv);
}

void solve() {
	for(int i = 0; i <= H; ++i){
		dpf[i] = f[i];
		dpnf[i] = nf[i];
	}

	for(int i = nMin; i <= D; ++i) {
		for(int k = 1; k <= H; ++k) {
			dpf[i + k] = (dpf[i + k] + (1LL * dpf[i] * f[k]) % MOD) % MOD;
			dpnf[i + k] = (dpnf[i + k] + (1LL * dpf[i] * nf[k]) % MOD) % MOD;
		}
		dpnf[i] = (dpnf[i] + dpf[i]) % MOD;
		dpf[i] = 0;
	}

	out << (dpf[D] + dpnf[D]) % MOD;
}

int main() {
	citire();
	dfs(1, 0);
	solve();
	return 0;
}
