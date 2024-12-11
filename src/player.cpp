#include "player.hpp"

Player::Player(player_side pside)
{
    side = pside;
    death = false;
    health = INITIAL_HEALTH;
    player_healthbar = new Health(side);
}
