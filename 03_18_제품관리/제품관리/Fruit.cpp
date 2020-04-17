#include"Fruit.h"

Fruit::Fruit(int fruitnum, int quantity, int cost){
	this->fruitNum = fruitnum;
	this->quantity = quantity;
	this->cost = cost;
}

Fruit::~Fruit(){}

void Fruit::SetFruitNum(int num) {
	fruitNum = num;
}

void Fruit::SetQuantity(int num) {
	quantity = num;
}

void Fruit::SetCost(int num) {
	cost = num;
}

const int Fruit::GetFruitNum() {
	return fruitNum;
}

const int Fruit::GetQuantity() {
	return quantity;
}

const int Fruit::GetCost() {
	return cost;
}