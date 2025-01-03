#ifndef WORKER_HPP
#define WORKER_HPP

#include "Officer.hpp"
#include <string>
using namespace std;

class Worker : public Officer {
private:
    int level;

public:
    Worker(string name, int age, string gender, string address, int level);
    int getLevel() const;
    void setLevel(int newLevel);
    string showInfo() const override;
};

#endif
