#ifndef ARBREBINAIRE_H__
#define ARBREBINAIRE_H__

template <class T>
class ArbreBinaire
{
private:
	struct Noeud
	{
		T valeur;
		Noeud* gauche;
		Noeud* droite;

		Noeud(const T& valeur, Noeud* gauche = 0, Noeud* droite = 0) : valeur(valeur), gauche(gauche), droite(droite) {}
	};

	void AfficherCroissant2(Noeud* n);
	void AfficherDecroissant2(Noeud* n);
	void Destruction(Noeud* root);
public:
	ArbreBinaire();
	~ArbreBinaire();

	void Ajouter(const T& valeur);
	void Enlever(const T& valeur);
	bool Contient(const T& valeur) const;
	int Nombre() const;

	const int& Minimum() const;
	const int& Maximum() const;

	void AfficherCroissant();
	void AfficherDecroissant();

private:


	Noeud* m_début;
	Noeud* m_gauche;
	Noeud* m_droite;
	int m_count;



};

template<class T>
void ArbreBinaire<T>::AfficherCroissant2(Noeud* n)
{
	if (n != NULL)
	{
		if (n->gauche != NULL)		
			AfficherCroissant2(n->gauche);

		std::cout << n->valeur << " ";

		if (n->droite != NULL)
			AfficherCroissant2(n->droite);
	}
	else
		std::cout << "Y'a rien" << std::endl;
}

template<class T>
void ArbreBinaire<T>::AfficherDecroissant2(Noeud* n)
{
	if (n != NULL)
	{
		if (n->droite != NULL)
			AfficherDecroissant2(n->droite);

		std::cout << n->valeur << " ";

		if (n->gauche != NULL)
			AfficherDecroissant2(n->gauche);

	}
	else
		std::cout << "Y'a rien" << std::endl;
}

template<class T>
void ArbreBinaire<T>::Destruction(Noeud* root)
{
	if (root != NULL)
	{
		if (root->gauche != NULL)		
			Destruction(root->gauche);
		if(root->droite != NULL)
			Destruction(root->droite);

		std::cout << "Deleted : " << root->valeur << std::endl;
		delete root;		
	}
}

template <class T>

ArbreBinaire<T>::ArbreBinaire() : m_début(0), m_count(0), m_gauche(0), m_droite(0)
{
}
template <class T>

ArbreBinaire<T>::~ArbreBinaire()
{
	Destruction(m_début);
}
template <class T>

void ArbreBinaire<T>::Ajouter(const T& valeur)
{
	Noeud* n = m_début;

	if (m_début == NULL)
	{
		m_début = new Noeud(valeur, 0, 0);
		m_count++;
	}

	while (n)
	{
		if (valeur < n->valeur)
		{
			if (n->gauche == NULL)
			{
				n->gauche = new Noeud(valeur, 0, 0);
				n = n->gauche->gauche;
				m_count++;
			}
			else
				n = n->gauche;
		}

		else if (valeur > n->valeur)
		{
			if (n->droite == NULL)
			{
				n->droite = new Noeud(valeur, 0, 0);
				n = n->droite->droite;
				m_count++;
			}
			else
				n = n->droite;
		}
	}
}
template <class T>

void ArbreBinaire<T>::Enlever(const T& valeur)
{
	if (m_début == NULL)
		std::cout << "Rien" << std::endl;


	Noeud* root = m_début;
	Noeud* parent = NULL;

	while (root != NULL)
	{
		if (valeur < root->valeur)
		{
			parent = root;
			root = root->gauche;
		}
		else if (valeur > root->valeur)
		{
			parent = root;
			root = root->droite;
		}
		else if (valeur == root->valeur)
			break;
	}

	if (root->droite == NULL)
	{
		if (parent == NULL)
			root = root->gauche;
		else
		{
			if (parent->valeur > root->valeur)
				parent->gauche = root->gauche;
			else if (parent->valeur < root->valeur)
				parent->droite = root->gauche;
		}
	}
	else if (root->droite->gauche == NULL)
	{
		root->droite->gauche = root->gauche;

		if (parent == NULL)
			root = root->droite;
		else
		{
			if (parent->valeur > root->valeur)
				parent->gauche = root->droite;
			else if (parent->valeur < root->valeur)
				parent->droite = root->droite;
		}
	}
	else
	{
		Noeud* Maxgauche = root->droite->gauche;
		Noeud* Maxgaucheparent = root->droite;

		while (Maxgauche->gauche != NULL)
		{
			Maxgaucheparent = Maxgauche;
			Maxgauche = Maxgauche->gauche;
		}

		Maxgaucheparent->gauche = Maxgauche->droite;
		Maxgauche->gauche = root->gauche;
		Maxgauche->droite = root->droite;

		if (parent == NULL)
			root = Maxgauche;
		else
		{
			if (parent->valeur > root->valeur)
				parent->gauche = Maxgauche;
			else if (parent->valeur < root->valeur)
				parent->droite = Maxgauche;
		}
	}
}

template <class T>

bool ArbreBinaire<T>::Contient(const T& valeur) const
{
	Noeud* n = m_début;

	while (n)
	{
		if (n->valeur == valeur)
			return true;

		if (valeur <= n->valeur)
			n = m_début->gauche;
		else
			n = n->droite;
	}
	return false;
}
template <class T>

int ArbreBinaire<T>::Nombre() const
{
	return m_count;
}
template <class T>

const int& ArbreBinaire<T>::Minimum() const
{
	Noeud* n = m_début->gauche;

	while (n)
	{
		if (n->gauche == NULL)
			return n->valeur;
		else
			n = n->gauche;
	}
}
template <class T>

const int& ArbreBinaire<T>::Maximum() const
{
	Noeud* n = m_début->droite;

	while (n)
	{
		if (n->droite == NULL)
			return n->valeur;
		else
			n = n->droite;
	}
}
template <class T>

void ArbreBinaire<T>::AfficherCroissant()
{
	AfficherCroissant2(m_début);
}
template <class T>

void ArbreBinaire<T>::AfficherDecroissant()
{
	AfficherDecroissant2(m_début);
}

#endif // !ARBREBINAIRE_H__


