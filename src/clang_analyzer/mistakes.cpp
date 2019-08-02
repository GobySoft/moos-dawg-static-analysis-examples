#include <string>

std::string* create()
{
    return new std::string("foo");
}


int main()
{
    // read/write off array
    char a[] = {1, 2, 3};
    ++a[4];

    // dead initialization
    int b = 2;
    int c = b / 3;
    
}

