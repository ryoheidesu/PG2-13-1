#include "Player.h"
#include"Novice.h"
#define _USE_MATH_DEFINES
#include<math.h>

Player::Player(int posX, int posY)
{
	this->pos.X = posX;
	this->pos.Y = posY;
}

void Player::Move(char* keys, char* preKeys)
{


	if (keys[DIK_W])
	{
		vector2.Y = -speed;
	}
	else if (keys[DIK_S])
	{
		vector2.Y = speed;
	}
	else
	{
		vector2.Y = 0;
	}
	if (keys[DIK_A])
	{
		vector2.X = -speed;
	}
	else if (keys[DIK_D])
	{
		vector2.X = speed;
	}
	else
	{
		vector2.X = 0;
	}

	if (keys[DIK_W] && keys[DIK_A])
	{
		vector2.Y = -speed;
		vector2.X = -speed;
	}
	if (keys[DIK_W] && keys[DIK_D])
	{
		vector2.Y = -speed;
		vector2.X = +speed;
	}
	if (keys[DIK_S] && keys[DIK_A])
	{
		vector2.Y = +speed;
		vector2.X = -speed;
	}
	if (keys[DIK_S] && keys[DIK_D])
	{
		vector2.Y = +speed;
		vector2.X = +speed;
	}



	if (vector2.X != 0 || vector2.Y != 0)
	{
		length = sqrtf(pow(vector2.X, 2) + pow(vector2.Y, 2));
		normal.X = vector2.X / length;
		normal.Y = vector2.Y / length;

		normal.X *= speed;
		normal.Y *= speed;

		pos.X += normal.X;
		pos.Y += normal.Y;
	}

}

void Player::Shoot(char* keys, char* preKeys)
{
	cooldown--;
	if (keys[DIK_SPACE])
	{
		for (int i = bulletCount; i < maxBullet; i++)
		{
			if (cooldown <= 30)
			{
				bullet_[i].isShooting = 1;
				bulletCount++;
				cooldown = 60;
			}
			break;
		}
	}
	for (int i = 0; i < maxBullet; i++)
	{
		bullet_[i].returnPos = pos;
		bullet_[i].Update();
	}
	if (bulletCount >= maxBullet)
	{
		bulletCount = 0;
	}
}

void Player::Update(char* keys, char* preKeys)
{
	this->Move(keys, preKeys);
	this->Shoot(keys, preKeys);
}

void Player::Draw()
{
	Novice::DrawEllipse(pos.X, pos.Y, 30, 30, 0, WHITE, kFillModeSolid);
}
