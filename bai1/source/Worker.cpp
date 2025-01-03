#include "Worker.hpp"

Worker::Worker(string name, int age, string gender, string address, int level)
    : Officer(name, age, gender, address), level(level) {}

int Worker::getLevel() const { return level; }
void Worker::setLevel(int newLevel) { level = newLevel; }

string Worker::showInfo() const {
    return Officer::showInfo() + ", Level: " + to_string(level);
}