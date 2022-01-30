#include<iostream>
#include<vector>
#include"src/rapidcsv.h"
#include"gnuplot-iostream.h"
#include"plotme.h"

using namespace std;
using namespace rapidcsv;

void plot() {

	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");
	Document dmeasured("displacement.csv");
	Document dfit("final_fit.csv");
	
	vector<double> getmeasured = dmeasured.GetColumn<double>(0);
	vector<double> getfit = dfit.GetColumn<double>(0);
	
	gp << "set title 'FIT vs Measurement'\n";
	gp << "plot '-' with lines title 'Fit',"
		<< "'-' with lines title 'Measured'\n";

	gp.send(getfit);
	gp.send(getmeasured);

	cin.get();


};