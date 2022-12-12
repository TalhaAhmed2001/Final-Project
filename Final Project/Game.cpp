#include "Game.h"
#include "Base.h"
#include "Barricade.h"
#include "Missile.h"
#include "Grenade.h"
#include "Airstrike.h"
#include "SupplyDrop.h"

void Game::countFPS() {
	countedFrames = 0;
	fps_timer.start();
}

void Game::calcFPS(int cf) {

	float avgFPS = cf / (fps_timer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}

	timer_text = "FPS = " + std::to_string(avgFPS);
	cout << timer_text << "\n";

}

bool Game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Final Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{

			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (renderer == nullptr) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(renderer, 0x87, 0xce, 0xef, 0xff);
			}

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = false;
			}
			else {
				quit = false;
				menu = true;
				ui_list.insert(ui_list.begin(), ammo_ui);
				ui_list.insert(ui_list.begin(),missile_ui);
				ui_list.insert(ui_list.begin(), grenade_ui);
				//ui_list.insert(ui_list.begin(), airstrike_ui);
			}
			//Hack to get window to stay up
			//SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}
	return success;
}

void Game::init_menu() {

	renderMenuBackdrop();
	createGameLogo();
	createPlayButton();
	//createLoadButton();
	createExitButton();

}

void Game::createGameLogo() {

	color = { 150,150,150 };

	SDL_Rect game_logo;
	game_logo.x = SCREEN_WIDTH / 2 - 300;
	game_logo.y = 50;
	game_logo.w = 600;
	game_logo.h = 200;

	createText(" Plastic Slug ");

	SDL_RenderCopy(renderer, texture, NULL, &game_logo);
	SDL_DestroyTexture(texture);
}

void Game::createPlayButton() {

	color = { 255,255,255 };

	SDL_Rect play_game;
	play_game.x = play_button->getX();
	play_game.y = play_button->getY();
	play_game.w = play_button->getSpriteSize()*2;
	play_game.h = play_button->getSpriteSize();

	SDL_Rect play_image;
	play_image.x = play_button->getCurrSprite() * play_button->getImageSize() * 2;
	play_image.y = 0;
	play_image.w = play_button->getImageSize() * 2;
	play_image.h = play_button->getImageSize();

	Pic2Texture(play_button->getPath());
	SDL_RenderCopy(renderer, texture, &play_image, &play_game);
	SDL_DestroyTexture(texture);

	play_game.x = play_button->getX() + 20;
	play_game.y = play_button->getY() + 20;
	play_game.w = play_button->getSpriteSize() * 2 - 40;
	play_game.h = play_button->getSpriteSize() - 40;

	createText(play_button->getText());

	SDL_RenderCopy(renderer, texture, NULL, &play_game);
	SDL_DestroyTexture(texture);
}

void Game::createLoadButton() {

	SDL_Rect load_game;
	load_game.x = load_button->getX();
	load_game.y = load_button->getY();
	load_game.w = load_button->getSpriteSize() * 2;
	load_game.h = load_button->getSpriteSize();

	SDL_Rect load_image;
	load_image.x = load_button->getCurrSprite() * play_button->getImageSize() * 2;
	load_image.y = 0;
	load_image.w = load_button->getImageSize() * 2;
	load_image.h = load_button->getImageSize();

	Pic2Texture(load_button->getPath());
	SDL_RenderCopy(renderer, texture, &load_image, &load_game);
	SDL_DestroyTexture(texture);

	load_game.x = load_button->getX() + 20;
	load_game.y = load_button->getY() + 20;
	load_game.w = load_button->getSpriteSize() * 2 - 40;
	load_game.h = load_button->getSpriteSize() - 40;

	createText(load_button->getText());

	//SDL_RenderCopy(renderer, texture, NULL, &load_game);
	SDL_DestroyTexture(texture);
}

