namespace targets {
// TODO: Insert the code for the alien class here
class Alien {
  public:
  int x_coordinate{};
  int y_coordinate{};

  Alien(int x, int y): x_coordinate{x}, y_coordinate{y} {}

  int get_health() const {
    return health;
  }
  bool hit() {
    if (health < 1) {
      return false;
    }
    health--;
    return true;
  }
  bool is_alive() {
    if (health < 1) {
      return false;
    }
    return true;
  }
  bool teleport(int x, int y) {
    x_coordinate = x;
    y_coordinate = y;
    return true;
  }
  bool collision_detection(Alien alien) {
    if (x_coordinate == alien.x_coordinate && y_coordinate == alien.y_coordinate) {
      return true;
    }
    return false;
  }

  private:
  int health{3};
};
}  // namespace targets
