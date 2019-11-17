#include <iostream>
#include <cmath>
double inchestb(double);
double inchesmeter(double);
double kgFunc(double);
using namespace std;
int main ()
{
	const double m = 0.0254;
	const double k = 2.2;
	const int InchesInFeet = 12;
	double heightInFeet, inches, weightInPounds, meters, kg, bmi;

	cout << "Enter your height in feet: ";
	cin >> heightInFeet;
//	double inches = inchestb(heightFeet);
//	double meters = inchesmeter(inches);
	cout << "Enter your weight in pounds: ";
	cin >> weightInPounds;
	
	inches = heightInFeet * InchesInFeet;
	meters = inches * m;
	kg = weightInPounds / k;
	bmi = kg / pow(meters, 2);
	
//	double kg = kgFunc(weightInPounds);
	cout << "Your height in feet = " << heightInFeet << ", inches = ";
	cout << inches << " and in meters = " << meters <<  endl;
	cout << "Your weight in pounds = " << weightInPounds << " and in killogrms = ";
	cout << kg << endl;
	
	cout << "Your BMI(body mass index) = " << bmi << endl;
	return 0;
	
}
//double inchestb(double feetInches)
//{
//	return InchesInFeet * feetInches;
//}
//double inchesmeter(double meter)
//{
//	return m * meter;
//}
//double kgFunc(double poundsKg)
//{
//	return poundsKg / k;
//}
