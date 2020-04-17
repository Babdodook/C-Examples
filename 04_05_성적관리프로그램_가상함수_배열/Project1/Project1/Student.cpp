#include"Student.h"

Student::Student(const char * name, const char * id)
{
	strcpy(this->name, name);
	strcpy(this->classID, id);
}

Student::~Student()
{
}

const char* Student::GetName()
{
	return name;
}

const char* Student::GetID()
{
	return classID;
}