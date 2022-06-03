#include "Cube.h"
#include <iostream>


Side::Side(char c) { //NOLINT
    maincol = c;
    for (int i = 0; i < 3; i++) { //NOLINT
        for (int j = 0; j < 3; j++) {
            cub[i][j] = maincol;
        }
    }
}

Cube::Cube() {
    correct = true;
}

void Side::print_side() {
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) { //NOLINT
        for (int j = 0; j < 3; j++) {
            std::cout << cub[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Cube::print() {
    std::cout << std::endl << 'F';
    Front.print_side();
    std::cout << 'U';
    Up.print_side();
    std::cout << 'B';
    Back.print_side();
    std::cout << 'D';
    Down.print_side();
    std::cout << 'R';
    Right.print_side();
    std::cout << 'L';
    Left.print_side();
}

void resh(int row, char a[][3], char b[]) { //NOLINT
    if (row < 3) {
        for (int i = 0; i < 3; i++) {
            a[row][i] = b[i];
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            a[i][row % 3] = b[i];
        }
    }
}

void resh(int row, char a[], char b[][3]) { //NOLINT
    if (row < 3) {
        for (int i = 0; i < 3; i++) {
            a[i] = b[row][i];
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            a[i] = b[i][row % 3];
        }
    }
}


void resh(int row1, int row2, char a[][3], char b[][3]) { //NOLINT
    if (row1 < 3) {
        if (row2 < 3) {
            for (int i = 0; i < 3; i++) {
                a[row1][i] = b[row2][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                a[row1][i] = b[i][row2 % 3];
            }
        }
    }
    else {
        if (row2 < 3) {
            for (int i = 0; i < 3; i++) {
                a[i][row1 % 3] = b[row2][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                a[i][row1 % 3] = b[i][row2 % 3];
            }
        }
    }
}

void Cube::front_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('f');
    }
    if (rightleft) {
        resh(5, temp, Left.cub);
        resh(5, 0, Left.cub, Down.cub);
        resh(0, 3, Down.cub, Right.cub);
        resh(3, 2, Right.cub, Up.cub);
        resh(2, Up.cub, temp);
    }
    else {
        if (check) {
            op.push_back('F');
        }
        for (int i = 0; i < 3; i++) {
            front_rotate(true, false);
        }
    }
}

void Cube::back_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('b');
    }
    if (rightleft) {
        resh(5, temp, Right.cub);
        resh(5, 2, Right.cub, Down.cub);
        resh(2, 3, Down.cub, Left.cub);
        resh(3, 0, Left.cub, Up.cub);
        resh(0, Up.cub, temp);
    }
    else {
        if (check) {
            op.push_back('B');
        }
        for (int i = 0; i < 3; i++) {
            back_rotate(true, false);
        }
    }
}

void Cube::left_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('l');
    }
    if (rightleft){
        resh(5, temp, Back.cub);
        resh(5, 3, Back.cub, Down.cub);
        resh(3, 3, Down.cub, Front.cub);
        resh(3, 3, Front.cub, Up.cub);
        resh(3, Up.cub, temp);
    }
    else {
        if (check) {
            op.push_back('L');
        }
        for (int i = 0; i < 3; i++) {
            left_rotate(1, 0);
        }
    }
}

void Cube::right_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('r');
    }
    if (rightleft){
        resh(5, temp, Down.cub);
        resh(5, 3, Down.cub, Back.cub);
        resh(3, 5, Back.cub, Up.cub);
        resh(5, 5, Up.cub, Front.cub);
        resh(5, Front.cub, temp);
    }
    else {
        if (check) {
            op.push_back('R');
        }
        for (int i = 0; i < 3; i++) {
            right_rotate(1, 0);
        }
    }
}

void Cube::up_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('u');
    }
    if (rightleft){
        resh(0, temp, Left.cub);
        resh(0, 0, Left.cub, Front.cub);
        resh(0, 0, Front.cub, Right.cub);
        resh(0, 0, Right.cub, Back.cub);
        resh(0, Back.cub, temp);
    }
    else {
        if (check) {
            op.push_back('U');
        }
        for (int i = 0; i < 3; i++) {
            up_rotate(1, 0);
        }
    }
}

void Cube::down_rotate(bool rightleft, bool check) {
    char temp[3];
    if (check == 1 and rightleft == 1) {
        op.push_back('d');
    }
    if (rightleft){
        resh(2, temp, Left.cub);
        resh(2, 2, Left.cub, Back.cub);
        resh(2, 2, Back.cub, Right.cub);
        resh(2, 2, Right.cub, Front.cub);
        resh(2, Front.cub, temp);
    }
    else {
        if (check) {
            op.push_back('D');
        }
        for (int i = 0; i < 3; i++) {
            down_rotate(true, false);
        }
    }
}

void Cube::random_rotates(int number_of_turns) {
    for (int i = 0; i < number_of_turns; i++) {
        switch(rand() % 6){ //NOLINT
            case 0:
                front_rotate(rand() % 2); //NOLINT
                break;
            case 1:
                left_rotate(rand() % 2); //NOLINT
                break;
            case 2:
                right_rotate(rand() % 2); //NOLINT
                break;
            case 3:
                up_rotate(rand() % 2); //NOLINT
                break;
            case 4:
                down_rotate(rand() % 2); //NOLINT
                break;
            case 5:
                back_rotate(rand() % 2); //NOLINT
                break;
        }
    }
}

bool Cube::check_corr() {
    if (Front.check_corr() and Up.check_corr() and Back.check_corr() and Down.check_corr() and Right.check_corr() and Left.check_corr()) {
        correct = true;
    }
    else {
        correct = false;
    }
    return correct;
}

bool Side::check_corr() {
    for (int i = 0; i < 3; i++) { //NOLINT
        for (int j = 0; j < 3; j++) {
            if (cub[i][j] != cub[1][1]) {
                return false;
            }
        }
    }
    return true;
}

void Cube::solution() {
    if (check_corr()) {
        return;
    }
    while (!op.empty()) {
        switch (op.back()) {
            case 'f':
                front_rotate(false, false);
                break;
            case 'F':
                front_rotate(true, false);
                break;
            case 'u':
                up_rotate(false, false);
                break;
            case 'U':
                up_rotate(true, false);
                break;
            case 'b':
                back_rotate(false, false);
                break;
            case 'B':
                back_rotate(true, false);
                break;
            case 'd':
                down_rotate(false, false);
                break;
            case 'D':
                down_rotate(true, false);
                break;
            case 'r':
                right_rotate(false, false);
                break;
            case 'R':
                right_rotate(true, false);
                break;
            case 'l':
                left_rotate(false, false);
                break;
            case 'L':
                left_rotate(true, false);
                break;
        }
        op.pop_back();
    }
}
