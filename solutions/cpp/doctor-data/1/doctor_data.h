#include <string>
#pragma once

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
        public:
            std::string name;
            star_map::System current_system;
            int generation;
            int busters{0};

            Vessel(std::string name, int generation, star_map::System system = star_map::System::BetaHydri);

            Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();
    };

    std::string get_older_bob(Vessel vessel_1, Vessel vessel_2);
    bool in_the_same_system(Vessel vessel_1, Vessel vessel_2);
}