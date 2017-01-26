/*
Написано в Kate
Скомпільовано в g++
Містить три функції для чисельного обрахунку інтегралів за формулами прямокутників, трапецій і парабол
*/
#include <iostream.h>
#include <cmath>

//--------------------------------------------------------------------------------------------------------
//інтегровна функція(зараз x^2, на проміжку [0;3] інтеграл рівний 9)

double f(double x)
{
	return(pow(x,2));
}

//--------------------------------------------------------------------------------------------------------
//формула прямокутників
//a, b - межі, s - кількість проміжків розбиття

double pr(double a, double b, double(*y)(double), int s)
{
	double x, l;
	double Sum;
	int i;

	Sum = 0;
	x = (b - a)/s;
	l = a - (x/2);

	for(i=1;i<=s;i++)
	{
		l = l + x;
		Sum = Sum + (y(l)*x);
	}

	return(Sum);
}

//--------------------------------------------------------------------------------------------------------
//формула трапецій
//a, b - межі, s - кількість проміжків розбиття

double tr(double a, double b, double(*y)(double), int s)
{
	double x, l;
	double Sum;
	int i;

	Sum = 0;
	x = (b - a)/s;
	l = a - x;

	for(i=1;i<=s;i++)
	{
		l = l + x;
		Sum = Sum + ((y(l)+y(l+x))/2);
	}

	return(Sum*x);
}

//--------------------------------------------------------------------------------------------------------
//формула парабол
//a, b - межі, s - кількість проміжків розбиття

double par(double a, double b, double(*y)(double), int s)
{
	double x, l;
	double Sum;
	int i;

	Sum = 0;
	x = (b - a)/s;
	l = a - x;

	for(i=1;i<=s;i++)
	{
		l = l + x;
		Sum = Sum + (x/6)*(y(l) + 4*y((2*l+x)/2) + y(l+x));
	}
	return(Sum);
}

int main(void)
{
	double a,b;
	int s;

	cout<<"a:";cin>>a;
	cout<<"b:";cin>>b;
	cout<<"s:";cin>>s;
	cout<<"Прямокутників:"<<pr(a, b, &f, s)<<"\n";
	cout<<"Трикутників:"<<tr(a, b, &f, s)<<"\n";
	cout<<"Парабол:"<<par(a, b, &f, s)<<"\n";

	return(0);
}
