#include "Fruit.h"

class TotalManager {
private:
	Fruit * fruitArr[MAXSIZE];
	Fruit * Nowfruit;
public:
	TotalManager();
	~TotalManager();

	void Run();

	void Init();
	void FruitIn();
	void FruitOut();
	void ShowState();
	int Mainmenu();
};