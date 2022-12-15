#include <iostream>
#include <cmath>


using namespace std;
int drop()
{
    int a, b;
    cout << "Chislitel" << endl;
    cin >> a;
    cout << "znamenatel" << endl;
    cin >> b;
    int c = a / b;
    cout << c;
}

int main() {
    drop();
}