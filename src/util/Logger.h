//
// Created by cFAG on 17/05/2020.
//

#pragma once

#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    std::ofstream stream;

    void prefix();
    void suffix(const std::string& message);

public:
    explicit Logger(const std::string& filename);
    ~Logger();

    void info(const std::string& message);
    void error(const std::string& message);
};
