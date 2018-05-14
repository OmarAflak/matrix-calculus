#ifndef UTILS
#define UTILS

#include <string>

bool hasFlag(const std::string& arg, const int& argc, char const *argv[]);
bool hasArg(const std::string& arg, const int& argc, char const *argv[]);
std::string getArg(const std::string& arg, const int& argc, char const *argv[]);

#endif
