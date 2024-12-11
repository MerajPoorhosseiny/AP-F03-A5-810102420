#include "sheep.hpp"

Sheep::Sheep(int player_pos, Vector2f position, sheep_type tof, int intery_line, Setting *game_setting)
{

    setting = game_setting;
    type_of_sheep = tof;
    sheep_side = player_pos;
    face_off = false;
    setup_sheep_info();
    sheep_pos = position;
    set_sheep_texture();
    IntRect rect;
    rect.top = 160;
    if (sheep_side == RIGHT_PLAYER)
    {
        rect.left = 1770;
    }
    else
    {
        rect.left = 115;
    }
    rect.width = 91;
    rect.height = 60;
    current_line = intery_line;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
}

void Sheep::reset_speed(int current_strength)
{
    sheep_info.speed = current_strength * 2;
}

int Sheep::get_power()
{
    return sheep_info.strength;
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

void Sheep::handle_sheep_animation()
{
    if (face_off)
        set_sheep_texture();
    else
        set_sheep_texture();
    Time animationelapsed = animation_render_time.getElapsedTime();
    if (animationelapsed.asMilliseconds() >= 100)
    {
        animation_render_time.restart();
        if (type_of_sheep == timmy)
        {
            current_rect = (current_rect + 1) % 3;
        }
        else if (type_of_sheep == shaun)
        {
            current_rect = (current_rect + 1) % 8;
        }

        IntRect rect;
        rect.top = 2;
        if (type_of_sheep == timmy)
        {
            rect.left = SHEEP_ANIMATION_X_REXT[current_rect];
        }
        else if (type_of_sheep == shaun)
        {
            rect.left = GOAT_ANIMATION_X_REXT[current_rect];
        }
        if (type_of_sheep == timmy)
        {
            rect.width = 90;
        }
        if (type_of_sheep == shaun)
        {
            rect.width = 73;
        }
        if (type_of_sheep == timmy)
        {
            rect.height = 60;
        }
        if (type_of_sheep == timmy)
        {
            rect.height = 78;
        }
        sprite.setTextureRect(rect);
    }
}

bool Sheep::is_out()
{
    if (sheep_side == RIGHT_PLAYER)
    {
        return sprite.getPosition().x > LEFT_LINE_LOCATIONS[0].x;
    }
    if (sheep_side == LEFT_PLAYER)
    {
        return sprite.getPosition().x > RIGHT_LINE_LOCATIONS[0].x;
    }
}

Vector2f Sheep::get_sheep_pos()
{
    return sheep_pos;
}