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
    bool sheep_side;
    bool face_off;
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
    Sheep();
    Sheep(int player_pos, Vector2f position, sheep_type type_of_sheep, Setting *game_setting);
    ~Sheep();
    void reset_speed(int current_strength);
    void collision();
    void rendering(RenderWindow &window);
    FloatRect get_rect();
    void update_sheep();
    int get_line();
};
