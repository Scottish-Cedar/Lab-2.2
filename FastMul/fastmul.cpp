
#include <iostream>
using namespace std;
#include <string>


class Z
{
private:
	int mass[1000] = {};
public:
	Z();
	int input();
	string output();
};

Z::Z()
{

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
	return i;
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

int main()
{
	string x1 = "";
	Z Z1;
	x1 = Z1.output();
	cout << x1 << endl;
	system("pause");
	return 0;
}
