#include "global.hpp"

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
