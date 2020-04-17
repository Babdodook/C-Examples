#include"TotalManager.h"

int main()
{
	TotalM * TManager = new TotalM();
	TManager->Run();
	delete TManager;
	return 0;
}