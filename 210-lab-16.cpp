//*****************************************************************************
// COMSC-210 | Lab 16 | Gabriel Marquez
// Description: this program modifies Lab 14, Color class, such that it
// leverages default, parameter, and partial constructors.
//*****************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int SIZE = 5;

class Color {
    string name; //added name member variable
    int red_val;
    int green_val;
    int blue_val;

    public:
    //default, parameter, and partial constructors
    //default constructor creates color named black with all values
    //initialized to 0
    Color() {name = "black", red_val = 0, green_val = 0, blue_val = 0;}
    //parameter constructor
    Color(string str, int r, int g, int b) {
        name = str, red_val = r, green_val = g, blue_val = b;}
    //partial constructors
    Color(string = "")
    //getters and setters
    string getName() const {return this->name;}
    int getRedVal() const {return this->red_val;}
    int getGreenVal() const {return this->green_val;}
    int getBlueVal() const {return this->blue_val;}
    void getName(string str) {this->name = str;}
    void setRedVal(int val) {this->red_val = val;}
    void setGreenVal(int val) {this->green_val = val;}
    void setBlueVal(int val) {this->blue_val = val;}
    //member print() method
    void print() {
        cout << "\tName: " << name << endl;
        cout << "\tRed Value: " << red_val << endl;
        cout << "\tGreen Value: " << green_val << endl;
        cout << "\tBlue Value: " << blue_val << endl;
        cout << endl;
    }
};

int main() {
    //create array of color objects using file input
    Color colors[SIZE];
    //color names to ouput at the end
    string colorNames[SIZE] = {"Grey", "Salmon", "Beige", "Teal", "Maroon"};
    ifstream fin("colors.txt");
    if (fin.good( )) {
        string colorName;
        int red, green, blue;
        int index = 0;

        while (fin >> red) {
            fin >> green;
            fin >> blue;
            
            //create temp color object, populate, and add it to array
            Color temp;
            temp.setRedVal(red);
            temp.setGreenVal(green);
            temp.setBlueVal(blue);
            colors[index] = temp;
            index++;
        }
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    //output values using color object's print() method
    cout << "Outputting color objects: " << endl;
    for (Color c : colors) {
        static int i = 0;
        cout << "Color #" << i + 1 << ": " << colorNames[i] << endl;
        c.print();
        i++;
    }
    return 0;
}