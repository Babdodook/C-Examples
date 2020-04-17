#include"Basic.h"

class Fruit {
private:
	int fruitNum; //제품번호
	int quantity; //수량
	int cost; //단가
public:
	Fruit(int fruitnum,int quantity,int cost);
	~Fruit();

	void SetFruitNum(int);
	void SetQuantity(int);
	void SetCost(int);

	const int GetFruitNum();
	const int GetQuantity();
	const int GetCost();
};