void Game::createExitButton() {

	SDL_Rect exit_game;
	exit_game.x = exit_button->getX();
	exit_game.y = exit_button->getY();
	exit_game.w = exit_button->getSpriteSize() * 2;
	exit_game.h = exit_button->getSpriteSize();

	SDL_Rect exit_image;
	exit_image.x = exit_button->getCurrSprite() * play_button->getImageSize() * 2;
	exit_image.y = 0;
	exit_image.w = exit_button->getImageSize() * 2;
	exit_image.h = exit_button->getImageSize();

	Pic2Texture(exit_button->getPath());
	SDL_RenderCopy(renderer, texture, &exit_image, &exit_game);
	SDL_DestroyTexture(texture);

	exit_game.x = exit_button->getX() + 20;
	exit_game.y = exit_button->getY() + 20;
	exit_game.w = exit_button->getSpriteSize() * 2 - 40;
	exit_game.h = exit_button->getSpriteSize() - 40;

	createText(exit_button->getText());

	SDL_RenderCopy(renderer, texture, NULL, &exit_game);
	SDL_DestroyTexture(texture);
}

bool Game::createText(string text) {
	bool success = true;

	font = TTF_OpenFont("Gimme Danger.ttf", 50);

	SDL_Surface* rowUI = TTF_RenderText_Solid(font, text.c_str(), color);


	if (rowUI == nullptr) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, rowUI);
		if (texture == nullptr)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			success = true;
		}
	}
	SDL_FreeSurface(rowUI);
	return success;

}

bool Game::createGameText(string text) {
	bool success = true;

	font = TTF_OpenFont("ARCADE_R.ttf", 50);

	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), { 0, 0, 0 });


	if (surf == nullptr) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, surf);
		if (texture == nullptr)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			success = true;
		}
	}
	SDL_FreeSurface(surf);
	return success;

}

void Game::renderUI() {
	int health;

	SDL_Rect health_box;
	if (cracked == true) {
		health_box.x = 15 + rand() % 10;
		health_box.y = 15 + rand() % 10;
		health_box.w = 500;
		health = 99999;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	else {
		health = player.at(1)->getHealth();
		if (health < 0) {
			health = 0;
		}
		health_box.x = 20;
		health_box.y = 20;
		health_box.w = 500 * ((float)health / 1000);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}


	health_box.h = 50;
	

	
	SDL_RenderFillRect(renderer, &health_box);

	health_box.x = 20;
	health_box.y = 20;
	health_box.w = 500;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &health_box);

	SDL_Rect health_num;
	health_num.x = 550;
	health_num.y = 20;
	health_num.w = 50;
	health_num.h = 50;

	createGameText(std::to_string(health));
	SDL_RenderCopy(renderer, texture, NULL, &health_num);
	SDL_DestroyTexture(texture);

	
	for (UI* temp : ui_list) {
		SDL_Rect ui_box;
		ui_box.x = temp->getX();
		ui_box.y = temp->getY();
		ui_box.w = temp->getSpriteSize();
		ui_box.h = temp->getSpriteSize();

		Pic2Texture(temp->getPath());
		SDL_RenderCopy(renderer, texture, NULL, &ui_box);
		SDL_DestroyTexture(texture);

		SDL_Rect weapon_count;
		weapon_count.x = temp->getX() + 60;
		weapon_count.y = temp->getY();
		weapon_count.w = temp->getSpriteSize() - 20;
		weapon_count.h = temp->getSpriteSize() ;

		createGameText(std::to_string(temp->getVal()));
		SDL_RenderCopy(renderer, texture, NULL, &weapon_count);
		SDL_DestroyTexture(texture);
	}
	
	if (airstrike_ability == 1) {
		SDL_Rect temp;
		temp.x = 20;
		temp.y = 160;
		temp.w = 64;
		temp.h = 64;

		Pic2Texture("sprites/airstrikeUI.png");
		SDL_RenderCopy(renderer, texture, NULL, &temp);
		SDL_DestroyTexture(texture);

	}

	if (cracked_ability == 1) {
		SDL_Rect temp;
		temp.x = 120;
		temp.y = 160;
		temp.w = 20;
		temp.h = 60;

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderFillRect(renderer, &temp);

		temp.x = 100;
		temp.y = 180;
		temp.w = 60;
		temp.h = 20;

		SDL_RenderFillRect(renderer, &temp);


	}

}

