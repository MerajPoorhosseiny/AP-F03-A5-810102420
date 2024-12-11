#include "setting.hpp"

Setting::Setting(){
    ifstream users_file("Settings");
    string line_temp;
    getline(users_file, line_temp);
    get_sheep_setting(line_temp);
    getline(users_file, line_temp);
}

int Setting::str_to_num(string input)
    {
        int output;
        char *char_temp;
        char_temp = new char[input.length() + 1];
        strcpy(char_temp, input.c_str());
        output = atof(char_temp);
        return output;
    }

float Setting::string_to_float(const std::string &str) {
    std::stringstream ss(str);
    float number;
    if (ss >> number) {
        return number;
    } else {
        std::cerr << "Invalid input: not a valid number." << std::endl;
        return 0.0f;
    }
}

void Setting::get_sheep_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    timmy.damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    shaun.strength = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    meow.displayProb = string_to_float(string_temp);
}