#include "sheep.hpp"

Sheep::Sheep(int player_pos, Vector2f position, sheep_type tof, Setting *game_setting)
{

    setting = game_setting;
    type_of_sheep = tof;
    sheep_side = player_pos;
    face_off = false;
    setup_sheep_info();
    sheep_pos = position;
    set_sheep_texture();
    IntRect rect;
    rect.top;
    rect.left;
    rect.width;
    rect.height;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(0, 0);
}

void Sheep::reset_speed(int current_strength)
{
    sheep_info.speed = current_strength * 2;
}

void Sheep::collision()
{
    face_off = true;
}

void Sheep::rendering(RenderWindow &window)
{
    window.draw(sprite);
}

void Sheep::setup_sheep_info()
{
    switch (type_of_sheep)
    {
    case (timmy):
        sheep_info.damage = setting->timmy.damage;
        sheep_info.strength = setting->timmy.strength;
        sheep_info.speed = setting->timmy.speed;
        sheep_info.displayProb = setting->timmy.displayProb;
        break;
    case (shaun):
        sheep_info.damage = setting->shaun.damage;
        sheep_info.strength = setting->shaun.strength;
        sheep_info.speed = setting->shaun.speed;
        sheep_info.displayProb = setting->shaun.displayProb;
        break;
    case (meow):
        sheep_info.damage = setting->meow.damage;
        sheep_info.strength = setting->meow.strength;
        sheep_info.speed = setting->meow.speed;
        sheep_info.displayProb = setting->meow.displayProb;
        break;
    }
}

void Sheep::set_sheep_texture()
{
    if (type_of_sheep == timmy)
    {
        if (face_off)
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + "white_sheep_stand.png"))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + "black_sheep_stand.png"))
                    debug("failed to load zombie texture");
            }
        }
        else
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + "white_sheep_move.png"))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + "black_sheep_move.png"))
                    debug("failed to load zombie texture");
            }
        }
    }
    if (type_of_sheep == shaun)
    {
        if (face_off)
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + "white_goat_stand.png"))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + "black_goat_stand.png"))
                    debug("failed to load zombie texture");
            }
        }
        else
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + "white_goat_move.png"))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + "black_goat_move.png"))
                    debug("failed to load zombie texture");
            }
        }
    }
    if (type_of_sheep == meow)
    {
        if (face_off)
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + ""))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + ""))
                    debug("failed to load zombie texture");
            }
        }
        else
        {
            if (sheep_side == RIGHT_PLAYER)
            {
                if (!texture.loadFromFile(PICS_PATH + ""))
                    debug("failed to load zombie texture");
            }
            else
            {
                if (!texture.loadFromFile(PICS_PATH + ""))
                    debug("failed to load zombie texture");
            }
        }
    }
}

int Sheep::get_line()
{
    if (sheep_pos.y == 65)
        return 1;
    if (sheep_pos.y == 165)
        return 2;
    if (sheep_pos.y == 265)
        return 3;
    if (sheep_pos.y == 365)
        return 4;
    if (sheep_pos.y == 465)
        return 5;
}

FloatRect Sheep::get_rect()
{
    return sprite.getGlobalBounds();
}

void Sheep::update_sheep()
{
    handle_sheep_animation();
    if (!face_off)
        sheep_pos.x -= sheep_info.speed;
    sprite.setPosition(sheep_pos);
}