bool Game::Pic2Texture(string path)
{
	bool success = true;

	SDL_Surface* Surf = IMG_Load(path.c_str());

	if (Surf == nullptr) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
		success = false;
	}
	else {
		if (texture != nullptr) {
			SDL_DestroyTexture(texture);
		}
		texture = SDL_CreateTextureFromSurface(renderer, Surf);
		SDL_FreeSurface(Surf);
	}
	return success;
}

bool Game::loadMusic(string path)
{
	Mix_HaltMusic();
	if (music != nullptr) {
		Mix_FreeMusic(music);
	}
	bool success = true;

	music = Mix_LoadMUS(path.c_str());

	if (music == nullptr) {
		printf("Unable to load music %s! SDL Error: %s\n", path.c_str(), Mix_GetError());
		success = false;
	}

	Mix_PlayMusic(music, -1);
	return success;
}

bool Game::loadSFX(string path)
{
	if (chunk != nullptr) {
		Mix_FreeChunk(chunk);
	}
	bool success = true;

	chunk = Mix_LoadWAV(path.c_str());

	if (chunk == nullptr) {
		printf("Unable to load music %s! SDL Error: %s\n", path.c_str(), Mix_GetError());
		success = false;
	}
	Mix_PlayChannel(-1, chunk, 0);
	return success;
}

void Game::checkCollision() {

	int health_inc = 0;

	//enemy collison
	for (Character* temp1 : enemy_list) {
		for (Projectile* temp2 : player_projectile_list) {
			if (temp1->detCollision(temp2->getX(), temp2->getY(), temp2->getAoE(), temp2->getImageSize())) {
				temp1->decHealth(temp2->getDamage());
				temp2->kill();
				string t1 = temp2->getSFXPath();
				if (t1 != "") {
					loadSFX(t1);
				}
				if (!temp1->isAlive()) {
					health_inc += temp1->getMaxHP();
				}
				if (temp1->getMaxHP() == 1 && temp1->getPath() == "sprites/ammo.png") {
					ui_list.at(0)->incVal(ui_list.at(0)->getMaxVal());
					ui_list.at(1)->incVal(ui_list.at(1)->getMaxVal());
					ui_list.at(2)->incVal(ui_list.at(2)->getMaxVal());
				}
				if (temp1->getMaxHP() == 1 && temp1->getPath() == "sprites/Health.png") {
					cracked_ability = 1;
				}
				if (temp1->getMaxHP() == 1 && temp1->getPath() == "sprites/Airstrike.png") {
					airstrike_ability = 1;
				}

			}
		}
	}

	//player collsion
	for (Character* temp1 : player) {
		if (typeid(temp1) == typeid(Base)) {
			temp1->incHealth(health_inc);
		}

		for (Projectile* temp2 : enemy_projectile_list) {
			if (temp1->detCollision(temp2->getX(), temp2->getY(), temp2->getAoE(), temp2->getImageSize())) {

				if (!cracked) {
					temp1->decHealth(temp2->getDamage());
				}
				temp2->kill();
				string t1 = temp2->getSFXPath();
				if (t1 != "") {
					loadSFX(t1);
				}
			}
		}

	}

}

