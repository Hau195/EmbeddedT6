# EmbeddedT6
## Lesson 4: Build process in C
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
## Lesson 5: Pointer
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
## Lesson 6: Memory Layout
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
## Lesson 7: Variable type
### Static
 *  Biến static là biến chỉ khởi tạo 1 lần trong khi chạy chương trình.
 *  Biến static chứa trong phân vùng data không phải stack
 *  Được khởi tạo = 0 nếu k được khởi tạo từ programmer.
 *  Biến static toàn cục và hàm static toàn cục chỉ được truy cập trong cyngf 1 file nếu khác thì không truy cập được.
### Extern
 * Từ khóa extern dùng để tìm kiếm biến đó ngoài phạm vi của file
### Volatile
 * Là biến thay đổi liên tục khi chương trình chạy và dùng để nói với chương trình là không được tối ưu biến đó.
## Lesson 7: Binary search

## Lesson 8: Linked list và binary search

## Lesson 9: C++: class
### Public:
* Có thể truy cập ở mọi nơi
### Protected:
* Truy cập ở nội bộ class và class con
### Private:
* Chỉ nội bộ class
### Virtual function:
## Lesson 10: C++ OOP
### Kế thừa
* Kế thừa Public:
  - Ở class cha là public và protected thì lớp con giữ nguyên
* Kế thừa Protected:
  - Ở class cha là public và protected thì lớp con là Protected
* Kế thừa Private:
  - Ở class cha là public và protected thì lớp con là Private
### Trừu tường
* Để cấu thành lên chương trình lớn thì cần các chương trình con nhưng bị giấu người dùng chỉ có thể truy cập ở chương trình lớn.
### Đóng gói
* Chỉ cho pháp truy cập các properties thông qua các method.
### Đa hình
* 2 hàm cùng tên khác input argument
* Template là vid dụ tính đa hình
  syntax: template <typename bien1, >
##Lesson11: C++ vector, list
### Vector:
* syntax: vector<int> vt;
* Tạo ra mảng động
* Vị trí vùng nhớ liên tiếp nhau
Vd: array.insert(array.begin()+2,35);
* For (int item : array)
  {
       cout<<item<<;
  }
### List:
* Các vị trí vùng nhớ không liên tiếp nhau
* Khai báo:
     list<int> lt;
* Cách duyệt list
  list<int>::iterator it;
  for(it = lt.begin(); it != lt.end(); it++)
  {
  }
