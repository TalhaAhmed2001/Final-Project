#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class GameObject
{
private:
	int x;
	int y;
	float angle = 0;
	bool alive = true;
	int image_size;
	int sprite_size;
	int animation;
	string path;
	float curr_sprite = 0;
	string sfx_path = "";

	void setImageSize(int size);
	void setPath(string p);
	
public:
	GameObject(int X, int Y, int img, int spr, int ani, string p) {
		x = X;
		y = Y;
		image_size = img;
		sprite_size = spr;
		animation = ani;
		path = p;
	}

	void setSpriteSize(int size);
	void setAngle(float a);
	void setCurrSprite(float cs);
	void setAnimation(int ani);

	virtual void Move() {}
	virtual void Move(int x, int y) {}

	void setSFXPath(string s);
	string getSFXPath();

	void setX(int X);
	void setY(int Y);
	
	void kill();
	bool isAlive();

	virtual void animate();

	int getX();
	int getY();
	float getAngle();
	string getPath();
	int getImageSize();
	int getSpriteSize();
	int getAnimation();
	float getCurrSprite();

	//virtual Particle* getParticle();

	void ifOut();
};

