#include"TotalManager.h"

int main() {
	TotalManager * Manager = new TotalManager;
	Manager->Run();
	delete Manager;

	return 0;
}