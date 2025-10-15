#pragma once
#include <string>

class JSON
{
protected:
    JSON();
    ~JSON();
    void parse(const std::string &JSON_filename);
    void stringify(const std::string &output_filename);
};