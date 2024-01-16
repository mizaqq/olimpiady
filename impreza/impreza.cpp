#include<vector>
#include <iostream>
#include <algorithm>

/*
Do rozwiązania zadania tworzymy macierz sąsiedztwa.
Następnie sprawdzamy wierzchołki i usuwamy te, które nie są ze sobą połączone.
Pozostałe wierzchołki tworzą nam klike i mamy wszystkich znajomych

*/

using namespace std;
const int MM = 3001;
int tab[MM][MM];
int checked[MM];
int main()
{	
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		tab[a-1][b-1] = 1;
		tab[b-1][a-1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n && !checked[i]; j++) {
			if (!tab[i][j] && !checked[j]) {
				checked[i] = 1;
				checked[j] = 1;
			}
		}
	}

	for (int i = 0,j=0; i < n,j<n/3; i++) {
		if (!checked[i]) {
			cout << i+1 << " ";
			j++;
		}
	}

}
