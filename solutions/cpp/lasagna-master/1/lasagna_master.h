#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int minutes = 2);
amount quantities(std::vector<std::string>);
void addSecretIngredient(std::vector<std::string>& reference, const std::vector<std::string>& otherReference);
void addSecretIngredient(std::vector<std::string>& myList, const std::string& secret);
std::vector<double> scaleRecipe(std::vector<double> quantities, int number_of_portions);
}  // namespace lasagna_master
