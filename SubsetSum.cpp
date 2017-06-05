#include <iostream>
using namespace std;

int main()
{
	const int setLength = 5;
	int set[setLength] = {2, 3, 7, 8, 10};
	int input;
	int result[setLength];
	int ctr = 0;

	cin >> input;

	int table[setLength][50];

	for (int i = 0; i < setLength; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			table[i][j] = 0;
		}
	}


	for (int i = 0; i < setLength; i++)
	{
		for (int j = 0; j <= input; j++)
		{
			if (j == 0){
				table[i][j] = 1;
			}
			else{
				if (i == 0){
					if (j == set[i])
						table[i][j] = 1;
					else
						table[i][j] = 0;
				}
				else{
					if (j < set[i]){
						table[i][j] = table[i - 1][j];
					}
					else if (table[i - 1][j] == 1){
						table[i][j] = table[i - 1][j];
					}
					else{
						table[i][j] = table[i - 1][j - set[i]];
					}
				}
			}
		}
	}

	for (int i = 0; i < setLength; i++){
		for (int j = 0; j <= input; j++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	int a = setLength - 1;
	int b = input;

	while (a > 0 || b > 0){
		if (table[a - 1][b] == 1){
			a--;
		}
		else{
			result[ctr++] = set[a];
			b -= set[a];
			a--;

		}
	}

	for (int i = 0; i < ctr; i++){
		cout << result[i] << endl;
	}

	return 0;
}