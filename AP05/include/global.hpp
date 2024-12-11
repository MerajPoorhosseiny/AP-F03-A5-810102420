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

const int LOSE = 1;
const int WIDTH = 1920;
const int HEIGHT = 1080;
const int RIGHT_PLAYER = 0;
const int LEFT_PLAYER = 1;
const int NUMBER_OFF_LINE = 4;
const Vector2f LEFT_PLAYER_HEALTHBAR(75, 75);
const Vector2f RIGHT_PLAYER_HEALTHBAR(75, 1855);
const vector<int> SHEEP_ANIMATION_X_REXT = {1, 93, 185, 277, 369, 461, 553, 645};
const vector<int> GOAT_ANIMATION_X_REXT = {1, 75, 149, 223, 297, 371, 445, 519};
const vector<Vector2f> RIGHT_LINE_LOCATIONS = {
    {115, 160},
    {115, 385},
    {115, 600},
    {115, 820}};
const vector<Vector2f> LEFT_LINE_LOCATIONS = {
    {1770, 160},
    {1770, 385},
    {1770, 600},
    {1770, 820}};

const string PICS_PATH = "./files/pics/",
             AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

constexpr float COOLDOWN_MS = 2;
constexpr int INITIAL_HEALTH = 400;
constexpr int CONSTANT_SPEED = 300;
constexpr int FRAME_RATE = 120;
#define debug(x) cout << x << endl, exit(0);

#include "setting.hpp"

#endif