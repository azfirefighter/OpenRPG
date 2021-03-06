/*
characters - race.cpp
Created on: Apr 29, 2017

OpenRPG Software License - Version 1.0 - February 10th, 2017 <https://openrpg.io/about/license/>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
*/
#include <string>
#include <vector>
#include <cstdlib>

#include "core/utils.h"
#include "names.h"
#include "character.h"

using namespace std;
using namespace ORPG;

/**
 * Races currently assume 5e. What can we do to abstract outside of
 * that space?
 *
 * TODO(incomingstick): based on how much copy pasting I did, it is clear that
 * setting the name could get ugly quick if we don't turn as much of it into
 * functions as possible.
 **/
namespace ORPG {
    namespace Characters {
        /**
         * @desc This function returns a random RaceID as an integer, from
         * the available races.
         *
         * TODO(incomingstick): Is hardcoding this as a switch the best
         * option? This likely won't scale well.
         * 
         * @return uint - the randomly selected race ID
         **/
        const uint random_race_id() {
            switch(Utils::randomInt(0, 2)) {
            case 0 : {
                return Human::ID;
            }

            case 1 : {
                return HillDwarf::ID;
            }

            case 2 : {
                return HighElf::ID;
            }

            default: {
                return 0;
            }
            }
        }

        /**
         * @desc This function takes in an integer, ideally a Race::ID,
         * creates a new Race of that ID type and returns a pointer to it. If an ID
         * less than 0 is passed we instead will randomly select a Race type to return.
         * 
         * @param const int identifier - the RaceID of the race to be generated
         * 
         * @return Race* - a pointer to the newly created Race
         **/
        Race* select_race(const int identifier) {
            const auto id = (identifier < 0) ?
                random_race_id() : identifier;

            switch(id) {
            case Human::ID : {
                return new Human();
            }

            case Dwarf::ID : {
                return new Dwarf();
            }

            case HillDwarf::ID : {
                return new HillDwarf();
            }

            case Elf::ID : {
                return new Elf();
            }

            case HighElf::ID : {
                return new HighElf();
            }

            default: {
                return nullptr;
            }
            }
        }
    }

    /**
     * @desc Constructor for a Human that is passed no arguments. A base Human
     * has +1 to all stats. Human::Initialize() is called at the end of the
     * constructor.
     */
    Human::Human() {
        abilBonus = AbilityScores(1);

        Initialize();
    }

    /**
     * @desc Initialization for a Human that is passed no arguments.
     *
     * NOTE(incomingstick): Here we should finish setting up our race,
     * by doing everything that ALL Races of type Human should do.
     */
    void Human::Initialize() {
        // TODO Initialize the Human
    }

    /**
     * @desc apply the current Human's AbilityScores to the passed set
     * of AbilityScores located at the provided pointer location
     *
     * @param AbilityScores* - a pointer the base AbilityScores to
     * add to
     **/
    void Human::applyRacialBonus(AbilityScores* base) {
        *base = *base + abilBonus;
    }

    /**
     * @desc Constructor for a Dwarf that is passed no arguments. A base Dwarf
     * has +2 to CON. Dwarf::Initialize() is called at the end of the
     * constructor.
     */
    Dwarf::Dwarf() {
        abilBonus = AbilityScores(0);

        Initialize();
    }

    /**
     * @desc Initialization for a Dwarf that is passed no arguments.
     *
     * NOTE(incomingstick): Here we should finish setting up our race,
     * by doing everything that ALL Races of type Dwarf should do.
     */
    void Dwarf::Initialize() {
        abilBonus.set_score(CON, 2);     // Constitution
    }

    /**
     * @desc apply the current Dwarf's AbilityScores to the passed set
     * of AbilityScores located at the provided pointer location
     *
     * @param AbilityScores* - a pointer the base AbilityScores to
     * add to
     **/
    void Dwarf::applyRacialBonus(AbilityScores* base) {
        *base = *base + abilBonus;
    }

    /**
     * @desc Constructor for a HillDwarf that is passed no arguments. A base
     * HillDwarf has +2 to CON and +1 to WIS. HillDwarf::Initialize() is
     * called at the end of the constructor.
     */
    HillDwarf::HillDwarf() {
        abilBonus = AbilityScores(0);
        abilBonus.set_score(WIS, 1);     // Wisdom

        Initialize();
    }

    /**
     * @desc apply the current HillDwarf's AbilityScores to the passed set
     * of AbilityScores located at the provided pointer location
     *
     * @param AbilityScores* - a pointer the base AbilityScores to
     * add to
     **/
    void HillDwarf::applyRacialBonus(AbilityScores* base) {
        *base = *base + abilBonus;
    }

    /**
     * @desc Constructor for an Elf that is passed no arguments. A base Elf
     * has +2 to DEX. Elf::Initialize() is called at the end of the
     * constructor.
     */
    Elf::Elf() {
        abilBonus = AbilityScores(0);

        Initialize();
    }

    /**
     * @desc Initialization for an Elf that is passed no arguments.
     *
     * NOTE(incomingstick): Here we should finish setting up our race,
     * by doing everything that ALL Races of type Elf should do.
     */
    void Elf::Initialize() {
        abilBonus.set_score(DEX, 2);      // Dexterity
    }

    /**
     * @desc apply the current Elf's AbilityScores to the passed set
     * of AbilityScores located at the provided pointer location
     *
     * @param AbilityScores* - a pointer the base AbilityScores to
     * add to
     **/
    void Elf::applyRacialBonus(AbilityScores* base) {
        *base = *base + abilBonus;
    }

    /**
     * @desc Constructor for a HighElf that is passed no arguments. A base
     * HighElf has +2 to DEX and +1 to INT. Elf::Initialize() is called at the
     * end of the constructor.
     */
    HighElf::HighElf() {
        abilBonus = AbilityScores(0);
        abilBonus.set_score(INT, 1);      // Intelligence

        Initialize();
    }

    /**
     * @desc apply the current Elf's AbilityScores to the passed set
     * of AbilityScores located at the provided pointer location
     *
     * @param AbilityScores* - a pointer the base AbilityScores to
     * add to
     **/
    void HighElf::applyRacialBonus(AbilityScores* base) {
        *base = *base + abilBonus;
    }
}
