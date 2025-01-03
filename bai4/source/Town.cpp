#include "Town.hpp"
#include <iostream>

Town::Town() {}

void Town::addFamily(std::shared_ptr<Family> family) {
    familyList.push_back(family);
}

// Show all families in the town
void Town::showDataTown() const {
    if (familyList.empty()) {
        std::cout << "No families in the town yet.\n";
        return;
    }

    std::cout << "\nTown Data:\n";
    for (size_t i = 0; i < familyList.size(); ++i) {
        std::cout << "Family " << i + 1 << ": " << familyList[i]->showInfor() << "\n";
    }
}
