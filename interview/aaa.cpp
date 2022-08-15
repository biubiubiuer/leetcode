#include <cstdio>

using namespace std;

int main() {
    int a[4] = {10, 20, 30, 40};
    int *p = (int *) (&a + 1);
    printf("%d", *(p - 1));
    return 0;
}