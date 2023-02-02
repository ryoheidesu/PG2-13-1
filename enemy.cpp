#include "enemy.h"

Enemy::Enemy(int radius, int posX, int posY, int type, int color) {
	this->posX_ = posX;
	this->posY_ = posY;
	this->speedX_ = 4;
	this->speedY_ = 4;
	this->radius_ = radius;
	this->color_ = color;
	this->type_ = type;
	isAlive_ = true;
}

void Enemy::Update() {
	if (isAlive_ == true) {
		if (type_ == Living) {
			posX_ += speedX_;
			if (posX_ >= 1280 - radius_ || posX_ <= radius_) {
				speedX_ *= -1;
			}
		}
	}
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0, color_, kFillModeSolid);
	}
}
