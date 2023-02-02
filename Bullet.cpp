#include "Bullet.h"
#include"Novice.h"

Bullet::Bullet(int damage, int speed, float* posX, float* posY) {
	this->damage = damage;
	this->returnPos.X = *posX;
	this->returnPos.Y = *posY;
	this->speed = speed;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	Shoot();
	Draw();
}

void Bullet::Shoot() {
	if (isShooting) {
		pos.Y -= speed;
	}
	else {
		pos.X = returnPos.X;
		pos.Y = returnPos.Y;
	}
	if (pos.Y <= 0) {
		isShooting = 0;
	}
}
void Bullet::Draw() {
	Novice::DrawEllipse(pos.X, pos.Y - 8, 16.0f, 16.0f, 0.0f, WHITE, kFillModeSolid);
}