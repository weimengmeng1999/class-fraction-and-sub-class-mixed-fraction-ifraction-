#include<iostream>// include information about standard library iostream
#include <iomanip>// include information about standard library iomanip 
#include<cmath>// include information about standard library cmath
using namespace std;

class fraction //define a class named fraction
{
private:
	int top;//the numerator of fraction
	int bottom; //the denominator of fraction

public:
	//initialize functions
	fraction(); //initialize the fraction with no argument
	fraction(int x); //initialize the fraction with one argument
	fraction(int x, int y); //initialize the fraction with two arguments

	friend int lcomu(int a, int b); //declare a function of the type of integer to get the least common mutiple between two integers
	friend int gcodi(int a, int b); //declare a function of the type of integer to get the greatest common divior between two integers

	fraction simplify(fraction &x); //declare a function whose return value is a fraction to simplfy the fractions

	void show(fraction &x); //decalre a function to output the fraction in the screen
	void getf(fraction &x); //declare a function to read the input fraction
	void man(fraction &x); //declare a function to ensure that only the numerator can be positive
	double decimal(fraction &x);// declare a function to convert the fraction into decimal

	friend const fraction operator +(const fraction &x, const fraction &y); //overload the "+' operator to calculate the sum of two fractions
	friend const fraction operator -(const fraction &x, const fraction &y); //overload the "-' operator to calculate the difference of two fractions
	friend const fraction operator *(const fraction &x, const fraction &y); //overload the "*' operator to calculate the mutiply of two fractions
	friend const fraction operator /(const fraction &x, const fraction &y); //overload the "/' operator to calculate the division of two fractions

	friend bool operator >(fraction &x, fraction &y); //overload the ">' operator to test whether a fraction is larger than the another one
	friend bool operator <(fraction &x, fraction &y); //overload the "<' operator to test whether a fraction is smaller than the another one
	friend bool operator >=(const fraction &x, const fraction &y); //overload the ">=' operator to test whether a fraction is larger than or equals to the another one
	friend bool operator <=(const fraction &x, const fraction &y); //overload the "<=' operator to test whether a fraction is smaller than or equals to the another one
	friend bool operator !=(const fraction &x, const fraction &y); //overload the "!=' operator to test whether a fraction dose not equal to the another one
	friend bool operator ==(const fraction &x, const fraction &y); //overload the "==' operator to test whether a fraction equals to the another one

	fraction& operator =(const fraction &x);//overload the "=' operator to assign a value to a variable
};


class ifraction :public fraction{//define a sub class named ifraction

private:
	int integer;//define an int as integer
	fraction fra;//define a fraction fra

public:
	ifraction();//initialize the ifraction with no argument
	ifraction(int x);//initialize the ifraction with one argument
	ifraction(int x, int y, int z); //initialize the fraction with two arguments

	void simple(ifraction &x);//declare a function whose return value is a fraction to simplfy the fractions
	void showif(ifraction &x);//declare a function to output the fraction in the screen
	friend ifraction convert(fraction &x);//declare a friend function to convert the inputted improper fraction
};

//define the functions to declared the class of fraction
fraction::fraction(){
	top = 0; //the initial value is 0/1
	bottom = 1;
}
fraction::fraction(int x){
	top = x; //the initial value is x/1
	bottom = 1;
}
fraction::fraction(int x, int y){
	while (y == 0) //ensure the denominator can not be 0
	{
		cout << "the denominator can not be 0, please input another one:"; //ask the user input another denominator until the denominator dose not equal to 0
		cin >> y;
	}
	if (y < 0){ //ensure the denominator can not be negative and only the numerator can be negative 
		x = (-1)*x; //if the denominator is negative, let the numerator be its opposite value
		y = (-1)*y; // let the denominator be its opposite value
	}
	top = x; //the initial value of the fraction is x/y
	bottom = y;
}

int gcodi(int a, int b){
	if (a == 0 || b == 0){ // if there is a 0 value, the greatest common divisor should be 1
		return 1;
	}
	a = abs(a); //let the two integers be their opposite value to ensure they are all positive
	b = abs(b);
	while (a != b){ // if the two integers are not equal, using the continues minus method until they equal to each other
		if (a > b){
			a = a - b; //let the larger integer be the difference between the two integers
		}
		else b = b - a;
	}
	return a; //return the value of largest common divisor
}
int lcomu(int a, int b){
	a = abs(a); //let the two integers be their opposite value to ensure they are all positive
	b = abs(b);
	int c; //declare a variable to store the result
	c = a*b / gcodi(a, b); //calculate the value of least common multiple
	return c; //return the value of the least common multiple
}



fraction fraction::simplify(fraction &x){
	int a; //declare a variable to store the value of the greatest common divisor of the denominator and numerator of a fraction
	a = gcodi(x.top, x.bottom);//calculate the greatest common divisor of the denominator and numerator of a fraction
	x.top = x.top / a; //divid the numerator by the greatest common divisor
	x.bottom = x.bottom / a; //divid the denominator by the greatest common divisor
	return x; //return the simpelest form of the fraction
}

void fraction::man(fraction &x){
	if (x.bottom < 0){ //test whether the denominator is negative
		x.top = (-1)*x.top; //if the denominator is negative, let the numerator be its opposite value
		x.bottom = (-1)*x.bottom; //let the denominator be its positive value
	}

}

