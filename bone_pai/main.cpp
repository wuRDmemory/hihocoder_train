#include <iostream>

using namespace std;

long long A[2][2] = {{0,1}, {1,1}};
long long R[2][2] = {{1,0}, {0,1}};

int main() {
    long long N = 0;
    cin >> N;
    int i=0;
    long long n = N;
    for (i = 0; ; ++i) {
        char ki = n%2;
        if (i != 0) {
            long a=A[0][0]*A[0][0]+A[0][1]*A[1][0];
            long b=A[0][0]*A[0][1]+A[0][1]*A[1][1];
            long c=A[1][0]*A[0][0]+A[1][1]*A[1][0];
            long d=A[1][0]*A[0][1]+A[1][1]*A[1][1];
            A[0][0] = a; A[0][1] = b; A[1][0] = c; A[1][1] = d;
        }

        if (ki != 0) {
            long a = R[0][0]*A[0][0]+R[0][1]*A[1][0];
            long b = R[0][0]*A[0][1]+R[0][1]*A[1][1];
            long c = R[1][0]*A[0][0]+R[1][1]*A[1][0];
            long d = R[1][0]*A[0][1]+R[1][1]*A[1][1];
            R[0][0] = a; R[0][1] = b; R[1][0] = c; R[1][1] = d;
        }
        n = n/2;
        if (n==0)
            break;
    }

    long b = R[1][1]%19999997;
    cout << b << endl;
    return 0;
}