#include "Menu.h"

void CMenu::MenuInitialize(int _id)
{
	//mHmenu=;	
	mMenuId=_id;
}
void CMenu::PorcessCommandMeg(WPARAM _wparam)
{
	
	switch(LOWORD(_wparam))
	{
	case ID_FREELINE:
		mSelectMenu=FREELINE;
		break;
	case ID_LINE:
		mSelectMenu=LINE;
		break;
	case ID_CIRCLE:
		mSelectMenu=CIRCLE;
		break;
	case ID_RECTANGLE:
		mSelectMenu=RECTANGLE;
		break;
	case ID_EXIT:
		PostQuitMessage(0);
		break;
	}
}

void CMenu::SetMenuHandle(HMENU _hmenu)
{
	mHmenu=_hmenu;
}

void CMenu::SetSelectMenu(int _menu)
{
	mSelectMenu=_menu;
}