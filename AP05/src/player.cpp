#include "player.hpp"

Player::Player(player_side pside)
{
    side = pside;
    death = false;
    health = INITIAL_HEALTH;
    player_sheeps = {timmy, shaun, timmy};
    player_healthbar = new Health(side);
}

Player::~Player()
{
}

void Player::taking_damage(int input_damage)
{
    health -= input_damage;
}

void Player::player_update()
{
    player_healthbar->health_update(health);
    if (health == 0)
    {
        death = true;
    }
}

void Player::player_render(RenderWindow &window)
{
    player_healthbar->health_render(window);
}

Health::Health(player_side side)
{
    if (!font.loadFromFile(FONTS_PATH + "HealthFont.otf"))
        debug("failed to load player texture");
    text.setFont(font);
    text.setFillColor(Color::Black);
    text.setCharacterSize(24);
    if (side == player_side::left)
    {
        text.setPosition(LEFT_PLAYER_HEALTHBAR);
    }
    else
    {
        text.setPosition(RIGHT_PLAYER_HEALTHBAR);
    }
}

Health::~Health()
{
}

void Health::health_update(int health)
{
    text.setString(to_string(health));
}

void Health::health_render(RenderWindow &window)
{
    window.draw(sprite);
    window.draw(text);
}

void Player::generate_sheep()
{
    int i = rand() % 10;
    if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4)
    {
        player_sheeps.insert(player_sheeps.begin(), timmy);
    }
    else if (i == 5 || i == 6 || i == 7)
    {
        player_sheeps.insert(player_sheeps.begin(), shaun);
    }
    else if (i == 8 || i == 9)
    {
        player_sheeps.insert(player_sheeps.begin(), meow);
    }
}