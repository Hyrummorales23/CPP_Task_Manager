#ifndef TASK_H
#define TASK_H

#include <string>

/**
 * @class Task
 * @brief Represents a single task with description and completion status
 *
 * This class encapsulates the data and behavior of a to-do item.
 * It follows object-oriented principles with proper encapsulation.
 */
class Task
{
private:
    int id;                  ///< Unique identifier for the task
    std::string description; ///< Task description
    bool completed;          ///< Completion status

public:
    // Constructor
    Task(int taskId, const std::string &desc);

    // Getters
    int getId() const;
    std::string getDescription() const;
    bool isCompleted() const;

    // Setters
    void setDescription(const std::string &desc);
    void markCompleted();
    void markPending();

    // Utility
    std::string toString() const;
};

#endif // TASK_H
