#include <iostream>

int main(int argc, char *argv[])
{
    unsigned int    i;
    unsigned int    j;
    std::string caps;

    if (argc > 1)
    {
        for (j = 1; argv[j] != NULL; j++)
        {
            caps = argv[j];
            for (i = 0; i < caps.length(); i++)
                caps[i] = ::toupper(caps[i]);
            std::cout << caps;
        }
        // std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}