
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

static string in_filename = "test.txt";
static int nrows, ncols, ndrones, nturns, max_load;
static int nptypes, nwhouses, norders;

static vector<int> pweights;
static vector<pair<int, int> > whloc;
static vector<vector<int> > whstock;
static vector<pair<int, int> > orderloc;
static vector<vector<int> > orderp;

int main()
{
	ifstream inFile(in_filename);
	  inFile >> nrows;
	  inFile >> ncols;
	  inFile >> ndrones;
	  inFile >> nturns;
	  inFile >> max_load;
	  
	  inFile >> nptypes;
	  pweights.resize(nptypes);
	  for (int i = 0; i < nptypes; i++)
	    inFile >> pweights[i];
	  inFile >> nwhouses;

	  whloc.resize(nwhouses);
	  whstock.resize(nwhouses);
	  for (int i = 0; i < nwhouses; i++) {
	    inFile >> whloc[i].first;
	    inFile >> whloc[i].second;
	    whstock[i].resize(nptypes);
	    for (int j = 0; j < nptypes; j++) {
	      inFile >> whstock[i][j];
	    }
	  }
	  inFile >> norders;
	  orderloc.resize(norders);
	  orderp.resize(norders);
	  for (int i = 0; i < norders; i++) {
	    inFile >> orderloc[i].first;
	    inFile >> orderloc[i].second;
	    int nprod;
	    inFile >> nprod;
	    orderp[i].resize(nprod);
	    for (int j = 0; j < nprod; j++)
	      inFile >> orderp[i][j];
	  }
	  
	return 0;
}
