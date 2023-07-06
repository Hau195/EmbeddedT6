# EmbeddedT6
## Lession 4: Build process in C
![Build process](https://fastbitlab.com/wp-content/uploads/2022/07/Figure-2-1-800x409.png)

### Preprocessing là bước đầu tiên trong quá trình build của C
 * File đầu vào của quá trình này là *.c file.
 * File đầu ra của quá trình này là  *.i .
 * Bỏ comment và thực hiện các macro.
 * Syntax: gcc -E main.c - o main.i
### Compiler
 * File đầu vào của quá trình này là *.i file.
 * File đầu ra của quá trình này là *.s file.
 * Syntax gcc main.i -S -o main.s
### Assembler: 
 * File đầu vào của quá trình này là *.asm file.
 * File đầu ra của quá trình này là *.o hay *.obj file + library.
 * Syntax: gcc - c main.s -o main.o
### Linker:
![Linker](https://media.licdn.com/dms/image/C4E12AQE48SgStVLuMA/article-inline_image-shrink_1000_1488/0/1567694279315?e=1692230400&v=beta&t=5pVG0bwLO2OtYWj8W6HvFUrESDrECaSz3FimkivtKE8)
 * File đầu vào của quá trình này là *.o file, and c standard libraries .
 *  File đầu ra của quá trình này là relocatable file.
## Lession 5: Pointer
### Integer pointer:
 * Pointer trỏ đến integer variable int * <name>.
### Void pointer:
 * Trỏ đến bất kỳ kiểu dữ liệu nào nhưng cần phải ép kiểu.
### NULL pointer:
 * Con trỏ không trỏ đi đâu int * ptr = NULL/0.
 * Ngăn trỏ vào địa chỉ rác hoặc có thể trùng địa chỉ vs 1 biến khác.
### FUNC pointer:
 * Trỏ đến hàm:
     void(*ptr)(int, int);
### Pointer to pointer:
 * Con trỏ trỏ đến địa chỉ của con trỏ kháckhác.
## Lession 6: Memory Layout
![Memory layout](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)
### Text
 * Chỉ đọc, chứa các chỉ dẫn, hằng số
### Initialized Data Segment (data)
 * Có thể đọc và ghi
 * Chứa global variables và static variables được có giá trị khởi đầu gán bởi programmer.
 * Free when program is end.
### Uninitialized Data Segment (bss)
 * Có thể đọc và ghi
 * Chứa global variables and static variables khởi đầu với giá trị 0 hoặc k có giá trị khởi đầu.
 * Free when program is end.
### Stack
 * The stack area chứa stack của chương trình, LIFO structure, ở vùng trên cùng của bộ nhớ.
 * Stack, chưa các biến cục bộ và các thông tin khi func được gọi.
 * Read-writ
 * Free when out of function
### Heap
 * Heap is the segment của bộ nhớ động: malloc, calloc, realloc.
 * Read and write
 * Free when use free func.
### Difference between Heap and Stack
 * Stack là bộ nhớ cứng dung lượng 1MB với window và 8MB Linux và truy cập nhanh hơn Heap. Auto free when out func. 
 * Heap is bộ nhớ động với dynamic memmory capacity and free by programmer.
### Error
 * Stack overflow (xử dụng quá nhiều vùng nhớ)
 * Heap overflow (không giải phóng vùng nhớ)
 * Memmory leak.
 * Dangling pointer.
## Lession 7: Variable type
### Static
 *  A static variable preserves its previous value in its previous scope and is not initialized again in the new scope.
 *  Static variables are allocated memory in the data segment, not the stack segment.
 *  Static variables (like global variables) are initialized as 0 if not initialized explicitly.
 *  Static global variables and functions are also possible in C/C++. The purpose of these is to limit the scope of a variable or function to a file. Access to static functions is restricted to the file where they are declared
### Extern
 * Extern keyword in C applies to C variables (data objects) and C functions. Basically, the extern keyword extends the visibility of the C variables and C functions.
### Volatile
 * Variable that changing while program is running and it used to tell compiler not to optimaze this line code.
