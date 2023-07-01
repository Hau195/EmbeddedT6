#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>


uint16_t random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 10000);
    }
    return ptr; 
}

void sort(uint16_t arr[], uint64_t length)
{   
    uint16_t temp;
    for(uint16_t i = 0; i < length - 1; i++)
    {
        for(uint16_t j = i + 1; j < length; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;        
            }
        }
    }
}

// uint16_t find_Number(uint16_t arr[], uint64_t length, uint16_t num)
// {
//     int exist_flag = 0;

//     int high_range = length;
//     int low_range = 0;
//     int pre_lowrange = 0;
//     int pre_highrange = length;

//     length = (high_range + low_range)/2;

//     while(length >= 1)
//     {
//         if(num < arr[length])
//         {
//             printf("LOW %d, ", arr[length]);

//             printf("high_range %d, ", length);

//             printf("pre_lowrange %d, ", pre_lowrange);
            
//             printf("%d\n ", length);

//             pre_highrange = length;

//             high_range = length;
//             low_range = pre_lowrange;

//             length = (high_range + low_range)/2;

            

//             if(high_range - low_range == 1)
//             {
//                 exist_flag = 0;
//                 break;
//             }
//         }
//         else if (num > arr[length])
//         {
//             printf("HIGH %d, ", arr[length]);

//             printf("Pre_highrange %d, ", pre_highrange);

//             printf("lowrange %d, ", length);

//             printf("%d\n ", length);

//             pre_lowrange = length;

//             high_range = pre_highrange;
//             low_range = length;
//             length = (high_range + low_range)/2;

            
//             if(high_range - low_range == 1)
//             {
//                 exist_flag = 0;
//                 break;
//             }
            
//         }
//         else if (num == arr[length])
//         {

//             printf("EQUAL %d, ", arr[length]);
//             printf("%d\n ", length);

//             exist_flag = 1;
//             break;
//         }
//         else
//         {
//             exist_flag = 0;
//             break;
//         }
        
//     }
//     if(exist_flag == 1) return length;
//     else if(exist_flag == 0) return 0;
    
// }

uint16_t find_Number2(uint16_t arr[], uint64_t length, uint16_t target_num)
{
    uint16_t first = 0;
    uint16_t last = length - 1;
    while(first <= last)
    {
        int midpoint = (last + first) / 2;
        if(target_num < arr[midpoint])
        {
            last = midpoint - 1;
            printf("LOW_last %d, ", last);
            printf("LOW_first %d \n ", first);

        }
        else if(target_num > arr[midpoint])
        {  
            first = midpoint + 1;
            printf("HIGH_last %d, ", last);
            printf("HIGH_first %d \n ", first);
        }
        else if(target_num == arr[midpoint])
        {
            printf("EQUAL %d \n ", midpoint);
            return midpoint;
        }
    }

    printf("Not found");
    return 0; 
}



int main(int argc, char const *argv[])
{
   uint16_t *array = createArray(1000);

   sort(array, 1000);

   int num_index = find_Number2(array,1000,120);

   printf("%d : ", num_index);
   printf("%d\n ", array[num_index]);
//    for(int i = 0; i< 10000; i++)
//    {
//         printf("%d, ", array[i]);
//    }
    return 0;
}