void Game::keyEvents() {
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			quit = true;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			shoot = 1;
		}
		if (e.type == SDL_MOUSEBUTTONUP) {
			shoot = 0;
		}
	}

	if (currentKeyStates[SDL_SCANCODE_X]){
		//ui_list.at(0)->decVal();
		if (missile_delay < fps_timer.getTicks() && ui_list.at(1)->getVal() > 0) {
			missile_delay = fps_timer.getTicks() + 1000;
			ui_list.at(1)->decVal();
			Missile* missile = new Missile();
			player_projectile_list.insert(player_projectile_list.begin(), missile);
		}
	}

	if (currentKeyStates[SDL_SCANCODE_SPACE]) {
		
		if (grenade_delay < fps_timer.getTicks() && ui_list.at(0)->getVal() > 0) {
			grenade_delay = fps_timer.getTicks() + 1000;
			ui_list.at(0)->decVal();
			Grenade* grenade = new Grenade();
			player_projectile_list.insert(player_projectile_list.begin(), grenade);
		}
	}

	if (currentKeyStates[SDL_SCANCODE_M] && airstrike_ability == 1) {
		airstrike_ability = 0;
		for (int i = 0; i < 20; i++) {
			Airstrike* airstrike = new Airstrike(400 + 50*i, 2 + rand()%8);
			player_projectile_list.insert(player_projectile_list.begin(), airstrike);
		}
	}

	if (currentKeyStates[SDL_SCANCODE_H] && cracked_ability == 1) {
		cracked_ability = 0;
		cracked_time = fps_timer.getTicks();
		cracked = true;
	}

	if (fps_timer.getTicks() - cracked_time > 10000) {
		cracked = false;
	}
}

void Game::spawnSupplyBox() {
	if (fps_timer.getTicks() % 60000 > 50000 && health_count == 0) {
		SupplyDrop* supply = new SupplyDrop(1,"sprites/Health.png");
		enemy_list.insert(enemy_list.begin(), supply);
		health_count = 1;
	}
	if (fps_timer.getTicks() % 80000 > 50000 && ammo_count == 0) {
		SupplyDrop* supply = new SupplyDrop(2,"sprites/ammo.png");
		enemy_list.insert(enemy_list.begin(), supply);
		ammo_count = 1;
	}
	if (fps_timer.getTicks() % 60000 > 30000 && airstrike_count == 0) {
		SupplyDrop* supply = new SupplyDrop(3,"sprites/Airstrike.png");
		enemy_list.insert(enemy_list.begin(), supply);
		airstrike_count = 1;
	}

}

void Game::spawnPlayerProjectile() {
	if (shoot_delay < fps_timer.getTicks() && shoot == 1 && ui_list.at(2)->getVal()>0) {
		loadSFX("sfx/shot.mp3");
		shoot_delay = fps_timer.getTicks() + 200;
		player_projectile_list.insert(player_projectile_list.begin(), player.at(0)->shoot(mouse_x + 64, mouse_y + 64));
		ui_list.at(2)->decVal();;
	}
}

void Game::moveEverything() {

	for (Character* temp : enemy_list) {
		temp->Move();
	}

	for (Particle* temp : particle_engine) {
		temp->Move();
	}

	for (Character* temp : player) {
		temp->Move(mouse_x, mouse_y);
	}

	for (Projectile* temp : player_projectile_list) {
		temp->Move();
	}

	for (Projectile* temp : enemy_projectile_list) {
		temp->Move();
	}

}

void Game::spawnPlayer1() {
	
	Barricade* bar = new Barricade(270,320,"sprites/woodenbarricade.png", 200);
	player.insert(player.begin(), bar);

	bar = new Barricade(350, 320, "sprites/metalbarricade1.png", 100);
	player.insert(player.begin(), bar);

	bar = new Barricade(400, 320, "sprites/metalbarricade3.png", 100);
	player.insert(player.begin(), bar);

	bar = new Barricade(450, 320, "sprites/metalbarricade3.png", 100);
	player.insert(player.begin(), bar);

	Base* base = new Base(50, 200);
	player.insert(player.begin(), base);

	Turret* play = new Turret(110, 100);
	player.insert(player.begin(), play);

}

