#include <csignal>
#include <iostream>
#include <cstdlib>

class Tester
{
    public:
    Tester() 
    {
        std::cout << "Tester ctor\n";
    }
    ~Tester()
    {
        std::cout << "Tester dtor\n";
    }
};

Tester static_tester; //Destuctor not called

//Causes abnormal program termination unless SIGABRT is being caught by a signal by a signal handler passed to std::signal and the handler does not return.
void signal_handler(int signal)
{
    if (signal == SIGABRT)
    {
        std::cerr << "SIGABRT received\n";
    }
    else
    {
        std::cerr << "Unexpected signal " << signal << " received\n";
    }
    std::_Exit(EXIT_FAILURE);
}

int main()
{
    //Destructors of variables with automatic, thread local (since C++11) and static storage durations are not called.
    //Functions registered with std::atexit() and std::at_quick_exit (since C++11) are also not called.
    Tester automatic_tester;

    //Setup handler
    auto previous_handler = std::signal(SIGABRT, signal_handler);
    if (previous_handler == SIG_ERR)
    {
        std::cerr << "Setup failed\n";
        return EXIT_FAILURE;
    }

    std::abort(); //Raise SIGABRT
    std::cout << "This code is unreachable\n";
}

