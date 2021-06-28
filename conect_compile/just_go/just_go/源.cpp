#include <iostream>
using namespace std;

int main()
{
	unsigned char dbyte[] = { 0x34,0x45,0x56,0x67,0xaf };
	for (int i = 0; i < 5; i++)
	{
	char temp = dbyte[i];
	_asm {
		mov cl, 4
		ror temp, cl
	}
	dbyte[i] = temp;
	}
	for (int i = 0; i < 5; i++)
		cout << "OX" << hex << (int)dbyte[i] << endl;


	return 0;
}