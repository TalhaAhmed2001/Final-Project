#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_ttf.h>
#include <cmath>
#include <SDL_mixer.h>
#include "Timer.h"
#include <iostream>
#include "Character.h"
#include "Infantry.h"
#include "Particle.h"
#include "Brute.h"
#include "Apache.h"
#include "Kamikaze.h"
#include "Tank.h"
#include "Turret.h"
#include "Button.h"
#include "UI.h"

using namespace std;

class Game
{
private:
	const int SCREEN_WIDTH = 1400;
	const int SCREEN_HEIGHT = 600;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	const string crosshair_path = "sprites/target.png";
	const string menu_bg = "sprites/menubg.png";
	const string level2_bg = "sprites/backdrop1.png";
	const string level1_bg = "sprites/backdrop2.png";

	int health = 0;
	const int button_w = 200;
	const int button_h = 100;

	Button* play_button = new Button(SCREEN_WIDTH / 2 - button_w / 2, SCREEN_HEIGHT / 2 - 50, "play");
	Button* load_button = new Button(SCREEN_WIDTH / 2 - button_w / 2, SCREEN_HEIGHT / 2 + 60, "load");
	Button* exit_button = new Button(SCREEN_WIDTH / 2 - button_w / 2, SCREEN_HEIGHT / 2 + 170, "exit");
	
	UI* ammo_ui = new UI(20, 80, "sprites/ammoUI.png",100);
	UI* grenade_ui = new UI(120, 80, "sprites/grenadeUI.png",10);
	UI* missile_ui = new UI(220, 80, "sprites/missilesUI.png",10);
	UI* airstrike_ui = new UI(20,140, "sprites/airstrikeUI.png",10);

	SDL_Color color = { 0,0,0 };

	int shoot = 0;
	long shoot_delay = 0;
	long missile_delay = 0;
	long grenade_delay = 0;

	int mouse_x;
	int mouse_y;

	int countedFrames;

	int infantry_count = 0;
	int brute_count = 0;
	int tank_count = 0;
	int apache_count = 0;
	int kamikaze_count = 0;

	int ammo_count = 0;
	int health_count = 0;
	int airstrike_count = 0;
	int airstrike_ability = 0;
	
	int cracked_ability = 0;
	long cracked_time = 0;
	bool cracked = false;

	float bg_x;
	float menu_bg_x;

	Timer fps_timer;
	Timer cap_timer;

	SDL_Event e;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	TTF_Font* font = nullptr;

	SDL_Rect crosshair;
	SDL_Rect bg;

	string timer_text;

	vector<Character*> player;
	vector<Character*> enemy_list;
	vector<Projectile*> player_projectile_list;
	vector<Projectile*> enemy_projectile_list;
	vector<Particle*> particle_engine;
	vector<UI*> ui_list;

	bool quit;
	bool menu;
	bool level1;
	bool level2;

	void countFPS();
	void calcFPS(int cf);

	bool init();

	void init_menu();
	void createGameLogo();
	void createPlayButton();
	void createLoadButton();
	void createExitButton();

	bool createText(string text);
	bool createGameText(string text);

	void init_level1();
	void init_level2();

	void close_level1();
	bool Pic2Texture(string path);
	void renderUI();

	void checkCollision();

	//event handler
	void keyEvents();

	void spawnSupplyBox();
	void spawnPlayerProjectile();

	//move all objects
	void moveEverything();

	void spawnPlayer1();
	void spawnEnemies1();
	void spawnProjectiles1();

	//render objects
	void renderEnemies();
	void renderEnemyProjectile();
	void renderPlayer();
	void renderPlayerProjectile();
	void renderParticle();

	void renderMenuBackdrop();
	void renderBackdrop1();
	void renderBackdrop2();

	void updateFrame();

	//eradicate die objects
	void eradicate();

	//destory all objects
	void destroyAll();

	void play();

	void level1Pass();

	void level2Pass();

	//return to menu
	void uDied();

	//close game
	void close();

public:
	Game() {}

	
	void run();
};

