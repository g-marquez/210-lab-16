//*****************************************************************************
// COMSC-210 | Lab 16 | Gabriel Marquez
// Description: this program modifies Lab 14, Color class, such that it
// leverages default, parameter, and partial constructors.
//*****************************************************************************

#include <iostream>
#include <vector> 
#include <string>
using namespace std;

int SIZE = 4;

class Color {
    int red_val;
    int green_val;
    int blue_val;

    public:
    //default, parameter, and partial constructors
    Color() {red_val = 0, green_val = 0, blue_val = 0;}
    Color(int r, int g, int b) {red_val = r, green_val = g, blue_val = b;}
    Color(int r, int g) {red_val = r, green_val = g, blue_val = 0;}
    Color(int r) {red_val = r, green_val = 0, blue_val = 0;}
    //getters and setters
    int getRedVal() const {return this->red_val;}
    int getGreenVal() const {return this->green_val;}
    int getBlueVal() const {return this->blue_val;}
    void setRedVal(int val) {this->red_val = val;}
    void setGreenVal(int val) {this->green_val = val;}
    void setBlueVal(int val) {this->blue_val = val;}
    //member print() method
    void print() {
        cout << "\tRed Value: " << red_val << endl;
        cout << "\tGreen Value: " << green_val << endl;
        cout << "\tBlue Value: " << blue_val << endl;
        cout << endl;
    }
};

int main() {
    //create vector of color objects
    vector<Color> colors;
    //color names to ouput at the end
    string colorNames[SIZE] = {"Black", "White", "Yellow", "Red"};
    
    //create and add color objects to vector
    Color black;
    colors.push_back(black);
    Color white(255, 255, 255);
    colors.push_back(white);
    Color yellow(255, 255);
    colors.push_back(yellow);
    Color red(255);
    colors.push_back(red);

    //output values using color object's print() method
    cout << "Outputting color objects made using construtors: " << endl;
    for (Color c : colors) {
        static int i = 0;
        cout << "Color #" << i + 1 << ": " << colorNames[i] << endl;
        c.print();
        i++;
    }
    return 0;
}