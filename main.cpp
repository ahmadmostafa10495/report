#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class CColor
{
    public:
    unsigned int red, green, blue;
    CColor();
    CColor(unsigned int red_,unsigned int green_, unsigned int blue_)
    {
        red = red_;
        green = green_;
        blue = blue_;
    }
    CColor(unsigned int wholeNumber)
    {
        red = wholeNumber | 0x00FF0000;
        red = red >> 16;
        green = wholeNumber | 0x0000FF00;
        green = green >> 8;
        blue = wholeNumber | 0x000000FF;
    }
    CColor average(CColor a, CColor b, CColor c)
    {
        red = a.red + b.red + c.red;
        red /=3;
        green = a.green + b.green + c.green;
        green /= 3;
        blue = a.blue + b.blue + c.blue;
        blue /= 3;
    }
    string getString (string s)
    {
        if (s == "dec")
        return (std::to_string(red)+", "+std::to_string(green)+", "+std::to_string(blue));
        //return ("red = %x, green = %x, blue = %x", red, green, blue);
    }
    ostream& operator << (ostream &os)
    {
        os<<getString("dec");
        return os;
    }
    /*ostream& operator << (ostream &os)
    {
        os<<getString("hex");
        return os;
    }*/
};
int main()
{
    CColor a(255/*red*/, 128/*green*/, 192/*blue*/);
CColor b(0x00667755); //red: 0x66, green: 0x77, blue: 0x55
CColor c(0x00552211);
cout << "a color = " << a << endl; //should prints (255, 128, 192)
cout << "b color = " << b("hex") << endl; //should prints 0x00667755

//Make y = average of a and b and c
CColor y = average(a, b, c);
cout << "y color = " << y << endl;
    return 0;
}
