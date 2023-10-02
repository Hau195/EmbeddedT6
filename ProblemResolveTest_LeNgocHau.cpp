#include <iostream>
#include <string>

using namespace std;

int solution(int A, int B)
{
    string so_A;
    string so_B;
    string so_C;
    int size;
    so_A = to_string(A);
    so_B = to_string(B);

    if(so_A.length() <= so_B.length()) {size = so_A.length();}
    else {size = so_B.length();}

    for(int i = 0; i < size; i++)
    {
        so_C.push_back(so_A[i]);
        so_C.push_back(so_B[i]);
    }

    if(size == so_A.length())
    {
        for(int i = size; i < so_B.length(); i++)
        {
            so_C.push_back(so_B[i]); 
        }
    }
    else
    {
        for(int i = size; i < so_A.length(); i++)
        {
            so_C.push_back(so_A[i]); 
        }
    }
    if(so_C.length()> 8){return -1;};
    return stoi(so_C);
}

int main(int argc, char const *argv[])
{
    int result = solution(1234,123);
    cout<< result <<endl;
    return 0;
}