void Game::spawnEnemies1() {

	int time = fps_timer.getTicks();

	if (time % 500 > 496 && time > 2000 && infantry_count < 30) {
		infantry_count++;
		Infantry* infantry = new Infantry(rand() % 100 + 1250, rand() % 10 + 335);
		enemy_list.insert(enemy_list.begin(), infantry);
	}

	if (time % 2000 > 1995 && time > 10000 && brute_count < 10) {
		brute_count++;
		Brute* brute = new Brute(1200, 263 + rand() % 3);
		enemy_list.insert(enemy_list.begin(), brute);
	}

	if (time % 2500 > 2495 && time > 20000 && apache_count < 6) {
		apache_count++;
		Apache* apache = new Apache(1300, 40 + rand() % 20);
		enemy_list.insert(enemy_list.begin(), apache);
	}

	if (time % 3000 > 2990 && time > 25000 && kamikaze_count < 10) {
		kamikaze_count++;
		Kamikaze* kamikaze = new Kamikaze(1200, rand() % 20 + 100);
		enemy_list.insert(enemy_list.begin(), kamikaze);
	}

	if (time % 3000 > 2985 && time > 50000 && tank_count < 10) {
		tank_count++;
		Tank* tank = new Tank(1200, 305 + rand() % 10);
		enemy_list.insert(enemy_list.begin(), tank);
	}

	if (infantry_count + brute_count + apache_count + kamikaze_count + tank_count == 66 && enemy_list.size() == 0) {
		level1Pass();
	}

}

void Game::spawnPlayer2() {

	Barricade* bar = new Barricade(270, 370, "sprites/woodenbarricade.png", 200);
	player.insert(player.begin(), bar);

	bar = new Barricade(350, 400, "sprites/metalbarricade1.png", 100);
	player.insert(player.begin(), bar);

	bar = new Barricade(400, 400, "sprites/metalbarricade3.png", 100);
	player.insert(player.begin(), bar);

	bar = new Barricade(450, 400, "sprites/metalbarricade3.png", 100);
	player.insert(player.begin(), bar);

	Base* base = new Base(50, 290);
	player.insert(player.begin(), base);

	Turret* play = new Turret(110, 200);
	player.insert(player.begin(), play);

}

void Game::spawnEnemies2() {

	int time = fps_timer.getTicks();

	if (time % 500 > 495 && time > 2000 && infantry_count < 20) {
		infantry_count++;
		Infantry* infantry = new Infantry(rand() % 100 + 1250, rand() % 10 + 385);
		enemy_list.insert(enemy_list.begin(), infantry);
	}

	if (time % 2000 > 1995 && time > 10000 && brute_count < 7) {
		brute_count++;
		Brute* brute = new Brute(1200, 313 + rand() % 3);
		enemy_list.insert(enemy_list.begin(), brute);
	}

	if (time % 2500 > 2495 && time > 20000 && apache_count < 5) {
		apache_count++;
		Apache* apache = new Apache(1300, 100 + rand() % 20);
		enemy_list.insert(enemy_list.begin(), apache);
	}

	if (time % 3000 > 2990 && time > 25000 && kamikaze_count < 7) {
		kamikaze_count++;
		Kamikaze* kamikaze = new Kamikaze(1200, rand() % 20 + 150);
		enemy_list.insert(enemy_list.begin(), kamikaze);
	}

	if (time % 3000 > 2985 && time > 50000 && tank_count < 6) {
		tank_count++;
		Tank* tank = new Tank(1200, 355 + rand() % 10);
		enemy_list.insert(enemy_list.begin(), tank);
	}

	if (time > 5000 && boss_count < 1) {
		boss_count++;
		Boss* tank = new Boss();
		enemy_list.insert(enemy_list.begin(), tank);
	}

	if (infantry_count + brute_count + apache_count + kamikaze_count + tank_count  + boss_count == 46 && enemy_list.size() == 0) {
		level2Pass();
	}

}

void Game::spawnProjectiles1() {

	for (Character* temp : enemy_list) {
		int freq = temp->getFreq();

		if (fps_timer.getTicks() % freq > (freq - 40)) {
			enemy_projectile_list.insert(enemy_projectile_list.begin(), temp->shoot());
		}
	}

}

