#include <IOStream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// Sets numPrices to a constant
const int numPrices = 10;

int main()
{
	//Initializes variables and sets if stream
	ifstream f;

	string name, stockName, date;
	float stockPrice[10], numHours[10], max, min, change, average, median, sum = 0;

	cout << "Enter stock data file name: ";
	cin >> name;
	f.open(name);
	if (f.fail())
	{
		cout << " Failed to open file " << name << endl;
	}

	else {
		//  Assigns  stockname, date, and stock prices, and the Hour
		f >> stockName >> date;
		for (int i = 0; i < numPrices; i++)
		{
			f >> stockPrice[i];
			sum += stockPrice[i];
			numHours[i] = 8 + i;

			if (numHours[i] > 12)
				numHours[i] = numHours[i] - 12;
		}


		//Print the List of Stocks
		cout << "STOCK: " << stockName << "DATE: " << date << endl;
		cout << "TIME     PRICE" << endl;
		cout << "----     -----" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << setw(2) << numHours[i] << ":00" << setw(5) << "$" << setw(2) << stockPrice[i] << endl;
		}


		//Assigns the Change, Max, Min, average , and minimum
		change = stockPrice[9] - stockPrice[0];
		sort(stockPrice, stockPrice + numPrices);
		max = stockPrice[9];
		min = stockPrice[0];
		average = sum / numPrices;
		median = (stockPrice[4] + stockPrice[5]) / 2;


		//Prints these functions
		cout << " " << endl;
		cout << "CHANGE:  $" << setw(2) << change << setprecision(5) << endl;
		cout << "HIGH:    $" << setw(2) << max << setprecision(5) << endl;
		cout << "LOW:     $" << setw(2) << min << setprecision(5) << endl;
		cout << "AVERAGE  $" << setw(2) << average << setprecision(5) << endl;
		cout << "MEDIAN:  $" << setw(2) << median << setprecision(5) << endl;
	}
	system("pause");
	return 0;
}