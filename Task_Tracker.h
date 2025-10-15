#pragma once
#include <string>
#include "JSON.h"

class Task_Tracker: protected JSON
{
private:
    int id = 0;
    std::string description = "";
    std::string status = "";
    std::string creation_date = "";
    std::string updated_date = "";

public:
    Task_Tracker();
    ~Task_Tracker();

    void add(const std::string &description);
    void remove(int task_id);
    void update(int task_id, const std::string &description);
    void list(const std::string &filter);
};