#include <stdio.h>

int a = 10;

void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a+b);
}
void hieu(int a, int b){
    printf("Hieu %d va %d = %d\n", a, b, a-b);
}
void tich(int a, int b){
    printf("Tich %d va %d = %d\n", a, b, a*b);
}
double thuong(int a, int b){
    return (double)a/b;
}

void toanHoc(void(*ptr)(int, int), int a, int b){
    printf("Chuong trinh: ");
    ptr(a,b);
}
int main(int argc, char const *argv[]){
    
    //integer pointer:

    /* int *ptr = &a;
     printf("Dia chi: %d\n", *ptr);*/

    // void pointer:

    /*int i = 10;
    char c = 'A';
    double d = 10.4;

    void *ptrv;
    ptrv = &i;
    
    printf("Dia chi i: %p, gia tri: %d\n", ptrv, *(int *)ptrv);

    ptrv = &c;
    printf("Dia chi i: %p, gia tri: %c\n", ptrv, *(char *)ptrv);

    ptrv = &d;
    printf("Dia chi i: %p, gia tri: %f\n", ptrv, *(double *)ptrv);*/

    //NULL pointer
    /*int *ptrn; // 00401A4B sai
    int *ptrn = NULL; // correct
    printf("Dia chi: %p\n", ptrn);*/

    //Func pointer:

    /*void(*ptr)(int,int);
    ptr = &tong;
    ptr(71,8);
    
    ptr = &hieu;
    ptr(19,7);

    ptr = &tich;
    ptr(7,3);

    double(*ptrD)(int, int);
    ptrD = &thuong;

    printf("Thuong: %f\n", ptrD(17,4));

    toanHoc(&tong,4,1);
    toanHoc(&hieu,4,1);

    void *ptr = &tong;
    ((void(*)(int, int))ptr)(8,9);*/

    
    // Pointer to pointer

    /* int *ptr;
    
    int **ptp;

    printf("Dia chi: %p, Gia tri: %p\n", &ptr, ptr);*/
    
    //micro processor architecture

    /*int *i;
    double *dd;
    void (*pp)(int, int);
    printf("size: %lu\n", sizeof(i));*/


    //Exercise

    double d = 10.3;
    char string[] = "Hello";
    void *array[] = {&toanHoc, &d, string};


    ((void(*)(void(*)(int, int),int, int))array[0])(&tong,8,9);

    printf("String: %s\n", array[2]);
    printf("Double: %f\n", *(double*)array[1]);

    return 0 ;
}