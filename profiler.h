#pragma once
#include <chrono>
#include <iostream>
#include <string>
#include "logger.h"

class Profiler
{
public:
    using time_point = std::chrono::time_point<std::chrono::system_clock>;

    Profiler(const QString &msg=""):
        start(std::chrono::system_clock::now()),
        msg(msg)
    {}
    ~Profiler()
    {
        finish = std::chrono::system_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::milliseconds>
                (finish - start);
        qDebug() << msg << " " << res.count() << "ms";
    }

private:
    time_point start;
    time_point finish;
    QString msg;
};
