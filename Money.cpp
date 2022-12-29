#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include <iostream>
#include <iomanip>
#include <limits> 
 
using namespace std;
class money
{
private:
int fullcopecs;
 
 
public:
 std::string toString() const;
    money() {fullcopecs=0;}
    money(unsigned int a){fullcopecs=a;}
    money(unsigned int r, unsigned int c){fullcopecs=r*100+c;}
    friend istream &operator >>(istream &in,money &A); //Ввод
    friend ostream &operator <<(ostream &out,money A);  //Вывода
    friend money operator+(money A,money B);//Сложение
    friend money operator-(money A,money B);//Вычитание
    friend int operator/(money A,money B); 
    friend money operator/(money A,int B);
    string operator!();  //в строку
 

 
};
 
 
using namespace std;
 
   //Вводим данные
istream &operator>>(istream &in,money &A) {
    unsigned int roubles, copecks;
    in >>roubles >> copecks;
    A.fullcopecs =roubles*100+copecks;
    return in;
}
//Выводим
ostream &operator<<(ostream &out, money A) 
{
    unsigned int roubles, copecks;
    roubles=A.fullcopecs/100;
    copecks=A.fullcopecs%100;
    out<<"Roubles: "<< roubles <<"; Copecks: "<<copecks<<endl;
    return out;
 
}
    //Складываем
money operator+(money B, money A)
{ 
    money temp;
    temp.fullcopecs =A.fullcopecs+B.fullcopecs; 
    return temp;
}
 
             //Вычитаем
money operator-(money A, money B)
{
    money temp;
    temp.fullcopecs= A.fullcopecs-B.fullcopecs; 
    return temp; 
}
 
 
string money::toString() const 
{
    ostringstream oss;
    unsigned int roubles, copecks;
    roubles=fullcopecs/100;
    copecks=fullcopecs%100;
    oss<<"Roubles: "<<roubles<<"; Copecks: "<<copecks<<endl;
    return oss.str();
}
 
 
 
            //Делим
int operator/(money A, money B)
{   
    unsigned int temp=0;
    if(B.fullcopecs!=0) temp=A.fullcopecs /B.fullcopecs;
    return temp;
}
 
money operator/(money A, int B)
{   
    money temp;
    if(B!=0) temp.fullcopecs =A.fullcopecs/B;
    return temp;
}
 
int main()
{
    money A, B;
 
        cout << "\nEnter first summ in format 'roubles' 'copecks':\t";
        cin >> A;
        cout << "Enter second summ in format 'roubles' 'copecks'':\t";
        cin >> B;
        cout << "Sum:\t\t" << (A+B) << endl;
        cout << "Raznost:\t\t" << ( A - B ) <<endl;
        cout << "Delenien:\t\t" << ( A / B ) <<" chasti" << endl;
        cout << "Delenien na 4 chasti:\t\t" << ( A / 4 ) <<" chasti" << endl;
        cout << " to str: " << A.toString() << endl;
        system ("pause");
       return 0;
}