void Game::renderEnemies() {

	for (Character* temp : enemy_list) {

		Pic2Texture(temp->getPath());

		SDL_Rect img_box;
		img_box.x = (int)(temp->getCurrSprite()) * temp->getImageSize();
		img_box.y = 0;
		img_box.w = temp->getImageSize();
		img_box.h = temp->getImageSize();

		SDL_Rect sprite_box;
		sprite_box.x = temp->getX();
		sprite_box.y = temp->getY();
		sprite_box.w = temp->getSpriteSize();
		sprite_box.h = temp->getSpriteSize();

		SDL_RenderCopyEx(renderer, texture, &img_box, &sprite_box, temp->getAngle(), NULL, SDL_FLIP_NONE);
		SDL_DestroyTexture(texture);
	}

}

void Game::renderEnemyProjectile() {

	for (Projectile* temp : enemy_projectile_list) {
		Pic2Texture(temp->getPath());

		SDL_Rect img_box;
		img_box.x = (int)(temp->getCurrSprite()) * temp->getImageSize();
		img_box.y = 0;
		img_box.w = temp->getImageSize();
		img_box.h = temp->getImageSize();

		SDL_Rect sprite_box;
		sprite_box.x = temp->getX();
		sprite_box.y = temp->getY();
		sprite_box.w = temp->getSpriteSize();
		sprite_box.h = temp->getSpriteSize();

		SDL_RenderCopyEx(renderer, texture, &img_box, &sprite_box, (int)temp->getAngle(), NULL, SDL_FLIP_NONE);
		SDL_DestroyTexture(texture);
	}

}

void Game::renderPlayer() {

	for (Character* temp : player) {
		Pic2Texture(temp->getPath());

		SDL_Rect img_box;
		img_box.x = (int)(temp->getCurrSprite()) * temp->getImageSize();
		img_box.y = 0;
		img_box.w = temp->getImageSize();
		img_box.h = temp->getImageSize();

		SDL_Rect sprite_box;
		sprite_box.x = temp->getX();
		sprite_box.y = temp->getY();
		sprite_box.w = temp->getSpriteSize();
		sprite_box.h = temp->getSpriteSize();

		SDL_RenderCopyEx(renderer, texture, &img_box, &sprite_box, temp->getAngle(), NULL, SDL_FLIP_NONE);
		SDL_DestroyTexture(texture);
	}

}

void Game::renderPlayerProjectile() {

	for (Projectile* temp : player_projectile_list) {
		Pic2Texture(temp->getPath());

		SDL_Rect img_box;
		img_box.x = (int)(temp->getCurrSprite()) * temp->getImageSize();
		img_box.y = 0;
		img_box.w = temp->getImageSize();
		img_box.h = temp->getImageSize();

		SDL_Rect sprite_box;
		sprite_box.x = temp->getX();
		sprite_box.y = temp->getY();
		sprite_box.w = temp->getSpriteSize();
		sprite_box.h = temp->getSpriteSize();

		SDL_RenderCopyEx(renderer, texture, &img_box, &sprite_box, temp->getAngle(), NULL, SDL_FLIP_NONE);
		SDL_DestroyTexture(texture);
	}

}

void Game::renderParticle() {

	for (Particle* temp : particle_engine){
		Pic2Texture(temp->getPath());

		SDL_Rect img_box;
		img_box.x = (int)(temp->getCurrSprite()) * temp->getImageSize();
		img_box.y = 0;
		img_box.w = temp->getImageSize();
		img_box.h = temp->getImageSize();

		SDL_Rect sprite_box;
		sprite_box.x = temp->getX();
		sprite_box.y = temp->getY();
		sprite_box.w = temp->getSpriteSize();
		sprite_box.h = temp->getSpriteSize();

		SDL_SetTextureAlphaMod(texture, temp->getAlpha());
		SDL_RenderCopyEx(renderer, texture, &img_box, &sprite_box, temp->getAngle(), NULL, SDL_FLIP_NONE);
		SDL_DestroyTexture(texture);

	}

}

