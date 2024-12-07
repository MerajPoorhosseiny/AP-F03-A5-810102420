#pragma once
#ifndef CONFIGS_HPP_INCLUDE
#define CONFIGS_HPP_INCLUDE

#include <array>
#include <deque>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int RIGHT_PLAYER = 0;
const int LEFT_PLAYER = 1;

const string PICS_PATH = "./files/pics/",
             AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

// const vector<Sheep_configs> SHEEP_CONFIGS = {
//     {
//         {"Timmy", 50, 50, 0.5f},
//         {"Shaun", 30, 150, 0.3f},
//         {"Meow", 10, 250, 0.2f},
//     }};

constexpr int COOLDOWN_MS = 2000;
constexpr int INITIAL_HEALTH = 400;
constexpr int CONSTANT_SPEED = 300;
#define debug(x) cout << x << endl, exit(0);




#include "setting.hpp"


#endif // CONFIGS_HPP_INCLUDE