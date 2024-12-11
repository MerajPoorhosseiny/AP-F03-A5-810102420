#pragma once

#include "global.hpp"
#include "sheep.hpp"
#include "player.hpp"

enum Handler_Type
{
    Nothing,
    Choosing,
};

struct players
{
    Player player_left = Player(player_side::left);
    Player player_right = Player(player_side::right);
};

class Game_Handler
{
public:
    Game_Handler();
    ~Game_Handler();
    void update();
    void render(RenderWindow &window);
    void handle_key_press(char output_key);
    bool check_gameover();

private:
    Setting *setting;
    int right_line;
    int left_line;
    Handler_Type type;
    mt19937 rng;
    Clock sheepclock;
    Clock sheep_cooldown_clock;
    float sheep_cooldown_time = COOLDOWN_MS;
    vector<Sheep *> Right_Sheeps;
    vector<Sheep *> Left_Sheeps;
    players game_players;
    void add_right_Sheep(sheep_type sheep_name);
    void add_left_Sheep(sheep_type sheep_name);
    void delete_out_of_bounds();
    void handle_collision(int line);
    bool check_first_line(int line,Vector2f side);
    int calculate_total_power(int line);
};