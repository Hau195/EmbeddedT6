#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int a[] = {12,43,53,28,33,72,51,19};
    int *b, **c, d;
    *b = a;
    c = &b;
    b++;
    d = *b+**c+3;
    string c;
    printf("%d",d);

}