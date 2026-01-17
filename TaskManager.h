#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <string>

/**
 * @class TaskManager
 * @brief Manages a collection of Task objects with CRUD operations
 *
 * This class handles all business logic for the To-Do List application,
 * including file persistence using C++ file I/O.
 */
class TaskManager
{
private:
    std::vector<Task> tasks; ///< STL vector to store tasks
    int nextId;              ///< Tracks next available ID

    // Private helper methods
    int findTaskIndex(int id) const;

public:
    TaskManager();

    // Core CRUD operations
    void addTask(const std::string &description);
    void viewTasks() const;
    void removeTask(int id);
    void markTaskCompleted(int id);
    void markTaskPending(int id);

    // File I/O operations (meets additional requirement)
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

    // Utility
    int getTaskCount() const;
    void clearAllTasks();
};

#endif // TASKMANAGER_H