void fraction::getf(fraction &x){
	cout << "please input the numerator:"; //ask the user to input the numerator
	cin >> x.top; //store the input into the numerator of the fraction
	cout << "please input the denominator:"; //ask the user to input the denominator
	cin >> x.bottom;//store the input into the numerator of the fraction
	while (x.bottom == 0){ //test whether the denominator is 0
		cout << "the denominator can not be 0, please input again:"; //ask the user to input another value of denominator that is not 0
		cin >> x.bottom; //store the input into the numerator of the fraction
	}
	x.man(x); //using man function to ensure that only the numerator can be positive
}

void fraction::show(fraction &x){
	x.simplify(x); //using simplify function to get the simplest form of fraction
	cout << x.top << "/" << x.bottom; //output the fraction on the screen
}

double fraction::decimal(fraction &x)
{
	double a, b, c;//define tow double variables: one for changing the numeratir to be double, another one for store the result
	a = (double)x.top;// convert the numerator into double */
	b = (double)x.bottom;
	c = a / b;/* assign g as e divde f */
	return c;
}


const fraction operator +(const fraction &x, const fraction &y){
	fraction c; //declare a fraction variable to store the result of the sum of two fractions
	c.bottom = lcomu(x.bottom, y.bottom); //calculate the least common multiple of the two denominators of two fraction, which equals to the denomitor of the sum
	c.top = x.top*(c.bottom / x.bottom) + y.top*(c.bottom / y.bottom); //calculate the sum of the numerator
	return c; //return the value of sum
}
const fraction operator -(const fraction &x, const fraction &y){
	fraction c; //declare a fraction variable to store the result of the difference of two fractions
	c.bottom = lcomu(x.bottom, y.bottom);//calculate the least common multiple of the two denominators of two fraction, which equals to the denomitor of the difference
	c.top = x.top*(c.bottom / x.bottom) - y.top*(c.bottom / y.bottom); //calculate the difference of the numerator
	return c;//return the value of difference
}
const fraction operator *(const fraction &x, const fraction &y){
	fraction c; //declare a fraction variable to store the result of the mutiply of two fractions
	c.bottom = x.bottom*y.bottom; //calculate the denominator of the mutiply 
	c.top = x.top*y.top; //calculate the numerator of the mutiply
	c.simplify(c); //simplify the fraction
	return c; //return the result of simplify
}
const fraction operator /(const fraction &x, const fraction &y){
	fraction c; // declare a fraction variable to store the result of the division of two fractions
	c.bottom = x.bottom*y.top;//calculate the denominator of the division
	c.top = x.top*y.bottom;//calculate the numerator of the division
	c.simplify(c);//simplify the fraction
	return c; //return the result of simplify
}


bool operator >(fraction &x, fraction &y){
	if ((x - y).top>0){ //judge by comparing the difference between numerators and 0
		return true; //if the difference is larger than 0, return true
	}
	else return false;
}
bool operator <(fraction &x, fraction &y){
	if ((x - y).top<0){ //if the difference of numerators is smaller than 0, return true
		return true;
	}
	else return false;
}
bool operator >=(const fraction &x, const fraction &y){
	if ((x - y).top >= 0){//if the difference of numerators is larger than 0 or equals to 0, return true
		return true;
	}
	else return false;
}
bool operator <=(const fraction &x, const fraction &y){
	if ((x - y).top <= 0){//if the difference of numerators is smaller than 0 or equals to 0, return true
		return true;
	}
	else return false;
}
bool operator !=(const fraction &x, const fraction &y){
	if ((x - y).top != 0){//if the difference of numerators does not equal to 0, return true
		return true;
	}
	else return false;
}
bool operator ==(const fraction &x, const fraction &y){
	if ((x - y).top == 0){//if the difference of numerators equals to 0, return true
		return true;
	}
	else return false;
}

fraction& fraction::operator =(const fraction &x){
	if (this != &x){// assign the value
		top = x.top;
		bottom = x.bottom;
	}
	return *this;
}


ifraction::ifraction(){//initialize a fraction
	integer = 0;
	fraction fra;
}

ifraction::ifraction(int x){//initialize a fraction with an argument
	integer = x;
	fraction fra;
}


ifraction::ifraction(int x, int y, int z) :fraction(y, z){//intialize fractions
	integer = x;
	fra = fraction(y, z);
}

void ifraction::simple(ifraction &x){//simplify the fraction
	x.simplify(x.fra);
	while (x.fra >= 1){// if fra is larger or equal to 1, fra by minus 1 each time
		x.fra = x.fra - 1;
		x.integer++;//intger plus 1 each time
	}
}

void ifraction::showif(ifraction &x){// print the fraction on the screen
	x.simple(x);// simplified the fraction first 
	cout << "the mixed fraction is" << x.integer << "(";// print the mixed fraction on the screen 
	x.show(x.fra);
	cout << ")\n";
}

ifraction convert(fraction &x){// convert the improper fraction
	ifraction a;
	fraction c(1, 1);
	int b = 0;// define an int b as 0
	while (x >= c){// if x is larger or equal to c, then do the loop
		b++;//b plus 1 each time
		x = x - 1;//x minus 1 each time
	}
	a.integer = b;//assign the value of b to integer of a
	a.fra = x;//assign the value of x to fra of a 
	a.simplify(a.fra);//simplify the fraction
	return a;//return the value of a 
}

int main(){
	cout << "please input the fraction you want to convert";//ask the user to input the fraction
	fraction c;
	c.getf(c);//get the fraction
	ifraction z;
	z = convert(c);//go to the convert function
	z.showif(z);

}