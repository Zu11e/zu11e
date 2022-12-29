#include <iostream>
#include <sstream>
using namespace std;
 
class CMoney
{
    void init(long roubles, unsigned char copecks, float wholeSum){
        class Array  {
        	unsigned int size;
        	Array *p;
        public:
        	Array()
        	{
        		size = m_size;
        		p = new Array[size];
        	};
        	Array(int size)  {
        		for (int i = 0; i < size; i++)
        			p[i] = 0;
        	}
        	Array(){ delete[] p; };
        	
        };
      
          void splitUp()
          {
               roubles = (int)wholeSum;
               copecks = (int)((wholeSum - (int)wholeSum) * 100);
          }
                void display(wholeSum)
                {
                
                }
          public:
                
                 void get()
                 {
                      cin >> wholeSum;
                      splitUp();
                 };
                 string show()
                 {
                      stringstream out;
                      string str;
                      out << roubles << ",";
                      if (copecks < 10)
                      {
                                  out << "0";
                      }
                      out << copecks;
                      str = out.str();
                      return str;
                 };
                 CMoney operator+ (CMoney arg)
                 { 
                        CMoney temp;
                        temp.wholeSum = this->wholeSum + arg.wholeSum;
                        temp.splitUp();
                        return temp;
                 };
                 CMoney operator- (CMoney arg)
                 { 
                        CMoney temp;
                        temp.wholeSum = this->wholeSum - arg.wholeSum;
                        temp.splitUp();
                        return temp;
                 };
                 float operator/ (CMoney arg)
                 { 
                        float temp;
                        temp = this->wholeSum / arg.wholeSum;
                        return temp;
                 };
                 CMoney operator/ (float arg)
                 { 
                        CMoney temp;
                        temp.wholeSum = this->wholeSum / arg;
                        temp.splitUp();
                        return temp;
                 };
                 CMoney operator* (float arg)
                 { 
                        CMoney temp;
                        temp.wholeSum = this->wholeSum * arg;
                        temp.splitUp();
                        return temp;
                 };
                 bool operator== (CMoney arg)
                 { return (this->wholeSum == arg.wholeSum); };
                 bool operator!= (CMoney arg)
                 { return (this->wholeSum != arg.wholeSum); };
                 bool operator> (CMoney arg)
                 { return (this->wholeSum > arg.wholeSum); };
                 bool operator< (CMoney arg)
                 { return (this->wholeSum < arg.wholeSum); };
                 bool operator>= (CMoney arg)
                 { return (this->wholeSum >= arg.wholeSum); };
                 bool operator<= (CMoney arg)
                 { return (this->wholeSum <= arg.wholeSum); };
    }
};