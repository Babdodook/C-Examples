#include"Basic.h"

class Fruit {
private:
	int fruitNum; //��ǰ��ȣ
	int quantity; //����
	int cost; //�ܰ�
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