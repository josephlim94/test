#include <sys/ioctl.h>
#include <pthread.h>
#include <iostream>
#include <thread>

void testFunc()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    std::cout << "lines: " << w.ws_row << std::endl;
    std::cout << "columns: " << w.ws_col << std::endl;
}

int main()
{
    std::thread first(testFunc);

    first.join();

    std::cout << "thread complete" << std::endl;
    return 0;
}
