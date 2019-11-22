//Zach Davis Chapter 7 PC Question 2
//This program should that takes a user's input of the total rainfall of the
// last 12 months(vector doubles). The program should then Calculate the
// following: total rainfall in year, monthly avg., month with highest/lowest.


#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

//Inputs
double jan, feb, mar, apr, may, jun, jly, agu, sep, octo, nov, decm;
void test();
int main()
{
	test();
	cout << "Please enter the rainfall (in inches) for each month going from"
		<< "January to December." << endl;
	cin >> jan >> feb >> mar >> apr >> may >> jun >> jly >> agu >> sep >> octo
		>> nov >> decm;

}

//*The total rainfall(in inches) for 12 months
double sum(vector<double> num);
//*A vector for the monthly values to be placed in
vector<double> rainfall(double rain);
vector<double> num = { jan, feb, mar, apr, may, jun, jly, agu, sep, octo, nov, decm };
//*Template for adding the 12 months together
//ERROR: input must return a value
int input() {
	int i = 0;
	while (i < 12) {
		i = i + 1;
		num[i] = num[i] + num[i - 1];
	}
}
//Outputs

//*The total rainfall of all twelve months
//ERROR: totalRain must return a value
double totalRain() {
	cout << "The total Rainfall over the past year is: "
	     << num[12] << endl;
}
//*The avg. rainfall per month
double avgNum;
//ERROR: avgRain must return a value
double avgRain() {
	avgNum = num[12] / 12;
	cout << "The average Rainfall per month is: "
		<< avgNum << endl;
}
//*The two months that had the highest and lowest rainfall

//QUESTION: I am unsure how to compare the values in the vector in order
// to determin the months with the lowest/highest rainfall


//QUESTION: should one assert be covering yearly rainfall, monthly avg., and
//highest/lowest all in one assert? Or should those functions be tested in
//different asserts?
void test() {
	//ERROR: Too many functions in function call
	assert(rainfall(12.0, 10.0) == sum(22.0));
	assert(rainfall(0.0) == sum(0.0));
	assert(rainfall(3.0, 5.0, 7.5) == sum(15.5));
}
