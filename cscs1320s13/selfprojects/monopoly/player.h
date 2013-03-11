#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Player{
	int money, netWorth, number;
	bool isAlive;
public:
	void set_values(int, int, int, bool);
	bool setAlive(bool);
	int incMoney(int, int);
	int decMoney(int, int);
	int incWorth(int, int);
	int decWorth(int, int);
	int getNumber();
	int getMoney();
	int getWorth();
	bool getAlive();
};

void Player::set_values(int a, int b, int c, bool d)
{
	money = a;
	netWorth = b;
	number = c;
	isAlive = d;
}

bool Player::setAlive(bool alive)
{
	isAlive = alive;
	return alive;
}

int Player::incMoney(int curMoney, int change)
{
	money = curMoney + change;
	return money;
}

int Player::decMoney(int curMoney, int change)
{
	money = curMoney - change;
	return money;
}


int Player::incWorth(int curWorth, int change)
{
	netWorth = curWorth + change;
	return money;
}


int Player::decWorth(int curWorth, int change)
{
	netWorth = curWorth - change;
	return netWorth;
}

int Player::getNumber()
{
	return number;
}

int Player::getMoney()
{
	return money;
}

int Player::getWorth()
{
	return netWorth;
}

bool Player::getAlive()
{
	return isAlive;
}

