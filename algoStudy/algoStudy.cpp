// algoStudy.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "src/rotate.h"

#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a = 10;
	int b = 3;
	int c[] = { 1,2,3,4,5,6,7,8,9 };
	int clen = sizeof(c) / sizeof(int);	
	
	for (int cn : c)
	{
		cout << cn << " ";
	}
	cout << endl;
	right_rotate_k(c, 2, 6, 3);

	for (int cn : c)
	{
		cout << cn << " ";
	}
	cout << endl;

	return 0;
}
 
