
#ifndef PILE_GENERIQUE_PILE_H
#define PILE_GENERIQUE_PILE_H

#include <iostream>

using namespace std;
template <typename T>
class Pile {
private:
    T* m_Elements;       // Tableau pour stocker les éléments de la pile
    int m_Capacite;   // Capacité actuelle du tableau
    int m_Taille;      // Nombre d'éléments dans la pile

public:
    // Constructeur par défaut
    Pile() : m_Elements(nullptr), m_Capacite(0), m_Taille(0) {}

    // Destructeur
    ~Pile() {
        delete[] m_Elements;
    }

    // Fonction pour ajouter un élément à la pile
    void Empiler(const T& value) {
        if (m_Taille == m_Capacite) {
            // Si la capacité est atteinte, redimensionner le tableau
            AugmenterCapacite(2 * m_Capacite + 1);
        }
        m_Elements[m_Taille++] = value;
    }

    
    void Depiler() {
        if (EstVide()) {
            throw std::out_of_range("La pile est vide");
        }
        T elem = m_Elements[--m_Taille];
        if (m_Taille > 0 && m_Taille == m_Capacite / 4) {
            // Réduire la capacité du tableau si nécessaire
            AugmenterCapacite(m_Capacite / 2);
        }

    }
    
    T& getSommet() {
        if (EstVide()) {
            throw std::out_of_range("La pile est vide");
        }
        return m_Elements[m_Taille - 1];
    }
    void Afficher()
    {
        Pile<T> tmp;
        while (!EstVide()) {
            cout << getSommet() << " ";
            tmp.Empiler( getSommet());
            Depiler();
        }
        while (!tmp.EstVide())
        {
            Empiler(tmp.getSommet());
            tmp.Depiler();
        }
    }

    // Vérifie si la pile est vide
    bool EstVide() const {
        return m_Taille == 0;
    }

    // Retourne le nombre d'éléments dans la pile
    size_t Taille() const {
        return m_Taille;
    }

private:
    // Fonction pour redimensionner le tableau
    void AugmenterCapacite(int new_capacity) {
        T* tmp = new T[new_capacity];
        for (int i = 0; i < m_Taille; ++i) {
            tmp[i] = m_Elements[i];
        }
        delete[] m_Elements;
        m_Elements = tmp;
        m_Capacite = new_capacity;
    }
};



#endif
