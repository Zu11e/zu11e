# include <iostream>
# include <cmath>
 
using namespace std;
 
int main ()
 
{

  double x,y;
  bool answer;
  cout << "Enter point coordinates." << endl << "Enter x coordinate:";
  cin >> x;
  cout << "Enter y coordinate:";
  cin >> y;
  answer = x>0 && y<0;
  cout << "The point with coordinates (x, y) lies in the fourth coordinate quadrant: " << boolalpha << answer << endl;

}