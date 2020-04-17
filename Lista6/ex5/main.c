#include <stdio.h>
#include <stdlib.h>

struct Vetor{
    float x;
    float y;
    float z;
};

int main()
{
    struct Vetor a, b;
    a.x=1;
    a.y=5;
    a.z=3;
    b.x=2;
    b.y=4;
    b.z=1;
    printf("Vetor Resultante = [%.2f,%.2f,%.2f]\n\n", a.x+b.x, a.y+b.y, a.z+b.z);
    return 0;
    system("PAUSE");
}
