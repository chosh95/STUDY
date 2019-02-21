<<<<<<< HEAD
#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int year = 1;
	while (true)
	{
		if ((year - A) % 15 == 0 && (year - B) % 28 == 0 && (year - C) % 19 == 0){
			cout << year;
			break;
		}
		else year++;
	}
=======
#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int year = 1;
	while (true)
	{
		if ((year - A) % 15 == 0 && (year - B) % 28 == 0 && (year - C) % 19 == 0){
			cout << year;
			break;
		}
		else year++;
	}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}