#include <iostream>
#include "TaskManager.h"

/**
 * @brief Displays the main menu options
 */
void displayMenu()
{
    std::cout << "\n=== C++ TASK MANAGER ===\n";
    std::cout << "1. Add New Task\n";
    std::cout << "2. View All Tasks\n";
    std::cout << "3. Remove Task\n";
    std::cout << "4. Mark Task as Completed\n";
    std::cout << "5. Mark Task as Pending\n";
    std::cout << "6. Save Tasks to File\n";
    std::cout << "7. Load Tasks from File\n";
    std::cout << "8. Clear All Tasks\n";
    std::cout << "9. Exit\n";
    std::cout << "========================\n";
    std::cout << "Enter your choice (1-9): ";
}

/**
 * @brief Main function - program entry point
 * @return Exit status
 */
int main()
{
    TaskManager manager;
    int choice;
    const std::string filename = "tasks.txt";

    std::cout << "Welcome to the C++ Task Manager!\n";
    std::cout << "A professional to-do list application\n";

    // Main program loop
    while (true)
    {
        displayMenu();
        std::cin >> choice;

        // Input validation
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number 1-9.\n";
            continue;
        }

        // Menu logic using switch statement (conditionals requirement)
        switch (choice)
        {
        case 1:
        { // Add task
            std::cin.ignore();
            std::string desc;
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            manager.addTask(desc);
            break;
        }
        case 2: // View tasks
            manager.viewTasks();
            break;
        case 3:
        { // Remove task
            int id;
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;
            manager.removeTask(id);
            break;
        }
        case 4:
        { // Mark completed
            int id;
            std::cout << "Enter task ID to mark as completed: ";
            std::cin >> id;
            manager.markTaskCompleted(id);
            break;
        }
        case 5:
        { // Mark pending
            int id;
            std::cout << "Enter task ID to mark as pending: ";
            std::cin >> id;
            manager.markTaskPending(id);
            break;
        }
        case 6: // Save to file
            manager.saveToFile(filename);
            break;
        case 7: // Load from file
            manager.loadFromFile(filename);
            break;
        case 8: // Clear all
            manager.clearAllTasks();
            std::cout << "All tasks cleared.\n";
            break;
        case 9: // Exit
            std::cout << "\nThank you for using C++ Task Manager!\n";
            std::cout << "Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter 1-9.\n";
        }

        // Loop continues (while loop requirement)
    }

    return 0;
}