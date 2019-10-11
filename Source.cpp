#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int i;
	class games {
	   public:
	   string que; //query
	   float  impact; // impact factor
	   int  quepop; // query popularity
	   int qci;// query competition index

	   void print() {
		   cout << que << "\t\t\t" << impact << "\t" << quepop << "\t" << qci << endl;

		  
			 
		 
		   
	   }
   

	};

	games list[30];
	void readData(games list[]);
	float averages(games list[]);
	string highest(games list[], int &pop);
	string lowest(games list[], int &pop);
	int highestPos(games list[]);
	int lowestPos(games list[]);



	int main() {

		float avg;
		int lpos,hpos;
		string largest,smallest;
		int lpop, spop;

		cout << "query:" << "\tImpact" << "\tQuery Pop" << "\tQCI" << endl;
		readData(list);
		cout << endl;


		avg = averages(list);
		largest = highest(list,lpop);
		smallest = lowest(list, spop);
		lpos = lowestPos(list);
		hpos = highestPos(list);

		cout << "The average impact factor is "<< avg << endl;
		cout << "The largest is " << largest << " with " <<  lpop << endl;
		cout << "The smallest is " << smallest << " with " << spop << endl;
		cout << "The largest is " << list[hpos].que << " with " << list[hpos].quepop << endl;
		cout << "The smallest is " << list[lpos].que << " with " << list[lpos].quepop << endl;


	//float avg = average(list[i].impact,i);


		
		
	}

/*
	void readData(games &list) {
		ifstream infile;
		infile.open("games2.dat");
		
		infile >> list.que;
		infile >> list.impact;
		infile >> list.quepop;
		infile >> list.qci;
*/
	
	//} // end of readData()



	void readData(games list[]) {
		float sum = 0;
		ifstream infile;
		float average;
		infile.open("games2.dat");
		while (infile >> list[i].que >> list[i].impact >> list[i].quepop >> list[i].qci) {
			sum += list[i].impact;
			list[i].print();
			i++;
		}

		average = sum / 10.0;
		cout << average << endl;

	}


	/*
	Function was reading the same line because it was calling the same function. If I can pass an i value, and have that increase,
	I can tell the code to cal la specific line. or do function with array or while loop

	The New Boston's while loop worked
	*/


	float averages(games list[]) {

		float avg;
		float sum = 0;
		for (i = 0; i < 30; i++) {
			sum += list[i].impact;
			
		}
		avg = sum / 30;
		return avg;
    }


	string highest(games list[], int &pop) {
		int largest;
		largest = list[0].quepop;
		int pos = 0;
		for (i = 0; i < 30; i++) {
			if (list[i].quepop > largest) {

				pos = i;
				largest = list[i].quepop;
			}

		}
		pop = list[pos].quepop;
		return list[pos].que;

	}
	

	string lowest(games list[], int& pop) {
		int smallest;
		smallest = list[0].quepop;
		int pos = 0;
		for (i = 0; i < 30; i++) {
			if (list[i].quepop < smallest) {

				pos = i;
				smallest = list[i].quepop;
			}

		}
		pop = list[pos].quepop;
		return list[pos].que;

	}




	int  lowestPos(games list[]) {
		int smallest;
		smallest = list[0].quepop;
		int pos = 0;
		for (i = 0; i < 30; i++) {
			if (list[i].quepop < smallest) {

				pos = i;
				smallest = list[i].quepop;
			}

		}
		
		return pos;

	}




	int  highestPos(games list[]) {
		int largest;
		largest = list[0].quepop;
		int pos = 0;
		for (i = 0; i < 30; i++) {
			if (list[i].quepop > largest) {

				pos = i;
				largest = list[i].quepop;
			}

		}
		return pos;

	}