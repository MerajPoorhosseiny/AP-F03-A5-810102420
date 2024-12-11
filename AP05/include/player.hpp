#include "global.hpp"
#include "sheep.hpp"

enum player_side
{
    left,
    right,
};

class Health{
public:
    Health(player_side side);
    ~Health();
    void health_update(int health);
    void health_render(RenderWindow &window);
private:
    Texture texture;
    Sprite sprite;
    Font font;
    Text text;
};

class Player
{
private:
    player_side side;
    int health;
    Health* player_healthbar;
public:
    Player(player_side pside);
    ~Player();
    void taking_damage(int input_damage);
    void player_update();
    void player_render(RenderWindow &Window);
    vector<sheep_type> player_sheeps;
    void generate_sheep();
    bool death;
};
