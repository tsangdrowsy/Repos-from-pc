#include<iostream>
using namespace std;

void KTCDX(const char* s)
{
	int n = strlen(s);
	int flag = 1;
	for (int i=0; i < n / 2; i++)
	{
		if (s[i] == s[n - i - 1])
		{
			flag = 1;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		cout << "Chuoi vua nhap la chuoi doi xung";
	else
		cout << "Chuoi vua nhap khong phai la chuoi doi xung";
}

int main()
{
	const char* s = "abccba";
	KTCDX(s);
	return 0;
}