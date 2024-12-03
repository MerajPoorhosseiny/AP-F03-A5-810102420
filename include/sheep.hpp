#include "global.hpp"

class Sheep
{
private:
    Sheep_configs sheep_info;
    int sheep_speed = CONSTANT_SPEED;
    bool sheep_side;
    bool face_off;

public:
    Sheep();
    Sheep(string sheep_name, int player_pos);
    ~Sheep();
    void reset_speed(int current_strength);
    void collision();
};
