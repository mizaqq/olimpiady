#include<iostream>
#include<vector>
/*
deklarujemy tablice odwiedzonych jako nieodwiedzone, wczytujemy wierzchołki grafu do macierzy sąsiedztwa, następnie przechodzimy przez cały graf, jeżeli jakiś wierzchołek nie będzie miał 
krawędzi to wypisujemy nie. 
następnie przeszukujemy graf wgłąb i naprzemian kolejne wierzchołki oznaczamy jako gildie szwaczek lub krawc ów.
przy każdym wejściu w dfs zerujemy visited


*/


using namespace std;
constexpr int MM = 2e5 + 7;
vector<int> g[MM];
int visited[MM];
void dfs(int x) {
	for (auto k : g[x]) {
		if (visited[k] != -1) {
			continue;
		}
		visited[k] = visited[x] ^ 1;
		dfs(k);
	}
}


int main()
{
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
	}
	for (int j = 1; j <= m; j++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].empty()) {
			cout << "NIE";
			return 0;
		}
		if (visited[i] != -1) {
			continue;
		}
		visited[i] = 0;
		dfs(i);
	}
	cout << "TAK\n";
	for (int i = 1; i <= n; i++) {
		cout << (visited[i] ? "S\n" : "K\n");
	}
}