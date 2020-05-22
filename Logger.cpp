//
// Created by cFAG on 17/05/2020.
//

#include "Logger.h"

using namespace std;

Logger::Logger(const string &filename) {
    stream.open(filename.c_str());
}

Logger::~Logger() {
    stream.close();
}

void Logger::prefix() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = 1 + ltm->tm_hour;
    int minute = 1 + ltm->tm_min;
    int second = 1 + ltm->tm_sec;

    stream << "== "
           << day << "/" << month << "/" << year
           << " "
           << hour << ":";
    if (minute < 10)
        stream << "0";
    stream << minute << ":";
    if (second < 10)
        stream << "0";
    stream << second
           << " == ";
}

void Logger::info(const std::string &message) {
    prefix();
    stream << "[INFO] ";
    suffix(message);
}

void Logger::error(const std::string &message) {
    prefix();
    stream << "[ERROR] ";
    suffix(message);
}

void Logger::suffix(const std::string &message) {
    stream << message << endl;
}