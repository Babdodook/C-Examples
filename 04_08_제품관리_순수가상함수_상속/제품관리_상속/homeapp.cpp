#pragma once
#include"HomeApp.h"

HomeApp::HomeApp(const char* name, const char* date, const char* id, int price, const char* model)
	:Product(name, date, id, price)
{
	strcpy(this->model, model);
}

HomeApp::~HomeApp()
{
}

void HomeApp::SetModel(const char* model)
{
	strcpy(this->model, model);
}

const char* HomeApp::GetModel()
{
	return model;
}