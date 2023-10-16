#include <vector>
#include <iostream>

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
