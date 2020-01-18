/*
platform - unix.cpp
Created on: Jan 17, 2020

OpenRPG Software License - Version 1.0 - February 10th, 2017 <https://openrpg.io/about/license/>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
 */
#include "core/platform/unix.h"

#include <limits.h>
#include <unistd.h>

#include <string>

using namespace std;

const char* EXEC_PATH() {
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    return std::string(path, (count > 0) ? count : 0).c_str();
}
