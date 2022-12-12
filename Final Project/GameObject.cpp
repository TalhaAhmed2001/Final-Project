#include "GameObject.h"
#include "Particle.h"
using namespace std;

void GameObject::setX(int X) {
	x = X;
}

void GameObject::setY(int Y) {
	y = Y;
}

void GameObject::setAngle(float a) {
	angle = a;
}

void GameObject::setCurrSprite(float cs)
{
	curr_sprite = cs;
}

void GameObject::setPath(string p) {
	path = p;
}

void GameObject::setImageSize(int size) {
	image_size = size;
}

void GameObject::setSpriteSize(int size) {
	sprite_size = size;
}

void GameObject::setAnimation(int ani) {
	animation = ani;
}

void GameObject::kill() {
	alive = false;
}

bool GameObject::isAlive() {
	return alive;
}

void GameObject::animate() {
	if (curr_sprite + 0.2 < getAnimation()) {
		curr_sprite += 0.2;
	}
	else {
		curr_sprite = 0;
	}
}

int GameObject::getX() {
	return x;
}

int GameObject::getY() {
	return y;
}

float GameObject::getAngle() {
	return angle;
}

string GameObject::getPath() {
	return path;
}

int GameObject::getImageSize() {
	return image_size;
}

int GameObject::getSpriteSize() {
	return sprite_size;
}

int GameObject::getAnimation() {
	return animation;
}

float GameObject::getCurrSprite() {
	return curr_sprite;
}

//
//Particle* GameObject::getParticle()
//{
//	return nullptr;
//}

void GameObject::ifOut() {
	if (getX() < 0 || getX() > (1400 - getImageSize()) || getY() < 0 || getY() > (600 - getImageSize())) {
		kill();
	}
}