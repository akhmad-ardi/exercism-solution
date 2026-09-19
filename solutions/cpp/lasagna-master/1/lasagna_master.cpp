#include "lasagna_master.h"
#include <vector>
#include <string>

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> layers, int minutes) {
    return layers.size() * minutes;
}

amount quantities(std::vector<std::string> foodstuffs) {
    amount result{0, 0.0};

    for (std::string foodstuff: foodstuffs) {
        if (foodstuff == "noodles") {
            result.noodles += 50;
        }
        if (foodstuff == "sauce") {
            result.sauce += 0.2;
        }
    }

    return result;
}

void addSecretIngredient(std::vector<std::string>& reference, const std::vector<std::string>& otherReference) {
    if (!reference.empty() && !otherReference.empty()) {
        reference.back() = otherReference.back();
    }
}

void addSecretIngredient(std::vector<std::string>& myList, const std::string& secret) {
    if (!myList.empty()) {
        myList.back() = secret;
    }
}

std::vector<double> scaleRecipe(std::vector<double> quantities, int number_of_portions) {
    double portions = static_cast<double>(number_of_portions);
    std::vector<double> result;
    
    for (double quantity: quantities) {
        result.push_back(quantity * portions / 2);
    }

    return result;
}

}  // namespace lasagna_master