void Game::renderMenuBackdrop() {

	bg.x = 0;
	bg.y = 0;
	bg.w = 256;
	bg.h = 128;

	Pic2Texture(menu_bg);
	SDL_RenderCopy(renderer, texture, &bg, NULL);

	SDL_DestroyTexture(texture);

}

void Game::renderBackdrop1() {

	//bg_x += 0.2;(int)(bg_x) % 470
	bg.x = 20;
	bg.y = 20;
	bg.w = 466;
	bg.h = 200;

	Pic2Texture(level1_bg);
	SDL_RenderCopy(renderer, texture, &bg, NULL);

	SDL_DestroyTexture(texture);
}

void Game::renderBackdrop2() {

	//bg_x += 0.5;
	bg.x = 50;
	bg.y = 20;
	bg.w = 500;
	bg.h = 200;

	Pic2Texture(level2_bg);
	SDL_RenderCopy(renderer, texture, &bg, NULL);

	SDL_DestroyTexture(texture);

}

void Game::updateFrame() {

	renderEnemies();
	renderEnemyProjectile();
	renderPlayer();
	renderPlayerProjectile();
	renderParticle();
	renderUI();

	SDL_GetMouseState(&mouse_x, &mouse_y);

	crosshair.x = mouse_x - 32;
	crosshair.y = mouse_y - 32;
	crosshair.w = 64;
	crosshair.h = 64;

	Pic2Texture(crosshair_path);
	SDL_RenderCopy(renderer, texture, NULL, &crosshair);
	SDL_DestroyTexture(texture);

	SDL_RenderPresent(renderer);

	//cout << "player" << player.size() << "enemi" << enemy_list.size() << "enemyproj" << enemy_projectile_list.size() << "\n";

}

void Game::eradicate() {

	for (int i = 0; i < player.size(); i++) {
		if (!player.at(i)->isAlive()) {
			player.erase(player.begin() + i);
		}
	}

	for (int i = 0; i < enemy_list.size(); i++) {
		if (!enemy_list.at(i)->isAlive()) {
			Particle* temp = enemy_list.at(i)->getParticle();
			if (temp != nullptr) {
				particle_engine.insert(particle_engine.begin(),temp);
			}
			enemy_list.erase(enemy_list.begin() + i);
		}
	}

	for (int i = 0; i < player_projectile_list.size(); i++) {
		if (!player_projectile_list.at(i)->isAlive()) {
			Particle* temp = player_projectile_list.at(i)->getParticle();
			if (temp != nullptr) {
				particle_engine.insert(particle_engine.begin(), temp);
			}
			player_projectile_list.erase(player_projectile_list.begin() + i);
		}
	}

	for (int i = 0; i < enemy_projectile_list.size(); i++) {
		if (!enemy_projectile_list.at(i)->isAlive()) {
			Particle* temp = enemy_projectile_list.at(i)->getParticle();
			if (temp != nullptr) {
				particle_engine.insert(particle_engine.begin(), temp);
			}
			enemy_projectile_list.erase(enemy_projectile_list.begin() + i);
		}
	}

	for (int i = 0; i < particle_engine.size(); i++) {
		if (!particle_engine.at(i)->isAlive()) {
			particle_engine.erase(particle_engine.begin() + i);
		}
	}

	/*if (typeid(player.at(1)) != typeid(Base)) {
		uDied();
	}*/

	
}

void Game::destroyAll() {

	player.clear();
	enemy_list.clear();
	player_projectile_list.clear();
	enemy_projectile_list.clear();
	particle_engine.clear();
}

void Game::play() {

	for (UI* temp : ui_list) {
		temp->incVal(temp->getMaxVal());
	}

	shoot_delay = 0;
	missile_delay = 0;
	grenade_delay = 0;

	ammo_count = 0;
	health_count = 0;
	airstrike_count = 0;
	airstrike_ability = 0;
	cracked_ability = 0;
	infantry_count = 0;
	brute_count = 0;
	tank_count = 0;
	apache_count = 0;
	kamikaze_count = 0;
	boss_count;

	destroyAll();

}

