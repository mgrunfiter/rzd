#pragma once
#include <chrono>
#include <iostream>
#include <string>

class Profiler
{
public:
    using time_point = std::chrono::time_point<std::chrono::system_clock>;

    Profiler(const std::string &msg=""):
        start(std::chrono::system_clock::now()),
        msg(msg)

    {}
    ~Profiler()
    {
        finish = std::chrono::system_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::milliseconds>
                (finish - start);
        std::cout << msg << " " << res.count() << "ms" << std::endl;
    }

private:
    time_point start;
    time_point finish;
    std::string msg;
};
