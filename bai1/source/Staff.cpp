#include "Staff.hpp"

Staff::Staff(string name, int age, string gender, string address, string task)
    : Officer(name, age, gender, address), task(task) {}

string Staff::getTask() const { return task; }
void Staff::setTask(const string &newTask) { task = newTask; }

string Staff::showInfo() const {
    return Officer::showInfo() + ", Task: " + task;
}