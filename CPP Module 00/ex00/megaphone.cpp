#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 1;

    char x;

    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    while(argc != j)
    {
        while(argv[j][i])
        {
            x = toupper(argv[j][i]);
            std::cout << x;
            i++;
        }
        j++;
        i = 0;
    }
    return 0;
    
}
