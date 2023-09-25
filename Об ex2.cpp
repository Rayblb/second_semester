#include <iostream>
using namespace std;
/*

1. `int *ptr = (int*)malloc(sizeof(int))` - Allocates memory for an integer and returns a pointer to the first byte of the allocated memory block. The C++ equivalent is `int *ptr = new int`.
2. `int *ptrArr = (int*)malloc(sizeof(int)*N)` - Allocates memory for an array of integers with N elements and returns a pointer to the first byte of the allocated memory block. The C++ equivalent is `int *ptrArr = new int[N]`.
3. `free(ptr)` - Deallocates the memory block pointed to by ptr. The C++ equivalent is `delete ptr`.
4. `free(ptrArr)` - Deallocates the memory block pointed to by ptrArr. The C++ equivalent is `delete[] ptrArr`.

In C++, it is necessary to free dynamic memory that has been allocated using `new` or `new[]`. If you do not free this memory, it will result in a memory leak, which can cause your program to run out of memory over time.

It is not possible to free the same allocated memory twice, as this can cause undefined behavior in your program.

It is also not possible to free unallocated memory, as this can also cause undefined behavior in your program.
*/



void fiboTriangle(int n) {
    int* f = new int[n * (n + 1) / 2];
    int fiboNum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                f[fiboNum] = 1;
            }
            else {
                f[fiboNum] = f[fiboNum - i] + f[fiboNum - i + 1];
            }
            cout << f[fiboNum++] << " ";
        }
        cout << endl;
    }
    delete[] f;
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    fiboTriangle(n);
    return 0;
}