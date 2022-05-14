#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int k(0);
    int max_a(sqrt(n / 3));
    for (int a = 0; a <= max_a; ++a) {
        int max_b(sqrt((n - a * a) / 2));
        for (int b = a; b <= max_b; ++b) {
            int m = n - a * a - b * b;
            int c(sqrt(m));
            if (c * c == m) {
                cout << ++k << ": " << "a=" << a << ", b=" << b << ", c=" << c << endl;
            }
        }
    }
    return 0;
}
