#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include "classes.h"

using namespace std;

static string in_filename = "test.txt";
static int nrows, ncols, ndrones, nturns, max_load;
static int nptypes, nwhouses, norders;

static vector<int> pweights;
static vector<pair<int, int> > whloc;
static vector<vector<int> > whstock;
static vector<pair<int, int> > orderloc;
static vector<vector<int> > orderp;

static vector<Produit> products;
static vector<Warehouse> warehouses;
static vector<Customer> customers;
static vector<Ordre> orders;
static vector<Drone> drones;

void calbarc(){
	int nprod;
	for (unsigned int j =0; j < products.size(); j++){
	  nprod = 0;
		for(unsigned int i =0; i < warehouses.size(); i++){	products[j].barycentre.first+=warehouses[i].nproduits[j]*warehouses[i].location.first;	products[j].barycentre.second+=warehouses[i].nproduits[j]*warehouses[i].location.second;
		nprod += warehouses[i].nproduits[j];
		}
		products[j].barycentre.first /= nprod;
		products[j].barycentre.second /= nprod;
	}
}

void scoreOrder()
{
  for (unsigned int i = 0; i < orders.size(); i++)
  {
    float x_weight = 0;
    float y_weight = 0;
    float dist = 0;
    for (unsigned int j = 0; j < products.size(); j++) {
      cout << orders[i].produits[j] << endl;
      if (orders[i].produits[j] > 0) {
      x_weight += products[j].barycentre.first - (float)orders[i].location.first;
      y_weight += products[j].barycentre.second - (float)orders[i].location.second;
      dist += sqrt(x_weight*x_weight + y_weight*y_weight);
      }
    }
    orders[i].score = dist/(float)orders.size();
  }
}


int main()
{
	int prod_id;
	ifstream inFile(in_filename);
	  inFile >> nrows;
	  inFile >> ncols;
	  inFile >> ndrones;
	  inFile >> nturns;
	  inFile >> max_load;
	  inFile >> nptypes;
	  
	  products.resize(nptypes);
	  drones.resize(ndrones);
	  
	  for (int i = 0; i < nptypes; i++)
	    inFile >> products[i].weight;
	  inFile >> nwhouses;

	  warehouses.resize(nwhouses);
	  for (int i = 0; i < nwhouses; i++) {
	    inFile >> warehouses[i].location.first;
	    inFile >> warehouses[i].location.second;
	    warehouses[i].nproduits.resize(nptypes, 0);
	    for (int j = 0; j < nptypes; j++) {
	      inFile >> warehouses[i].nproduits[j];
	    }
	  }
	  inFile >> norders;
	  orders.resize(norders);
	  for (int i = 0; i < norders; i++) {
	    inFile >> orders[i].location.first;
	    inFile >> orders[i].location.second;
	    int nprod;
	    inFile >> nprod;
	    orders[i].produits.resize(nptypes, 0);
	    for (int j = 0; j < nprod; j++)
	      inFile >> prod_id;
	      orders[i].produits[prod_id] += 1;
	  }
	  
	  
	  calbarc();
	  scoreOrder();
	  
	  for (int i = 0; i <  products.size(); i++)
	  {
	    cout << products[i].barycentre.first << " " << products[i].barycentre.second << endl;
	  }
	  
	  for (int i = 0; i <  orders.size(); i++)
	  {
	    cout << orders[i].score << endl;
	  }
	  
	  
	return 0;
}
