#ifndef _CMENU_H
#define _CMENU_H
#include "Global.h"


class CMenu
{
	HMENU		mHmenu;	
	int			mMenuId;
	int			mSelectMenu;

public:
	CMenu(){}
	~CMenu(){}

	void	MenuInitialize(int _id);

	void	PorcessCommandMeg(WPARAM _wparam);
	HMENU	GetMenuHandle() const{return mHmenu;}
	int		GetSelectMenu() const{return mSelectMenu;}
	int		GetMenuId()const {return mMenuId;}

	void	SetMenuHandle(HMENU _hmenu);
	void	SetSelectMenu(int _menu);
	void	SetMenuId(int _id){mMenuId=_id;}
};

#endif