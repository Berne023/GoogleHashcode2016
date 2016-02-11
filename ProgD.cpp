#include <stdio>

vector<int> getIdDrones(vector<Drone> drones) {
	vector<int> idDrones;
	for (int i = 0 ; i < drones.size() ; i++) {
		if (drones[i].dispo)
			idDrones.push_back(i);
	}
	return idDrones;
}

utilite(Pair<Pair<int, int>, int> current, int idCurrent, Pair<Pair<int, int>, int> father, vector<Ordre> ordres) {
	if (idCurrent < ordres.size()) {
		return 1; // Wait 1 turn
	}

	float dist = distance(current.first, father.fisrt) + distance(current.first, ordres.location);
	int weight = current.second - totalWeight(ordres[j]);
	return (float)weight/dist;
}

totalWeight(Ordre ordre) {
	int weight = 0;
	for (int i = 0 ; i < ordre.nproduits.size() ; i++ ) {
		weight += ordre.nproduits[i];
	}
	return weight;
}

//actualiser(Pair<Pair<int, int>, int>> , Pair<Pair<int, int>, int>>, 

void findWay(vector<Drone> drones, vecteor<Produit> produits, vector<Warehouse> warehouses, vector<Ordre> ordres) {
	vector<vector<Drone>> tableDrones;
	vector<vector<Warehouse>> tableWares;
	vector<vector<OrdreElementaire>> tableOrdres;
	
	vector<vector<Pair<Pair<int, int>, int>>> tableau;
	vector<vector<int>> tableauPere;
	tableau.resize(10);
	tableauPere.resize(10);
	for (int i = 0 ; i < 10 ; i++ ) {
		tableau[i].resize(drones.size() + warehouses.size() + ordres.size());
		tableauPere[i].resize(drones.size() + warehouses.size() + ordres.size());
	}

	vector<int> idDrones = getIdDrones(drones);

	int nb;
	int idMax;

	flaot tmp;
	flaot max;

	for ( int i = 0 ; i < 10 ; i++) {
		for (j = idDrones.size() ; j < tableau[i].size() ; j++ ) {
			if (i == 0 )
				nb = isDrones.size();
			else
				nb = tableau.size();
			max = 0;
			idMax = -1;
			for ( k = 0 ; k < nb ; k++ )  {
				tmp = utilite(tableau[i][j], j, tableau[i-1][k], ordres);
				if (max < tmp) {
					max = tmp;
					idMax = k;
				}
			}
			actualiser(tableau[i][j], tableau[i-1][idMax], tableauPere[i][j], idMax);
		}
		
	}
}
