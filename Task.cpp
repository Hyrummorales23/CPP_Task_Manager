#include "Task.h"

/**
 * @brief Constructs a new Task object
 * @param taskId Unique identifier for the task
 * @param desc Description of the task
 */
Task::Task(int taskId, const std::string &desc)
    : id(taskId), description(desc), completed(false) {}

// Getters
int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::isCompleted() const { return completed; }

// Setters
void Task::setDescription(const std::string &desc) { description = desc; }
void Task::markCompleted() { completed = true; }
void Task::markPending() { completed = false; }

/**
 * @brief Returns a string representation of the task
 * @return Formatted string with task details
 */
std::string Task::toString() const
{
    return "ID: " + std::to_string(id) +
           " | Description: " + description +
           " | Status: " + (completed ? "Completed" : "Pending");
}