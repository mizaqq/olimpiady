#include <iostream>
#include<vector>
/*
Najpierw robimy sobie tablice z minimalną szerokościa na jakiej się może zatrzymać krążek o danej średnicy, następnie jak skończymy to wczytujemy po kolei krążki,
a następnie sprawdzamy w jakim miejscu się zatrzyma, odejmując wynik za każdym razem gdy średnica krążka jest większa niż szerokość rurki
*/
using namespace std;
const int maxn = 300002;
int rurka[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, wynik = 0;
    cin >> n >> m;
    rurka[0] = 1e9;
    wynik = n + 1;
    int j = 1;
    for (int i = 1; i < n + 1; i++) {
        cin >> k;
        rurka[i] = min(rurka[i - 1], k);
    }
    rurka[n + 1] = 0;
    for (int i = 0; i < m; i++) {
        cin >> k;
        if (wynik > 0) {
            wynik--;
        }
        while (wynik > 0 && k > rurka[wynik]) {
            wynik--;
        }
    }
    cout << wynik;
}