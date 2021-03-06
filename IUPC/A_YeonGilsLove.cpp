#include <iostream>

using namespace std;

int main()
{
	string YeonGil = "";
	cin >> YeonGil;

	if (YeonGil[0] == 'E') YeonGil[0] = 'I';
	else if (YeonGil[0] == 'I') YeonGil[0] = 'E';

	if (YeonGil[1] == 'S') YeonGil[1] = 'N';
	else if (YeonGil[1] == 'N') YeonGil[1] = 'S';

	if (YeonGil[2] == 'T') YeonGil[2] = 'F';
	else if (YeonGil[2] == 'F') YeonGil[2] = 'T';

	if (YeonGil[3] == 'J') YeonGil[3] = 'P';
	else if (YeonGil[3] == 'P') YeonGil[3] = 'J';

	cout << YeonGil << endl;

	return 0;
}