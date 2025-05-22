/*  USAGE: ./<object_name> <mode>
    where, mode = 1 for printing the time in 'ms' mode = 0 for priting in no. of CPU-Cycles.
    For eaxmple:   ./PBC_time a.param 1
    or, ./PBC_time a.param 0
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdint.h> // for intptr_t
#include <pbc/pbc.h>
#include <pbc/pbc_test.h>

#include <ctime>

using namespace std;

int main(int argc, char **argv) {
	if(argc < 3){
		cerr << "Error! Incorrect Usage: ./<object_name> <a.param> <mode>" << endl;
		exit(1);
	}
	size_t mode;
	mode = stoi(argv[2]);
	
	bool debug = false;
	
	pairing_t params;
	pbc_demo_pairing_init(params, argc, argv);
	size_t n; 
	if(debug) n = 10000;
	else n = 10000; // accuracy vs. cost
	
	
	clock_t startTime1, endTime1;
    	double elapsed_time1;
    	double avgTimeTaken1, totalTimeTaken1 = 0.0;
    	
    	clock_t startTime2, endTime2;
    	double elapsed_time2;
    	double avgTimeTaken2, totalTimeTaken2 = 0.0;
    	
    	clock_t startTime3, endTime3;
    	double elapsed_time3;
    	double avgTimeTaken3, totalTimeTaken3 = 0.0;

	clock_t startTime4, endTime4, startTime5, endTime5, startTime6, endTime6, startTime7, endTime7, startTime8, endTime8, startTime9, endTime9, startTime10, endTime10, startTime11, endTime11;
	double elapsed_time4, elapsed_time5, elapsed_time6, elapsed_time7, elapsed_time8, elapsed_time9, elapsed_time10, elapsed_time11;
	double avgTimeTaken4, avgTimeTaken5, avgTimeTaken6, avgTimeTaken7, totalTimeTaken4 = 0.0, totalTimeTaken5 = 0.0, totalTimeTaken6 = 0.0, totalTimeTaken7 = 0.0;
	double avgTimeTaken8, avgTimeTaken9, avgTimeTaken10, avgTimeTaken11, totalTimeTaken8 = 0.0, totalTimeTaken9 = 0.0, totalTimeTaken10 = 0.0, totalTimeTaken11 = 0.0;
	
	clock_t startTime12, endTime12, startTime13, endTime13, startTime14, endTime14, startTime15, endTime15, startTime16, endTime16, startTime17, endTime17, startTime18, endTime18;
    	double elapsed_time12, elapsed_time13, elapsed_time14, elapsed_time15, elapsed_time16, elapsed_time17, elapsed_time18;
    	double avgTimeTaken12, avgTimeTaken13, avgTimeTaken14, avgTimeTaken15, avgTimeTaken16, avgTimeTaken17, avgTimeTaken18;
    	double totalTimeTaken12 = 0.0, totalTimeTaken13 = 0.0, totalTimeTaken14 = 0.0, totalTimeTaken15 = 0.0, totalTimeTaken16 = 0.0, totalTimeTaken17 = 0.0, totalTimeTaken18 = 0.0;
    	
    	
	element_t P1, P2, P3, P4, P5, P6, X1, X2, X3, d1, d2, d3;
  
	element_init_G1(P1, params);
	element_init_G1(P2, params);
	element_init_G1(P3, params);
  
	element_init_G2(P4, params);
	element_init_G2(P5, params);
	element_init_G2(P6, params);
	
	element_init_GT(X1, params);
	element_init_GT(X2, params);
	element_init_GT(X3, params);
	
	element_init_Zr(d1, params);
	element_init_Zr(d2, params);
	element_init_Zr(d3, params);
	
	char *m = "JunaidAlam";
	
    	for(size_t i = 0; i < n; i++){
    		
		/////////////////                      Calculations in G1        /////////////////////////////////////////
		
    		startTime1 = clock();
    		
      		element_from_hash(P1, m, strlen(m));
      		
    		endTime1 = clock();
    		if(mode) elapsed_time1 = static_cast<double>(endTime1 - startTime1)/CLOCKS_PER_SEC*1000;
    		else elapsed_time1 = static_cast<double>(endTime1 - startTime1);
    		totalTimeTaken1 = (totalTimeTaken1 + elapsed_time1);
     		
    		
    		/////////////////                      Calculations in G2        /////////////////////////////////////////
    		
    		
    		startTime5 = clock();
    		
      		element_from_hash(P4, m, strlen(m));
      		
    		endTime5 = clock();
    		if(mode) elapsed_time5 = static_cast<double>(endTime5 - startTime5)/CLOCKS_PER_SEC*1000;
    		else elapsed_time5 = static_cast<double>(endTime5 - startTime5);
    		totalTimeTaken5 = (totalTimeTaken5 + elapsed_time5);
    		
    		
    		/////////////////                      Calculations in GT        /////////////////////////////////////////
    		
    	
    		startTime9 = clock();
    		
      		element_from_hash(X1, m, strlen(m));
      		
    		endTime9 = clock();
    		if(mode) elapsed_time9 = static_cast<double>(endTime9 - startTime9)/CLOCKS_PER_SEC*1000;
    		else elapsed_time9 = static_cast<double>(endTime9 - startTime9);
    		totalTimeTaken9 = (totalTimeTaken9 + elapsed_time9);
    		   		
    		/////////////////                      Calculations in Zr        /////////////////////////////////////////
    		
    		
    		if(debug){
    			element_set_si(d1, 5);
    			element_set_si(d2, 2);
    			element_printf("d1= %B\n", d1);
    			element_printf("d2= %B\n", d2);
    		}
    		
    		startTime12 = clock();
    		
      		element_from_hash(d1, m, strlen(m));
      		
    		endTime12 = clock();
    		if(mode) elapsed_time12 = static_cast<double>(endTime12 - startTime12)/CLOCKS_PER_SEC*1000;
    		else elapsed_time12 = static_cast<double>(endTime12 - startTime12);
    		totalTimeTaken12 = (totalTimeTaken12 + elapsed_time12);
    		if(debug) element_printf("Result of addition: %B\n", d3);
    		}
    	
    	 
    	avgTimeTaken1 = (totalTimeTaken1 / n);
    	avgTimeTaken5 = (totalTimeTaken5 / n);
    	avgTimeTaken9 = (totalTimeTaken9 / n);
    	avgTimeTaken12 = (totalTimeTaken12 / n);
    	
    	cout << endl << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl;
    	
	if(mode){
	        
		cout << "TIME REPORT IN G1 ............." << endl;
		cout << endl << "Cost of Hash from G1 = " << avgTimeTaken1 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN G2 ............." << endl;
		cout << endl << "Cost of Hash from G2 = " << avgTimeTaken5 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN GT ............." << endl;
		cout << endl << "Cost of Hash from GT = " << avgTimeTaken9 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN Zr ............." << endl;
		cout << endl << "Cost of Hash from Zr = " << avgTimeTaken12 << " ms" << endl;
		
	}
	else{
		cout << "TIME REPORT IN G1 ............." << endl;
		cout << endl << "Cost of Hash from G1 = " << avgTimeTaken1 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN G2 ............." << endl;
		cout << endl << "Cost of Hash from G2 = " << avgTimeTaken5 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN GT ............." << endl;
		cout << endl << "Cost of Hash from GT = " << avgTimeTaken9 << " ms" << endl;
		
		cout << endl << "TIME REPORT IN Zr ............." << endl;
		cout << endl << "Cost of Hash from Zr = " << avgTimeTaken12 << " ms" << endl;
		
	}
	
	return 0;
}
