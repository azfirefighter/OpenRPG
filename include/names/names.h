/*
name-generator - names.h
Created on: Nov 10, 2016

OpenRPG Software License - Version 1.0 - February 10th, 2017 <https://openrpg.io/about/license/>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
*/
#ifndef SRC_GENERATOR_H_
#define SRC_GENERATOR_H_

namespace ORPG {
    namespace Names {
        void print_version_flag();
        void print_help_flag();
        void print_basic_version();
        void print_basic_help();
    }

    class NameGenerator {
    private:
        std::string location;

    public:
        std::string race;
        std::string subrace;
        std::string gender;

        NameGenerator(std::string _race = "dwarf");
        NameGenerator(std::string _race, std::string _gender);

        std::string make_name();
        std::string make_first();
        std::string make_last();
    };
}

#endif /* SRC_GENERATOR_H_ */
