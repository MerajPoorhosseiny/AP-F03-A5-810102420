#pragma once

#include "global.hpp"

struct Sheep_configs
{
    int damage;
    int strength;
    int speed;
    float displayProb;
};

class Setting{
public:
    Setting();
    Sheep_configs timmy;
    Sheep_configs shaun;
    Sheep_configs meow;
private:
    int str_to_num(string input);
    void get_sheep_setting(string line);
    float string_to_float(const std::string &str);
};