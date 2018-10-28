
#include <iostream>
using namespace std;
#include <string>
#include <cmath>

class Z
{
private:
	int mass[1000] = {};
	int c1 = 0;
public:
	Z();
	void check();
	int input();
	int getc1();
	int getm(int i);
	void division(Z, Z&, Z&);
	void operator+=(Z);
	bool div2(int a);
};

Z::Z()
{

}

void Z::check()
{
	int i = 0;
	while (i<c1)
	{
		mass[i + 1] += mass[i] / 10;
		mass[i] = mass[i] % 10;		
		if (mass[i] != 0)
		{
			c1=i;
		}
		i++;
	}
}

void Z::operator+=(Z Z1)
{
	int i = 0;
	while (i < 1000)
	{
		mass[i] += Z1.getm(i);
		i++;
	}
	check();
}

int Z::getc1()
{
	return c1;
}

int Z::getm(int i)
{
	return mass[i];
}

int Z::input()
{
	int masshelp[1000] = {};
	int i = 0;
	while (i < 1000)
	{
		masshelp[i] = 0;
		i++;
	}
	i = 0;
	int k = 0;
	int massh[1000] = {};
	int c = 0;
	while ((i < 1000) && !cin.fail())
	{
		cin >> k;
		if (k > 9)
		{
			c = 0;
			while (k > 0)
			{
				c++;
				massh[c] = k % 10;
				k /= 10;
			}

			while (c > 0)
			{
				masshelp[i] = massh[c];
				i++;
				c--;
			}
		}
		else
		{
			masshelp[i] = k;
			i++;
		}
	}
	c1 = i-1;
	i = 0;
	int i1 = 999;
	while (i <1000)   //98700...00 -> 00...00789 
	{
		mass[i1] = masshelp[i];
		i++;
		i1--;
	}
	i--;	
	return c1;
}  

void Z::division(Z Z1, Z& Z2,Z& Z3) //00...00987654321 -> 00..0009876 + 00...0054321
{
	int i = 0;
	int k = 999;
	while (i < c1 / 2)
	{
		Z2.mass[k] = Z1.mass[k];
		i++;
		k--;
	}
	while (i < c1)
	{
		Z3.mass[k] = Z1.mass[k];
		i++;
		k--;
	}
	i = 0;
	while (i < 1000)
	{
		cout << Z2.mass[i];
		i++;
	}
	i = 0;
	while (i < 1000)
	{
		cout << Z3.mass[i];
		i++;
	}
}

bool Z::div2(int a)
{
	if (a % 2 != 0)
	{
		 return false;
	}
	else return true;
}



int main()
{
	Z Z1, Z2, Z3;
	Z1.input();
	Z1.division(Z1,Z2,Z3);
	system("pause");
	return 0;
}
