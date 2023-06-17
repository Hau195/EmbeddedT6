#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// int i = 10;
// static int i = 5;

// void tong(){
//     int x;
//     i = 10;
// }

// int tong(int a, int b){
//     int c;
//     c = a + b;
//      return c;
// }

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int array[] = {1,2,3,4};

// int *ptr = array;

void test1(){
    int array[4];

    printf("Dia chi test 1: %p\n", array);
}

void test2(){
    int *array = (int*)malloc(16);

    printf("Dia chi test2: %p\n", array);

    free(array);
}

int main(int argc, char const *argv[]){
    
    

    // int a; 
    // i = 20;
    // printf("i = %f\n", i);
    // i = 4;

    //int x = tong(5,7); // int a = 5; //0x01
                       // int b = 7; //0x02
                       // int c;     //0x03
                       // c = a+b;
                       // return c;

    //tong(7,8);         //int a = 7   //0xc1

    // int x = 10;
    // int y = 20;
    // swap(&x,&y);
    // printf("x = %d, y = %d\n",x,y);

    // printf("Dia chi arr: %p\n", array);

    // for (int i = 0; i<4; i++){
    //     printf("Dia chi array[%d] = %p\n",i,&array[i] );
    // }

    // int *array = (int*)malloc(sizeof(int)*4);

    // for(int i = 0; i < 4; i++){
    //     array[i] = 3*i;
    // }

    // for(int i = 0; i < 4; i++){
    //     printf("i = %d\n", array[i]);
    // }

    // array = (int*)realloc(array, sizeof(int)*7);
    
    // for(int i = 0; i < 7; i++){
    //     array[i] = 2*i;
    // }

    // for(int i = 0; i < 7; i++){
    //     printf("i = %d\n", array[i]);
    // }

    test1();
    test1();

    test2();
    test2();

    return 0;
}