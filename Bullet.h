#pragma once
#include"Struct.h"
class Bullet
{
public:
	//Variables
	int damage;
	int speed;
	bool isShooting = 0;
	Transform pos;
	Transform returnPos;

	//Function
	Bullet(int damage, int speed, float* posX, float* posY);
	~Bullet();
	void Update();
	void Shoot();
	void Draw();
};

