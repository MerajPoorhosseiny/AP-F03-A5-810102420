#include "game_handler.hpp"

Game_Handler::Game_Handler()
{
    right_line = 0;
    left_line = 0;
    setting = new Setting();
    type = Nothing;
}

Game_Handler::~Game_Handler()
{
    for (auto s : Right_Sheeps)
        delete s;
    for (auto s : Left_Sheeps)
        delete s;
}

int Game_Handler::calculate_total_power(int line)
{
    int total = 0;
    for (auto r : Right_Sheeps)
    {
        if (r->get_line() == line && r->face_off == true)
        {
            total -= r->get_power();
        }
    }
    for (auto l : Left_Sheeps)
    {
        if (l->get_line() == line && l->face_off == true)
        {
            total += l->get_power();
        }
    }
    return total;
}

void Game_Handler::update()
{
    for (auto ls : Left_Sheeps)
        ls->update_sheep();
    for (auto rs : Right_Sheeps)
        rs->update_sheep();
    game_players.player_left.player_update();
    game_players.player_right.player_update();
    delete_out_of_bounds();
    for (int i = 0; i < NUMBER_OFF_LINE; i++)
    {
        handle_collision(i);
    }
}

void Game_Handler::render(RenderWindow &window)
{
    for (auto s : Right_Sheeps)
        s->rendering(window);
    for (auto s : Left_Sheeps)
        s->rendering(window);
    game_players.player_left.player_render(window);
    game_players.player_right.player_render(window);
}

void Game_Handler::handle_key_press(char output_key)
{
    switch (output_key)
    {
    case ('W'):
        if (left_line < LEFT_LINE_LOCATIONS.size())
        {
            left_line++;
        }
        break;
    case ('s'):
        if (left_line > 0)
        {
            left_line--;
        }
        break;
    case (' '):
        cout << '1' << endl;
        add_left_Sheep(game_players.player_left.player_sheeps[game_players.player_left.player_sheeps.size()-1]);
        game_players.player_left.player_sheeps.pop_back();
        game_players.player_left.generate_sheep();
        left_line = 0;
        break;
    case ('↑'):
        if (right_line < RIGHT_LINE_LOCATIONS.size())
        {
            right_line++;
        }
        break;
    case ('↓'):
        if (right_line > 0)
        {
            right_line--;
        }
        break;
    case ('\n'):
        cout << '1' << endl;
        add_right_Sheep(game_players.player_right.player_sheeps[game_players.player_right.player_sheeps.size()-1]);
        game_players.player_right.player_sheeps.pop_back();
        game_players.player_right.generate_sheep();
        right_line = 0;
        break;
    default:
        break;
    }
}

bool Game_Handler::check_first_line(int line, Vector2f side)
{
    for (auto v : Right_Sheeps)
    {
        if (v->get_line() == line)
        {
            if (v->get_sheep_pos() == side)
            {
                return false;
            }
        }
    }
    for (auto v : Left_Sheeps)
    {
        if (v->get_line() == line)
        {
            if (v->get_sheep_pos() == side)
            {
                return false;
            }
        }
    }
    return true;
}

bool Game_Handler::check_gameover()
{
    if (game_players.player_left.death)
    {
        return LOSE;
    }
    else if (game_players.player_right.death)
    {
        return LOSE;
    }
    return !LOSE;
}

void Game_Handler::add_right_Sheep(sheep_type sheep_name)
{
    if (sheep_cooldown_clock.getElapsedTime().asSeconds() >= sheep_cooldown_time &&
        check_first_line(right_line, RIGHT_LINE_LOCATIONS[right_line]))
    {
        sheep_type specific_type = timmy;
        Sheep *new_sheep = new Sheep(RIGHT_PLAYER, RIGHT_LINE_LOCATIONS[right_line], specific_type, right_line, setting);
        Right_Sheeps.push_back(new_sheep);

        sheep_cooldown_clock.restart();
    }
}

void Game_Handler::add_left_Sheep(sheep_type sheep_name)
{
    if (sheep_cooldown_clock.getElapsedTime().asSeconds() >= sheep_cooldown_time && check_first_line(left_line, LEFT_LINE_LOCATIONS[left_line]))
    {
        sheep_type specific_type = sheep_name;
        Sheep *new_sheep = new Sheep(LEFT_PLAYER, LEFT_LINE_LOCATIONS[left_line], specific_type, left_line, setting);
        Left_Sheeps.push_back(new_sheep);

        sheep_cooldown_clock.restart();
    }
}
void Game_Handler::delete_out_of_bounds()
{
    vector<Sheep *> trash_right_sheep;
    for (auto s : Right_Sheeps)
    {
        if (s->is_out())
        {
            trash_right_sheep.push_back(s);
        }
    }
    Right_Sheeps.erase(remove_if(Right_Sheeps.begin(), Right_Sheeps.end(),
                                 [](auto v)
                                 { return v->is_out(); }),
                       Right_Sheeps.end());
    for (auto v : trash_right_sheep)
    {
        delete v;
    }
    vector<Sheep *> trash_left_sheep;
    for (auto s : Left_Sheeps)
    {
        if (s->is_out())
        {
            trash_left_sheep.push_back(s);
        }
    }
    Left_Sheeps.erase(remove_if(Left_Sheeps.begin(), Left_Sheeps.end(),
                                [](auto v)
                                { return v->is_out(); }),
                      Left_Sheeps.end());
    for (auto v : trash_left_sheep)
    {
        delete v;
    }
}

void Game_Handler::handle_collision(int line)
{
    vector<Sheep *> trash_right;
    vector<Sheep *> trash_left;
    for (auto r : Right_Sheeps)
    {
        for (auto l : Left_Sheeps)
        {
            if (r->face_off == false)
            {
                FloatRect r_rect = r->get_rect();
                FloatRect l_rect = l->get_rect();
                if (r_rect.intersects(l_rect))
                {
                    r->face_off = true;
                    int total = calculate_total_power(line);
                    r->reset_speed(total);
                }
            }
            if (l->face_off == false)
            {
                FloatRect r_rect = r->get_rect();
                FloatRect l_rect = l->get_rect();
                if (r_rect.intersects(l_rect))
                {
                    l->face_off = true;
                    int total = calculate_total_power(line);
                    l->reset_speed(total);
                }
            }
        }
    }
}
