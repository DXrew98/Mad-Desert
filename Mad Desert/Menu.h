#pragma once

enum STATE {SPLASH, MAIN, PLAY, GAME, EXIT};

void splash();

STATE mainMenu();

void update();

void draw();

void exit();