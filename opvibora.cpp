#include <iostream>

using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
 
    cout << "k = "; cin >> k;
	 switch (k)
    {
        case 1: cout << "именительный"; break;
        case 2: cout << "родительный"; break;
        case 3: cout << "дательный"; break;
        case 4: cout << "винительный"; break;
        case 5: cout << "творительный"; break;
        case 6: cout << "предложный"; break;

    }
}