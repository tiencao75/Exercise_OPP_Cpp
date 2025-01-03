#ifndef TOWN_HPP
#define TOWN_HPP

#include <vector>
#include <memory>
#include "Family.hpp"

class Town {
private:
    std::vector<std::shared_ptr<Family>> familyList;

public:
    Town();
    void addFamily(std::shared_ptr<Family> family);
    void showDataTown() const;
};

#endif // TOWN_HPP
