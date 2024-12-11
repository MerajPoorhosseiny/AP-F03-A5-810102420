#include "player.hpp"

Player::Player(player_side pside)
{
    side = pside;
    death = false;
    health = INITIAL_HEALTH;
    player_healthbar = new Health(side);
}

Player::~Player()
{
    
}

void Player::taking_damage(int input_damage)
{
    health -= input_damage;
}
