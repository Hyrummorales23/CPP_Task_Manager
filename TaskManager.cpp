#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// Constructor
TaskManager::TaskManager() : nextId(1) {}

/**
 * @brief Adds a new task to the manager
 * @param description The task description text
 */
void TaskManager::addTask(const std::string &description)
{
    tasks.push_back(Task(nextId++, description));
    std::cout << "Task added successfully! (ID: " << (nextId - 1) << ")\n";
}

/**
 * @brief Displays all tasks in a formatted table
 */
void TaskManager::viewTasks() const
{
    if (tasks.empty())
    {
        std::cout << "\nNo tasks found. Add some tasks first!\n";
        return;
    }

    std::cout << "\n"
              << std::string(60, '-') << "\n";
    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(40) << "Description"
              << std::setw(12) << "Status" << "\n";
    std::cout << std::string(60, '-') << "\n";

    for (const auto &task : tasks)
    {
        std::cout << std::left << std::setw(8) << task.getId()
                  << std::setw(40) << task.getDescription()
                  << std::setw(12) << (task.isCompleted() ? "✓ Done" : "◻ Pending") << "\n";
    }
    std::cout << std::string(60, '-') << "\n";
}

/**
 * @brief Finds the index of a task by ID
 * @param id The task ID to search for
 * @return Index if found, -1 if not found
 */
int TaskManager::findTaskIndex(int id) const
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Removes a task by ID
 * @param id The ID of the task to remove
 */
void TaskManager::removeTask(int id)
{
    int index = findTaskIndex(id);
    if (index != -1)
    {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task " << id << " removed successfully.\n";
    }
    else
    {
        std::cout << "Task " << id << " not found.\n";
    }
}

/**
 * @brief Marks a task as completed
 * @param id The ID of the task to mark
 */
void TaskManager::markTaskCompleted(int id)
{
    int index = findTaskIndex(id);
    if (index != -1)
    {
        tasks[index].markCompleted();
        std::cout << "Task " << id << " marked as completed.\n";
    }
    else
    {
        std::cout << "Task " << id << " not found.\n";
    }
}

/**
 * @brief Marks a task as pending
 * @param id The ID of the task to mark
 */
void TaskManager::markTaskPending(int id)
{
    int index = findTaskIndex(id);
    if (index != -1)
    {
        tasks[index].markPending();
        std::cout << "Task " << id << " marked as pending.\n";
    }
    else
    {
        std::cout << "Task " << id << " not found.\n";
    }
}

/**
 * @brief Saves all tasks to a text file (File I/O requirement)
 * @param filename The name of the file to save to
 */
void TaskManager::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    file << tasks.size() << "\n";
    for (const auto &task : tasks)
    {
        file << task.getId() << "\n"
             << task.getDescription() << "\n"
             << task.isCompleted() << "\n";
    }

    file.close();
    std::cout << "Tasks saved to '" << filename << "' successfully.\n";
}

/**
 * @brief Loads tasks from a text file (File I/O requirement)
 * @param filename The name of the file to load from
 */
void TaskManager::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Could not open file for reading.\n";
        return;
    }

    tasks.clear();
    int count;
    file >> count;
    file.ignore(); // Skip newline

    for (int i = 0; i < count; i++)
    {
        int id;
        std::string desc;
        bool completed;

        file >> id;
        file.ignore();
        std::getline(file, desc);
        file >> completed;
        file.ignore();

        Task task(id, desc);
        if (completed)
            task.markCompleted();
        tasks.push_back(task);

        if (id >= nextId)
            nextId = id + 1;
    }

    file.close();
    std::cout << "Tasks loaded from '" << filename << "' successfully.\n";
}

// Utility methods
int TaskManager::getTaskCount() const { return tasks.size(); }
void TaskManager::clearAllTasks()
{
    tasks.clear();
    nextId = 1;
}
