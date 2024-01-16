#include <iostream>
#include <vector>
/*
zeby sprawidzć ile mamy oddzielnych skarbonek robimy algorytm find and union i szukamy ilość niezależnych grafów które możemy stworzyć wraz z początkowym wierzchołkiem
następnie sprawdzamy początkowe wierzchołki i te wierzchołki są skarbonkami bazowymi które trzeba otworzyc


*/
using namespace std;
const int MM = 1e6 + 13;
int parent[MM];

int findSet(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findSet(parent[node]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        parent[b] = a;
    }
}

int count(int n) {
    int u;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {

        cin >> u;
        unionSets(i, u);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (findSet(i) == i) {
            components++;
        }
    }

    return components;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << count(n);

}