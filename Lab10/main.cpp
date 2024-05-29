#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Definim o clasa de exceptii pentru cazul in care indexul este in afara intervalului
class Array_Out_Of_Range : public exception {
public:
    virtual const char* what() const throw() {
        return "Indexul specificat nu este in vector.";
    }
};

// Definim o clasa de exceptii pentru cazul in care vectorul este plin
class Array_Out_Of_Space : public exception {
public:
    virtual const char* what() const throw() {
        return "Vectorul a atins dimensiunea maxima.";
    }
};

// Definim o clasa pentru iteratorul array-ului
template<class T>
class ArrayIterator {
private:
    int Current; // Pozitia curenta a iteratorului
    T** arr; // Referinta catre array-ul pe care il iteram
public:
    // Constructor pentru iterator
    ArrayIterator(T** arr, int current) {
        this->arr = arr;
        this->Current = current;
    }

    // Constructor de copiere pentru iterator
    ArrayIterator(const ArrayIterator& other) {
        this->arr = other.arr;
        this->Current = other.Current;
    }

    // Operator de incrementare a iteratorului
    ArrayIterator& operator ++ () {
        this->Current++;
        return *this;
    }

    // Operator de decrementare a iteratorului
    ArrayIterator& operator -- () {
        this->Current--;
        return *this;
    }

    // Operator de egalitate intre doi iteratori
    bool operator==(const ArrayIterator<T>& other) const {
        return this->arr == other.arr && this->Current == other.Current;
    }

    // Operator de inegalitate intre doi iteratori
    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }

    // Metoda pentru a obtine elementul curent al iteratorului
    T* GetElement() const {
        return this->arr[Current];
    }
};

// Definim clasa pentru array
template<class T>
class Array {
private:
    T** List; // Lista cu pointeri la obiecte de tipul T*
    int Capacity; // Dimensiunea maxima a listei de pointeri
    int Size; // Numarul actual de elemente in lista
public:
    // Constructor fara parametri
    Array() {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }

    // Destructor
    ~Array() {
        for (int i = 0; i < this->Capacity; i++)
            if (this->List[i])
                delete this->List[i];

        delete[] this->List;
    }

    // Constructor cu un parametru pentru alocarea initiala a unei liste de capacitate specificata
    Array(int capacity) {
        this->List = new T * [capacity];
        for (int i = 0; i < capacity; i++)
            List[i] = nullptr;
        this->Capacity = capacity;
        this->Size = 0;
    }

    // Constructor de copiere
    Array(const Array<T>& otherArray) {
        this->List = new T * [otherArray.Size];
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Size;
        for (int i = 0; i < this->Capacity; i++)
            this->List[i] = new T(*otherArray.List[i]);
    }

    // Operator pentru accesarea elementelor array-ului
    T& operator[] (int index) {
        if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
            return nullptr;
        }
        return *this->List[index];
    }

    // Operator pentru adaugarea unui element la sfarsitul listei
    const Array<T>& operator+=(const T& newElem) {
        if (this->Size >= this->Capacity) {
            throw Array_Out_Of_Space();
            exit(0);
        }
        else {
            this->List[this->Size] = new T;
            *this->List[this->Size] = newElem;
            Size++;
        }
        return *this;
    }

    // Metoda pentru inserarea unui element la o anumita pozitie in lista
    const Array<T>& Insert(int index, const T& newElem) {
        if (this->Size >= this->Capacity) {
            throw Array_Out_Of_Space();
        }
        else if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
        }
        else
        {
            this->List[this->Size] = new T;
            for (int i = Size; i > index; i--)
            {
                *this->List[i] = *this->List[i - 1];
            }

            *this->List[index] = newElem;
            this->Size++;
        }

        return *this;
    }

    // Metoda pentru inserarea unei alte liste la o anumita pozitie in lista
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (this->Size + otherArray.Size >= this->Capacity) {
            throw Array_Out_Of_Space();
        }
        else if (index < 0 || index > this->Size) {
            throw Array_Out_Of_Range();
        }
        else
        {
            for (int i = this->Size - 1; i >= index; i--)
            {
                this->List[i + otherArray.Size] = this->List[i];
            }
            for (int i = 0; i < otherArray.Size; i++)
            {
                this->List[index + i] = new T(*otherArray.List[i]);
            }

            this->Size += otherArray.Size;
        }

        return *this;
    }

    // Metoda pentru stergerea unui element de la o anumita pozitie in lista
    const Array<T>& Delete(int index) {
        if (index < 0 || index >= this->Size) {
            throw Array_Out_Of_Range();
        }
        else {
            for (int i = index; i < this->Size - 1; i++) {
                this->List[i] = this->List[i + 1];
            }
            this->List[this->Size - 1] = nullptr;
            this->Size--;
        }
        return *this;
    }

    // Operator de atribuire intre doua array-uri
    bool operator=(const Array& otherArray) {
        for (int i = 0; i < this->Capacity; i++)
            delete this->List[i];
        delete[] this->List;

        this->List = new T * [otherArray.Capacity];
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;

        for (int i = 0; i < this->Size; i++)
        {
            this->List[i] = new T(*otherArray.List[i]);
        }
        for (int i = this->Size; i < this->Capacity; i++)
        {
            this->List[i] = nullptr;
        }

        return true;
    }

    // Metoda pentru a obtine numarul actual de elemente din lista
    int GetSize() {
        return this->Size;
    }

    // Metoda pentru a obtine capacitatea listei
    int GetCapacity() {
        return this->Capacity;
    }

    // Metoda pentru a obtine un iterator catre inceputul listei
    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(this->List, 0);
    }

    // Metoda pentru a obtine un iterator catre sfarsitul listei
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(this->List, this->Size);
    }

    // Metoda pentru a afisa lista
    void PrintArray(const char* prompt) {
        cout << prompt;
        for (int i = 0; i < this->Size; i++)
            cout << *this->List[i] << " ";
        cout << "\n";
    }
};

// Functia principala
int main()
{
    // Exemplificarea utilizarii clasei Array

    // Cream un array de intregi cu o capacitate initiala de 10
    Array<int> v(10);


    try {
        // Adaugam cateva elemente
        v += 0;
        v += 1;
        v += 3;

        // Inseram un element la indexul 2
        v.Insert(2, 2);
        v.Insert(14, 3); // Index invalid -> exceptie

        // Adaugam alte elemente
        v += 4;
        v += 5;
    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    // Afisam array-ul
    v.PrintArray("Numere: ");

    // Cream un alt array si adaugam cateva elemente
    Array<int> w(3);
    try {
        w += 6;
        w += 7;
        w += 8;
        w += 9; // Size >= Capacity -> exceptie
    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    // Inseram array-ul w la indexul 3 in array-ul v
    v.Insert(3, w);

    // Afisam noul array v
    v.PrintArray("Numere dupa alipire: ");

    // stergem un element din array-ul v si afisam rezultatul
    v.Delete(6);
    v.PrintArray("Numere dupa stergere: ");

    // Cream un nou array z si il initializam cu array-ul v
    Array<int> z(11);
    z = v;
    z.PrintArray("Elemente z: ");

    // Adaugam un nou element in array-ul z si il afisam
    z += 3;
    z.PrintArray("z nou: ");

    // Exemplu de utilizare a iteratorului
    ArrayIterator<int> i = v.GetBeginIterator();
    for (i = v.GetBeginIterator(); i != v.GetEndIterator(); ++i) {
        cout << *i.GetElement() << " ";
    }
    cout << "\n";

    return 0;
}
