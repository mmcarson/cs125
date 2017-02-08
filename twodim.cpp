// Program TwoDim manipulates a two-dimensional array
// variable.                                        

#include <iostream>
#include <fstream>
using namespace std;

const int ROW_MAX = 8;
const int COL_MAX = 10;

typedef int ItemType;

typedef ItemType ChartType[ROW_MAX][COL_MAX];

void  GetChart(ifstream&, ChartType, int&, int&);
// Reads values and stores them in the chart.

void  PrintChart(ofstream&, const ChartType, int, int);
// Writes values in the chart to a file. 

void PrintMax(const ChartType, int, int)

int  main ()
{
    ChartType  chart;
    int  rowsUsed;
    int  colsUsed;
    ifstream  dataIn;
    ofstream  dataOut;

    dataIn.open("twod.dat");
    dataOut.open("twod.out");
    GetChart(dataIn, chart, rowsUsed, colsUsed);
    PrintChart(dataOut, chart, rowsUsed, colsUsed);
    return 0;
}
                                                           
//***************************************************    
                                                     
void  GetChart(ifstream&  data, ChartType  chart,
               int&  rowsUsed, int&  colsUsed)
// Pre:  rowsUsed and colsUsed are on the first line of 
//       file data; values are one row per line       
//       beginning with the second line.                
// Post: Values have been read and stored in the chart.                



{
    ItemType  item;
    data  >> rowsUsed >> colsUsed; 

    for (int row = 0; row < rowsUsed; row++)
        for (int col = 0; col < colsUsed; col++)
			data >> chart[row][col];
}                                                            

//****************************************************     

void  PrintChart(ofstream&  data, const ChartType  chart, 
                 int  rowsUsed, int  colsUsed)
// Pre:  The chart contains valid data.
// Post: Values in the chart have been sent to a file by row, 
//       one row per line. 
{
	for (int row = 0; row < rowsUsed; row++)
	{
        for (int col = 0; col < colsUsed; col++)
			data << chart[row][col] << "  ";
		data << endl;
	}
}

