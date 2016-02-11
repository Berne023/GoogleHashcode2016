#ifndef CLASSES_H
#define CLASSES_H

#include <vector>
#include <utility>

using namespace std;

class Produit 
{
public:
int id;
float weight;
pair<float, float> barycentre;
};

class Drone
{
public:
int id;
vector<int> produits;
pair<int, int> location;
bool dispo;
int turns;
int weight;
};

class Warehouse
{
public:
int id;
pair<int, int> location;
vector<int> nproduits;
};

class Customer
{
public:
int id;
pair<int, int> location;
};

class Ordre
{
public:
int id;
int id_customer;
pair<int, int> location;
vector<int> produits;
float score;
};

#endif /* CLASSES_H */