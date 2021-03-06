/*
Завдання 1.
Створити ієрархію класів Grandpa-> Daddy-> Son.
o	Клас Grandpa  має віртуальну функцію Sleep().
o	Класи Daddy та  Son мають віртуальні функції  Walk().
o	Клас Son має віртуальну функцію Play().
Створити масив вказівників на базовий клас.
Визначити глобальну функцію, яка отримує масив(або вектор) вказівників на об’єкти та для кожного об’єкта викликає правильний набір віртуальних методів.
Розв’язати задачу двома способами
o	використати операцію dynamic_cast < >(виконано у класі).
o	використати операцію typeid().

*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

class Grandpa
{
public:

	virtual void sleep()
	{
		cout << "Grandpa sleep\n";
	}

};

class Daddy : public Grandpa
{
public:

	virtual void sleep() override
	{
		cout << "Daddy sleep\n";
	}

	virtual void walk()
	{
		cout << "Daddy walk\n";
	}

};

class Son : public Daddy
{
public:

	virtual void sleep() override
	{
		cout << "Son sleep\n";
	}

	virtual void walk() override
	{
		cout << "Son walk\n";
	}

	virtual void play()
	{
		cout << "Son play\n";
	}

};

//	використати операцію dynamic_cast < >(виконано у класі).
void life_dynamic_cast(Grandpa* arr[])
{
	Daddy *pD = nullptr;
	Son *pS = nullptr;

	cout << "\n\t= dynamic_cast =\n";
	for (int i = 0; i < 3; ++i)
	{
		cout << "\n\tObject # " << i << endl;

		arr[i]->sleep();

		if (pD = dynamic_cast<Daddy*>(arr[i]))
			pD->walk();

		if (pS = dynamic_cast<Son*>(arr[i]))
			pS->play();
	}
}

//o	використати операцію typeid().
void life_typeid(Grandpa* arr[])
{
	
	Daddy *pD = nullptr;
	Son *pS = nullptr;
	
	

	cout << "\n\t= typeid =\n";
	for (int i = 0; i < 3; ++i)
	{

		cout << "\n\tObject # " << i << endl;

		arr[i]->sleep();


		if (typeid(Daddy) == typeid(*arr[i]))
		{
			pD = static_cast<Daddy*>(arr[i]);
			pD->walk();
		}


		if (typeid(Son) == typeid(*arr[i]))
		{
			pS = static_cast<Son*>(arr[i]);
			pS->walk();

			pS = static_cast<Son*>(arr[i]);
			pS->play();
		}

	}
}

int main()
{

	Grandpa * arr[3] = { new Grandpa, new Daddy, new Son };
	life_dynamic_cast(arr);
	life_typeid(arr);


	cout << endl;
	system("pause");
	return 0;

}