#include "raindrops.h"
#include <string>

namespace raindrops {

// TODO: add your solution here
std::string convert(int number) {
  if (number % 3 == 0 && number % 3 == 5) {
    return "PlingPlang";
  } else if (number % 3 == 0) {
    return "Pling";
  } else if (number % 5 == 0) {
    return "Plang";
  } else if (number % 7 == 0) {
    return "Plong";
  } else {
    return std::to_string(number);
  }
}
}  // namespace raindrops
