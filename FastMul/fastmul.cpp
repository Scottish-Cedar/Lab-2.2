
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
	int input();
	int getc1();
	int getm(int i);
	string output();
	bool div2(int &a);
};

Z::Z()
{

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
				mass[i] = massh[c];
				i++;
				c--;
			}
		}
		else
		{
			mass[i] = k;
			i++;
		}
	}
	c1 = i;
	return c1;
}

string Z::output()
{
	int i = 0;
	string x1 = "";
	int c1 = Z::input();
	while (i <= c1 - 2)
	{
		x1 += (mass[i] + 48);
		i++;
	}
	return x1;
}

bool Z::div2(int &a)
{
	if (a % 2 != 0)
	{
		 return false;
	}
	else return true;
}

int main()
{
	string x1 = "";
	Z Z1;
	x1 = Z1.output();
	long a = 0;
	int i = 0;
	while (i<Z1.getc1())
	{
		a += Z1.getm(i) * pow(10, Z1.getc1()-i-2);
		i++;
	}
	cout << a << endl;
	cout << x1 << endl;
	int k = Z1.getc1()-1;
	cout << k<< endl;
	int xl=0, xr=0;
	if (Z1.div2(k))
	{
		int i = 0;
		while (i < k / 2)
		{
			xl += Z1.getm(i)*pow(10, k/2 - i-1);
			i++;
		}
		while (i < k)
		{
			xr += Z1.getm(i)*pow(10, k-i-1);
			i++;
		}
		cout << xl << "*10^"<<k/2<<"+" << xr << endl;
	}
	else
	{
		int i = 0;
		while (i < 1+(k / 2))
		{
			xl += Z1.getm(i)*pow(10, k/2-i);
			i++;
		}
		while (i < k)
		{
			xr += Z1.getm(i)*pow(10, k-i-1);
			i++;
		}
		cout << xl << "*10^" << k / 2 << "+" << xr << endl;
	}
	system("pause");
	return 0;
}
