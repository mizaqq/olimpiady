#include <vector>
#include <iostream>
/*
wczytujemy plakaty a następnie dodajemy po jedny minimalnym plakacie za każdym razem gdy nowy wczytany budynek jest mniejszy do momentu az znajdziemy większy bądź równy budynek.
jeżeli jest większy lub stos jest pusty do dodajemy budynek na koniec stosu
*/
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int d, w;
    int ile = 0;
    vector<int> stos;
    cin >> d >> w;
    stos.push_back(w);
    for (int i = 0; i < n - 1; i++) {
        cin >> d >> w;
        if (stos.size() > 0) {
            while (w < stos[stos.size() - 1]) {
                stos.pop_back();
                ile++;
                if (stos.size() == 0)break;
            }
        }
        if (stos.size() == 0) {
            stos.push_back(w);
        }
        else if (w > stos[stos.size() - 1]) {
            stos.push_back(w);
        }
    }
    printf("%d", ile + stos.size());
}
