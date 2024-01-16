#include <vector>
#include <iostream>
#include<cmath>
/*
Przez most mogą przechodzić turysci albo z najszybszym turystą lub z sąsiadem
i wtedy wybieramy albo przejście wolniejszego i powrót najszybszego turysty,
albo podwójne przejście drugiego najszybszego turysty i pojedyncze najszybszego.
wzór min[(ci-2,t1+2t2+ti);(ci-1+t1+ti)];


*/

using namespace std;
const int MM = 1e5 + 13;
int tab[MM];
vector<int> czas;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    czas.push_back(tab[0]);
    czas.push_back(tab[1]);
    czas.push_back(tab[0] + tab[1] + tab[2]);

    int a, b;
    for (int i = 3; i < n; i++) {
        a = czas[i - 2] + tab[0] + 2 * tab[1]+tab[i];
        b = czas[i - 1] + tab[0] + tab[i];
        czas.push_back(min(a, b));
    }
    if (n == 1) {
        cout << tab[0];
    }
    else if (n==2) {
        cout << czas[1];
    }
    else if (n==3) {
        cout << czas[2];
    }
    else{
        cout << czas[czas.size()-1];
    }
}
