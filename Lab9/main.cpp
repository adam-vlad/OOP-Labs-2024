#pragma once
#include <iostream>
using namespace std;

template <class Key, class Value>
class Map {
private:
	struct Pair {
		Key key;
		Value value;
		int index;
	};
	Pair* v;
	int counter, capacity;
public:
	// Constructor care initializeaza o mapa cu o capacitate initiala de 1 pereche cheie-valoare si un contor la 0
	Map() {
		this->v = new Pair[1];
		this->counter = 0;
		this->capacity = 1;
	}

	// Destructor care elibereaza memoria alocata pentru vectorul de perechi
	~Map() {
		delete[] this->v;
	}

	// Operator [] care permite accesarea sau modificarea valorii asociate unei chei
	Value& operator[](const Key& k) {
		for (int i = 0; i < this->counter; i++) {
			if (this->v[i].key == k) {
				return this->v[i].value; // returneaza valoarea asociata cheii daca aceasta exista deja
			}
		}
		// daca cheia nu exista, adauga o noua pereche cheie-valoare la sfarsitul vectorului
		if (this->counter == this->capacity) {
			Pair* newV = new Pair[this->capacity * 2];
			for (int i = 0; i < this->counter; i++) {
				newV[i] = this->v[i];
			}
			delete[] this->v;
			this->v = newV;
			this->capacity *= 2; // dubleaza capacitatea
		}
		// adauga noua pereche cheie-valoare la sfarsitul vectorului si incrementeaza contorul
		this->v[this->counter].key = k;
		this->v[this->counter].index = this->counter;
		return this->v[this->counter++].value;
	}

	// Seteaza valoarea asociata unei chei
	void Set(Key k, Value v) {
		// Verificam daca cheia exista deja
		for (int i = 0; i < this->counter; i++) {
			if (this->v[i].key == k) {
				this->v[i].value = v; // Actualizam valoarea
				return; // Iesim din functie
			}
		}

		// Daca cheia nu exista, adaugam o noua pereche
		if (this->counter == this->capacity) {
			// Daca am atins capacitatea maxima, dublam capacitatea
			Pair* newV = new Pair[this->capacity * 2];
			for (int i = 0; i < this->counter; i++) {
				newV[i] = this->v[i];
			}
			delete[] this->v;
			this->v = newV;
			this->capacity *= 2;
		}

		// Adaugam perechea noua la sfarsitul vectorului
		this->v[this->counter].key = k;
		this->v[this->counter].value = v;
		this->v[this->counter].index = this->counter; // Indexul este setat ca indexul actual
		this->counter++; // Incrementam contorul de perechi
	}


	// Verifica daca o cheie si o valoare exista in mapa
	bool Get(const Key& k, const Value& v) {
		for (int i = 0; i < this->counter; i++) {
			if (this->v[i].key == k && this->v[i].value == v) {
				return true;
			}
		}
		return false;
	}

	// Returneaza numarul de perechi cheie-valoare din mapa
	int Count() {
		return this->counter;
	}

	// Sterge toate perechile cheie-valoare din mapa
	void Clear() {
		delete[] this->v;
		this->v = new Pair[1];
		this->counter = 0;
		this->capacity = 1;
	}

	// Sterge o pereche cheie-valoare data o cheie
	bool Delete(const Key& k) {
		int poz = 0;
		bool ok = false;
		for (int i = 0; i < this->counter; i++) {
			if (this->v[i].key == k) {
				poz = i;
				ok = true;
			}
		}
		// Rearanjeaza vectorul pentru a elimina perechea cheie-valoare specificata
		for (int i = poz; i < this->counter - 1; i++) {
			this->v[i].key = this->v[i + 1].key;
			this->v[i].value = this->v[i + 1].value;
		}
		this->counter--;
		return ok;
	}

	// Verifica daca toate perechile cheie-valoare dintr-o alta mapa sunt prezente in aceasta mapa
	bool Includes(const Map<Key, Value>& map) {
		bool ok;
		for (int i = 0; i < map.counter; i++) {
			ok = false;
			for (int j = 0; j < this->counter; j++) {
				if (map.v[i].key == this->v[j].key && map.v[i].value == this->v[j].value) {
					ok = true;
					break;
				}
			}
			if (ok == false)
				return false;
		}
		return true;
	}

	// Returneaza pointer la prima pereche cheie-valoare din mapa
	const Pair* begin() { return &this->v[0]; }

	// Returneaza pointer la sfarsitul vectorului de perechi cheie-valoare din mapa
	const Pair* end() { return &this->v[this->counter]; }

};

int main()
{
	// Se creeaza o instanta a clasei Map cu chei de tip int si valori de tip const char*.
	Map<int, const char*> m;

	// Se adauga perechi cheie-valoare in map folosind operatorul de indexare [].
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	m[50] = "val1";
	m[60] = "val2";

	// Se parcurge map-ul si se afiseaza cheile, valorile si indicele fiecarei perechi.
	for (auto [key, value, index] : m) {
		cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
	}

	// Se actualizeaza valoarea asociata cheii 20.
	m[20] = "result";

	// Se afiseaza map-ul dupa actualizare.
	for (auto [key, value, index] : m) {
		cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
	}

	// Se verifica daca map-ul contine o anumita pereche cheie-valoare.
	cout << m.Get(20, "result") << "\n";

	// Se afiseaza numarul total de perechi cheie-valoare din map.
	cout << m.Count() << "\n";

	// Se elimina perechea cheie-valoare asociata cheii 30 din map.
	m.Delete(30);

	// Se afiseaza map-ul dupa eliminare.
	cout << "Map m: \n";
	for (auto [key, value, index] : m) {
		cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
	}

	// Se creeaza o alta instanta a clasei Map si se adauga perechi cheie-valoare.
	Map<int, const char*> n;
	n[10] = "C++";
	n[20] = "result";
	n[30] = "Poo";

	// Se afiseaza map-ul n.
	cout << "Map n: \n";
	for (auto [key, value, index] : n) {
		cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
	}

	// Se verifica daca map-ul n include toate perechile cheie-valoare din map-ul m.
	cout << n.Includes(m);

	return 0;
}
