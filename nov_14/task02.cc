#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int r = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    cout << r << endl;
    int i = 0;
    do {
        cout << i * i << " ";
        i += 2;
    } while (i <= n);
    cout << endl;
    return 0;
}