#include <string>
#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(std::string name, int generation, star_map::System system) {
        this->name = name;
        this->generation = generation;
        this->current_system = system;
    }

    Vessel Vessel::replicate(std::string name) {
        return Vessel{name, 2, star_map::System::Sol};
    }

    void Vessel::make_buster() {
        this->busters++;
    }

    bool Vessel::shoot_buster() {
        if (this->busters < 1) {
            return false;
        }
        this->busters--;
        return true;
    }

    std::string get_older_bob(Vessel vessel_1, Vessel vessel_2) {
        if (vessel_1.generation < vessel_2.generation) {
            return vessel_1.name;
        } else {
            return vessel_2.name;
        }
    }

    bool in_the_same_system(Vessel vessel_1, Vessel vessel_2) {
        return vessel_1.current_system == vessel_2.current_system;
    }
}