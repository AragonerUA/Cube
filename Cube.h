#pragma once
#include <memory>
#include <cstring>
#include <cstdlib>
#include <vector>

class Side{
public:
    explicit Side(char c);
    ~Side() = default;

    char maincol;
    char cub[3][3];
    bool check_corr();
    void print_side(); // print
};

class Cube{
public:
    Cube();
    ~Cube() = default;
    Side Front = Side{'B'}; //black purple
    Side Up = Side{'P'}; //purple
    Side Back = Side{'O'}; //orange
    Side Down = Side{'C'}; //cyan
    Side Right = Side{'G'}; //green
    Side Left = Side{'Y'}; //yellow
    bool correct;
    std::vector<char> op;
    void print(); // print

    void front_rotate(bool rightleft = true, bool check = true);
    void left_rotate(bool rightleft = true, bool check = true);
    void right_rotate(bool rightleft = true, bool check = true);
    void up_rotate(bool rightleft = true, bool check = true);
    void down_rotate(bool rightleft = true, bool check = true);
    void back_rotate(bool rightleft = true, bool check = true);
    void random_rotates(int number_of_turns = 5);
    bool check_corr();
    void solution();
};



