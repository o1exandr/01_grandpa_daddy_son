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
	Daddy *pD = new Daddy;
	Son *pS = new Son;
	Grandpa *p, pbase;
	Daddy d;
	Son s;
	/*
	Grandpa g;
	Daddy d;
	Son s;
	*/

	cout << "\n\t= typeid =\n";
	for (int i = 0; i < 3; ++i)
	{
	
		cout << "\n\tObject # " << i << endl;
		
		arr[i]->sleep();

		//cout /*<< typeid(*pD).name(); << typeid(*arr[i]).name();
		/*
		cout << "pD: " << typeid(pD).name() << "\tarr[i]: " << typeid(arr[i]).name() << endl;
		cout << "pS: " << typeid(pS).name() << "\tarr[i]: " << typeid(arr[i]).name() << endl;
		cout << "*pD: " << typeid(*pD).name() << "\t*arr[i]: " << typeid(*arr[i]).name() << endl;
		cout << "*pS: " << typeid(*pS).name() << "\t*arr[i]: " << typeid(*arr[i]).name() << endl;
		*/
		
		if (typeid(*pD).name() == typeid(*arr[i]).name())
			pD->walk();

		
		if (typeid(*pS).name() == typeid(*arr[i]).name())
			pS->play();
	
		
		/*
		Grandpa *p, pbase;
		Daddy d;
		Son s;
	
		// демонстрация typeid с полиморфными типами
		p = &pbase;
		cout << "p is pointing to an object of type ";
		cout << typeid(*p).name() << endl;

		p = &d;
		cout << "p is pointing to an object of type ";
		cout << typeid(*p).name() << endl;

		p = &s;
		cout << "p is pointing to an object of type ";
		cout << typeid(*p).name() << endl;
		*/
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