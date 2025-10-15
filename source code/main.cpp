#include <iostream>
#include "Task_Tracker.h"
#include "headers.h"

int main(int argc, char *argv[])
{
    if (argc == 0 || argv == nullptr)
    {
        std::cout << "Hello and Welcome to Task Tracker CLI!\n";
        std::cout << "Type 'help' to see a list of commands.\n";
        return 0;
    }
    else if (argc == 2)
    {
        unsigned long hashed_command = hash_cstr(argv[1]);
        switch (hashed_command)
        {
            case hash_cstr("help"):
            {
                std::cout << "Available commands:\n";
                std::cout << "  add <task_description> - Add a new task\n";
                std::cout << "  remove <task_id> - Remove a task by its ID\n";
                std::cout << "  update <task_id> <new_description> - Update a task's description\n";
                std::cout << "  list [filter] - List all tasks, optionally filtered by a keyword\n";
                std::cout << "  help - Show this help message\n";
                return 0;
            }
            case hash_cstr("add"):
            {
                if (argc < 3)
                {
                    std::cout << "Error: Task description is required for 'add' command.\n";
                    return 1;
                }
                std::string description = argv[2];
                Task_Tracker tracker;
                tracker.add(description);
                std::cout << "Task added successfully.\n";
                return 0;
            }
            case hash_cstr("remove"):
            {
                if (argc < 3)
                {
                    std::cout << "Error: Task ID is required for 'remove' command.\n";
                    return 1;
                }
                int task_id = std::stoi(argv[2]);
                Task_Tracker tracker;
                tracker.remove(task_id);
                std::cout << "Task removed successfully.\n";
                return 0;
            }
            case hash_cstr("update"):
            {
                if (argc < 4)
                {
                    std::cout << "Error: Task ID and new description are required for 'update' command.\n";
                    return 1;
                }
                int task_id = std::stoi(argv[2]);
                std::string new_description = argv[3];
                Task_Tracker tracker;
                tracker.update(task_id, new_description);
                std::cout << "Task updated successfully.\n";
                return 0;
            }
            case hash_cstr("list"):
            {
                std::string filter = (argc == 3) ? argv[2] : "";
                Task_Tracker tracker;
                tracker.list(filter);
                return 0;
            }
            default:
            {
                std::cout << "Unknown command. Type 'help' to see a list of commands.\n";
                return 1;
            }
        }
    }
    else
    {
        std::cout << "Invalid number of arguments. Type 'help' to see a list of commands.\n";
        return 1;
    }
}