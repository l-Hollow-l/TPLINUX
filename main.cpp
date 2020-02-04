#include <iostream>
#include "ArbreBinaire.h"

int main()
{
	ArbreBinaire<int> arb;

	// gauche
	arb.Ajouter(8);
	//arb.Ajouter(8);
	arb.Ajouter(3);
	// std::cout << arb.Minimum() << std::endl;
	// std::cout << arb.Nombre() << std::endl;
	arb.Ajouter(1);
	arb.Ajouter(6);
	//arb.~ArbreBinaire();
	arb.Ajouter(4);
	arb.Ajouter(7);
	std::cout << arb.Minimum() << std::endl;


	// droite
	arb.Ajouter(10);
	arb.Ajouter(14);
	arb.Ajouter(9);
	std::cout << arb.Maximum() << std::endl;
	arb.Ajouter(13);
	arb.Ajouter(16);
	//arb.Enlever(10);
	std::cout << arb.Contient(16) << std::endl;
	arb.Contient(7);
	arb.Enlever(4);
	arb.Enlever(6); // not working
	arb.Enlever(3);
	//arb.Enlever(1);
	arb.AfficherCroissant();
	std::cout <<  std::endl;
	arb.AfficherDecroissant();
	std::cout << arb.Maximum() << std::endl;
	std::cout << arb.Nombre() << std::endl;
}