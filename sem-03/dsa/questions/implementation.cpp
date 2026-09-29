#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Representing f(x) and g(x) as arrays of size 17
    const int size = 17; // Max degree + 1
    vector<int> f(size, 0); // Initialize all coefficients to 0
    vector<int> g(size, 0); // Initialize all coefficients to 0
    vector<int> h(size, 0); // To store the result

    // Defining f(x) = 5x^16 - 2x^4 + 3x^2 + 5
    f[16] = 5;  // Coefficient of x^16
    f[4] = -2;  // Coefficient of x^4
    f[2] = 3;   // Coefficient of x^2
    f[0] = 5;   // Constant term

    // Defining g(x) = 6x^15 + 8x^6 + 6x^4 + 3x^3 + 2x^2 - 10
    g[15] = 6;  // Coefficient of x^15
    g[6] = 8;   // Coefficient of x^6
    g[4] = 6;   // Coefficient of x^4
    g[3] = 3;   // Coefficient of x^3
    g[2] = 2;   // Coefficient of x^2
    g[0] = -10; // Constant term

    // Adding f(x) and g(x) to get h(x)
    for (int i = 0; i < size; i++) {
        h[i] = f[i] + g[i];
    }

    // Displaying the polynomials
    cout << "f(x): ";
    for (int i = size - 1; i >= 0; i--) {
        if (f[i] != 0) {
            cout << f[i] << "x^" << i << " ";
        }
    }
    cout << endl;

    cout << "g(x): ";
    for (int i = size - 1; i >= 0; i--) {
        if (g[i] != 0) {
            cout << g[i] << "x^" << i << " ";
        }
    }
    cout << endl;

    cout << "h(x): ";
    for (int i = size - 1; i >= 0; i--) {
        if (h[i] != 0) {
            cout << h[i] << "x^" << i << " ";
        }
    }
    cout << endl;

    return 0;
}
