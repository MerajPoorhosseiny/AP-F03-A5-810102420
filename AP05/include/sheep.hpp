#pragma once
#include "global.hpp"

enum sheep_type
{
    timmy,
    shaun,
    meow,
};

class Sheep
{
private:
    Sheep_configs sheep_info;
    int current_rect = 0;
    int current_line = 0;
    bool sheep_side;
    Setting *setting;
    Vector2f sheep_pos;
    sheep_type type_of_sheep;
    Texture texture;
    Sprite sprite;
    Clock animation_render_time;
    void setup_sheep_info();
    void set_sheep_texture();
    void handle_sheep_animation();

public:
    Sheep() = default;
    Sheep(int player_pos, Vector2f position, sheep_type type_of_sheep, int intery_line, Setting *game_setting);
    ~Sheep() = default;
    void reset_speed(int current_strength);
    void collision();
    void rendering(RenderWindow &window);
    FloatRect get_rect();
    void update_sheep();
    int get_line();
    int get_power();
    bool is_out();
    bool face_off;
    Vector2f get_sheep_pos();
};
