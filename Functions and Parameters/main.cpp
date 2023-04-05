#include <iostream>
#include <iomanip>

using namespace std;

void getPrices(double&, double&, double&);
/*
Preconditions:
Accepts 3 reference parameters as data type double

Postconditions:
Prompts user and stores input in the provided variables
*/

void calcInflationRates(double, double, double, double&, double&);
/*
Preconditions:
Accepts 3 actual parameters as data type double and 2 reference parameters as data type double

Postconditions:
Calculates the inflation rates and stores them in their respective reference parameters provided
*/

void showInflationRates(double, double);
/*
Preconditions:
Accepts 2 actual parameters as data type double

Postconditions:
Outputs the inflation rates and whether or not the inflation rates have been increasing or decreasing or neither
*/

int main() {
  double priceYearsAgo3, priceYearsAgo2, priceYearsAgo1;
  double rate1, rate2;

  cout << showpoint << fixed << setprecision(2);

  getPrices(priceYearsAgo1, priceYearsAgo2, priceYearsAgo3);

  calcInflationRates(priceYearsAgo1, priceYearsAgo2, priceYearsAgo3, rate1, rate2);

  showInflationRates(rate1, rate2);

  return 0;
}

void getPrices(double& priceYearsAgo1, double& priceYearsAgo2, double& priceYearsAgo3) {
  //Prompts user for input in relation to price of an item indicated years ago

  cout << "Enter the price of an item two years ago as a decimal value: ";
  cin >> priceYearsAgo3;

  cout << "Enter the price of the same item one year ago as a decimal value: ";
  cin >> priceYearsAgo2;

  cout << "Enter the price of the same item this year as a decimal value: ";
  cin >> priceYearsAgo1;
}

void calcInflationRates(double priceYearsAgo1, double priceYearsAgo2, double priceYearsAgo3, double& rate1, double& rate2) {
  //Calculates two inflation rates in respect to the price of an item said years ago

  rate1 = (priceYearsAgo2 - priceYearsAgo3) / priceYearsAgo3;
  
  rate2 = (priceYearsAgo1 - priceYearsAgo2) / priceYearsAgo2;
}

void showInflationRates(double rate1, double rate2) {
  //Outputs the inflation rates provided and determines and outputs the change in the rates as increasing, decreasing, or static

  cout << "The inflation rate from two years ago to last year was " << rate1*100 << '%' << endl;

  cout << "The inflation rate from one year ago to today is " << rate2*100 << '%' << endl;

  cout << "The inflation rate has been ";
  if (rate2 - rate1 == 0) {
    cout << "static.";
  } else if (rate2 - rate1 > 0) {
    cout << "increasing.";
  } else {
    cout << "decreasing.";
  }
}