#include <iostream>

using namespace std;

struct students     // 1 пункт
{
	string Surname;
	string Name;
	int Score[3];
	int Sum;
};

void showData(students* st, int amount)
{
	for (int i = 0; i != amount; i++) //4 пункт
	{
		cout << "#" << i + 1 << " Surname:\t" << st[i].Surname << "\t" << " Name:\t" << st[i].Name << "\t" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "Score # " << j + 1 << ": " << st[i].Score[j] << endl;
		}
	}
}

// 4 пункт
void punktPiat(students* st, int amount)
{
	for (int i = 0; i != amount; i++)
	{
		if (st[i].Sum % 4 == 0)         
		{
			int sum = 0;

			for (int j = 0; j != 3; j++)
			{
				sum += st[i].Score[j];

				st[i].Sum = sum / 3;

			}
		}
		else if (st[i].Sum % 4 == 1)   
		{
			int max = st[i].Score[0];

			for (int j = 0; j != 3; j++)
			{
				if (max < st[i].Score[j]) st[i].Sum = st[i].Score[j];
			}
		}
		else if (st[i].Sum % 4 == 2)  
		{
			int min = st[i].Score[0];

			for (int j = 0; j != 3; j++)
			{
				if (min > st[i].Score[j]) st[i].Sum = st[i].Score[j];
			}
		}
		else if (st[i].Sum % 4 == 3)  
		{
			int sum = 0;

			for (int j = 0; j != 3; j++)
			{
				sum += st[i].Score[j];

				st[i].Sum = sum;
			}
		}
	}
}

// 5 пункт
int main()
{
	int amount, sum;

	cout << "Please enter amount of students" << endl;
	cin >> amount;

	if (amount < 2) // 2 пункт
	{
		cout << "Please enter bigger number" << endl;
	}
	else  //3 пункт
	{
		students* st = new students[amount];

		for (int i = 0; i != amount; i++)
		{
			cout << "#" << i + 1 << " Please enter surname" << endl;
			cin >> st[i].Surname;

			cout << "#" << i + 1 << " Please enter name" << endl;
			cin >> st[i].Name;

			cout << "#" << i + 1 << " Please enter scores" << endl;

			for (int j = 0; j <3;j++ )
			{
				cin >> st[i].Score[j];
			}
		}
		
		showData(st,amount);
	
		punktPiat(st,amount);

		cout << "\t Sorted data\t" << endl;

		cout << " --------------------------------------------------------------------\t" << endl;

		showData(st, amount); // 6 пункт 

		delete[] st; //7 пункт
	}
}



