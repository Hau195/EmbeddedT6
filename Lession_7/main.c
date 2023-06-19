#include <stdio.h>

extern void display();
extern int count;

void counter(){
    static int temp = 0;
    printf("%d", temp);
    temp++;
}



int main(int argc, char const *argv[])
{

    // while (1)
    // {
    //  volatile int data = readADC(); //0-1024
     
    //  A();
     
    //  B();

    // }

    display(); display();

    // counter();
    // counter();
    // counter();

    
    return 0;
}