
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
	int kara(Z Z1, Z Z2);
	void division(Z);
	void operator+=(Z);
	bool div2(int a);
};

Z::Z()
{

}

void Z::check()
{
	int i = 0;
	while (i < c1)
	{
		mass[i + 1] += mass[i] / 10;
		mass[i] = mass[i] % 10;
		if (mass[i] != 0)
		{
			c1 = i;
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
	int i = 0;
	while (i < 1000)
	{
		mass[i] = 0;
		i++;
	}
	string k;
	cin >> k;
	i = 0;
	while (i<=k.length())
	{
		mass[999 - i] = k[k.length()-i]-'0';
		i++ ;
	}	
	c1 = k.length()+1;
	cout << c1 << endl;
	return c1;
}

void Z::division(Z Z1) //00...00987654321 -> 00..0009876 + 00...0054321
{
	int i = 0;
	int k = 999;
	Z Z2, Z3;
	if (c1 % 2 == 0)
	{
		while (i < c1 / 2)
		{
			Z2.mass[k] = Z1.mass[k];
			i++;
			k--;
		}
	}
	else
	{
		while (i < 1 + c1 / 2)
		{
			Z2.mass[k] = Z1.mass[k];
			i++;
			k--;
		}
	}
	while (i < c1)
	{
		Z3.mass[k] = Z1.mass[k];
		i++;
		k--;
	}
	i = 1000 - c1;
	while (i < 1000)
	{
		cout << Z2.mass[i];
		i++;
	}
	i = 1000 - c1;
	cout << "    ";
	while (i < 1000)
	{
		cout << Z3.mass[i];
		i++;
	}
	cout << "    ";
}

int  Z::kara(Z Z1, Z Z2)
{

	return 0;
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
	Z Z1, Z2;
	Z1.input();
	Z2.input();
	/*while (i < 1000)
	{
		cout << Z1.getm(i);
		i++;
	}*/
	Z2.division(Z2);
	Z1.division(Z1);
	system("pause");
	return 0;
}
