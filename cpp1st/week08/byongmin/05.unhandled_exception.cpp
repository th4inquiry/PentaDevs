#include <iostream>
#include <exception>

void customTerminate()
{
    std::cout << "Uncaught exception!" << std::endl;
    exit(-1);
}

int main()
{
    try
    {
        std::set_terminate(customTerminate);
        throw std::runtime_error("runtime exception error.");
    }
    catch (...)
    {
        if (std::terminate_handler() != nullptr)
        {
            std::terminate_handler();
        }
        else
        {
            std::terminate();
        }
    }

    return 0;
}