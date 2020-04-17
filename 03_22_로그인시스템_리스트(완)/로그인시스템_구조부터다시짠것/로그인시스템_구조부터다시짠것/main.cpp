#include"TotalManager.h"

int main() 
{
	TotalManager * MasterManager = new TotalManager;
	MasterManager->RunProgram();
	delete MasterManager;

	return 0;
}