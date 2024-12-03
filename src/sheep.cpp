#include "sheep.hpp"

Sheep::Sheep(string sheep_name,int player_pos)
{
    for(auto it = SHEEP_CONFIGS.begin();it != SHEEP_CONFIGS.end();it++)
    {
        if (it->name == sheep_name)
        {
            sheep_info.name = it ->name;
            sheep_info.damage = it ->damage;
            sheep_info.strength = it ->strength;
            sheep_info.displayProb = it ->displayProb;
        }
        
    }

    sheep_side = player_pos;
    face_off = false;
}

void Sheep::reset_speed(int current_strength)
{
    sheep_speed = current_strength*2;
}

void Sheep::collision()
{
    face_off = true;
}