#include"Chef.h"
#include"Carrot.h"
#include"Onion.h"
#include"Potato.h"

int main()
{
	Chef* pChef = new Chef();
	pChef->Prepare_Setting(new Carrot());
	pChef->Prepare();

	pChef->Prepare_Setting(new Onion());
	pChef->Prepare();

	pChef->Prepare_Setting(new Potato());
	pChef->Prepare();

	delete pChef;
	return 0;
}