void Game::menuPass() {
	menu = false;
	level1 = true;
	level2 = true;
	play();
}

void Game::level1Pass() {

	level1 = false;
	level2 = true;
	play();
}

void Game::level2Pass() {
	level2 = false;
	menu = true;
	play();
}

void Game::uDied() {
	menu = true;
	level1 = false;
	level2 = false;

	color = { 192,102,159 };

	createGameText("lol noob");

	SDL_Rect die;
	die.x = SCREEN_WIDTH / 2 - 200;
	die.y = SCREEN_HEIGHT / 2 - 50;
	die.w = 400;
	die.h = 100;

	SDL_RenderClear(renderer);
	destroyAll();

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderCopy(renderer, texture, NULL, &die);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	//init_menu();

}

void Game::close()
{
	SDL_DestroyRenderer(renderer);

	play_button = nullptr;
	load_button = nullptr;
	exit_button = nullptr;

	destroyAll();
	SDL_DestroyWindow(window);
}

void Game::run() {

	if (!init()) {
		printf("failed to initialise\n");
		system("pause");
	}
	else {
		
		//game loop
		while (!quit){

			countFPS();

			loadMusic("sfx/Menu.mp3");
			//menu loop
			while (!quit && menu) {
				cap_timer.start();

				SDL_RenderClear(renderer);

				init_menu();

				while (SDL_PollEvent(&e) != 0) {
					
					SDL_GetMouseState(&mouse_x, &mouse_y);

					if (e.type == SDL_QUIT) {
						quit = true;
					}

					//play button
					if (play_button->ifInside(mouse_x, mouse_y)) {
						if (e.type == SDL_MOUSEBUTTONDOWN) {
							menuPass();
						}
					}

					//load button
					if (load_button->ifInside(mouse_x, mouse_y)) {
						if (e.type == SDL_MOUSEBUTTONDOWN) {
							quit = true;
						}
					}

					//exit button
					if (exit_button->ifInside(mouse_x, mouse_y)) {	
						if (e.type == SDL_MOUSEBUTTONDOWN) {
							quit = true;
						}
					}

				}

				//keyEvents();
				calcFPS(countedFrames);

				//updateFrame();
				SDL_RenderPresent(renderer);
				++countedFrames;

				if (cap_timer.getTicks() < 60) {
					SDL_Delay(60 - cap_timer.getTicks());
				}

			}

			countFPS();
			spawnPlayer1();

			loadMusic("sfx/Level1.mp3");

			//level 1 loop
			while (!quit && level1) {
				

				cap_timer.start();

				SDL_RenderClear(renderer);

				SDL_GetMouseState(&mouse_x, &mouse_y);

				keyEvents();

				
				spawnPlayerProjectile();
				spawnEnemies1();
				spawnProjectiles1();
				spawnSupplyBox();
				moveEverything();
				checkCollision();
				renderBackdrop1();
				updateFrame();
				eradicate();
				//level1Pass();
				if (player.size() == 1) {
					uDied();
				}

				calcFPS(countedFrames);

				++countedFrames;

			}

			countFPS();
			spawnPlayer2();

			loadMusic("sfx/Level2.mp3");

			//level 2 loop
			while (!quit && level2) {

				SDL_RenderClear(renderer);
				//level2Pass();

				SDL_GetMouseState(&mouse_x, &mouse_y);

				keyEvents();

				spawnPlayerProjectile();
				spawnEnemies2();
				spawnProjectiles1();
				spawnSupplyBox();
				moveEverything();
				checkCollision();
				renderBackdrop2();
				updateFrame();
				eradicate();

				if (player.size() < 2) {
					uDied();
				}

				calcFPS(countedFrames);

				++countedFrames;
			}

		}
	}
	close();
	//system("pause");

}