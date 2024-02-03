#include <iostream>
#include <vector>
#include <string>

// Структура для представления задачи
struct Task {
    int id;
    std::string description;
    bool completed;
};

// Функция для добавления новой задачи
void addTask(std::vector<Task> &tasks, int &taskId, std::string description) {
    Task newTask = {taskId, description, false};
    tasks.push_back(newTask);
    taskId++;
}

// Функция для удаления задачи по её идентификатору
void deleteTask(std::vector<Task> &tasks, int taskId) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == taskId) {
            tasks.erase(it);
            break;
        }
    }
}

// Функция для обновления информации о задаче
void updateTask(std::vector<Task> &tasks, int taskId, std::string newDescription, bool newCompleted) {
    for (auto &task : tasks) {
        if (task.id == taskId) {
            task.description = newDescription;
            task.completed = newCompleted;
            break;
        }
    }
}

// Функция для отображения информации обо всех задачах
void displayTasks(const std::vector<Task> &tasks) {
    for (const auto &task : tasks) {
        std::cout << "ID: " << task.id << ", Описание: " << task.description << ", Выполнено: " << (task.completed ? "Да" : "Нет") << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int taskId = 1;
    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить новую задачу" << std::endl;
        std::cout << "2. Удалить задачу" << std::endl;
        std::cout << "3. Обновить задачу" << std::endl;
        std::cout << "4. Показать все задачи" << std::endl;
        std::cout << "5. Выход" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string description;
            std::cout << "Введите новое описание задачи: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            addTask(tasks, taskId, description);
        } else if (choice == 2) {
            int taskId;
            std::cout << "Введите ID задачи на удаление: ";
            std::cin >> taskId;
            deleteTask(tasks, taskId);
        } else if (choice == 3) {
            int taskId;
            std::string newDescription;
            bool newCompleted;
            std::cout << "Введите ID задачи на обновление: ";
            std::cin >> taskId;
            std::cout << "Введите новое описание задачи: ";
            std::cin.ignore();
            std::getline(std::cin, newDescription);
            std::cout << "Задача выполнена? (1 - Да, 0 - Нет) ";
            std::cin >> newCompleted;
            updateTask(tasks, taskId, newDescription, newCompleted);
        } else if (choice == 4) {
            displayTasks(tasks);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Неправильный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
