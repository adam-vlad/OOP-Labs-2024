#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <functional>

template <typename T, unsigned int maxCopii>
struct Node {
    T val;
    int nrCopii = 0;
    Node* parinte;
    Node* copii[maxCopii];

    Node(T valoare, Node* par) {
        val = valoare;
        parinte = par;
        for (unsigned int i = 0; i < maxCopii; i++)
            copii[i] = nullptr;
    }

};

template <typename T, unsigned int maxCopii>
class Tree {
    Node<T, maxCopii>* rad;

public:
    Tree(T rootValue) {
        rad = new Node<T, maxCopii>(rootValue, nullptr);
    }

    ~Tree() {
        delete_node(rad);
    }

    Node<T, maxCopii>* add_node(Node<T, maxCopii>* parent, T value) {
        if (parent == nullptr)
        {
            rad = new Node<T, maxCopii>(value, parent);
            return rad;
        }
        else
        {
            Node<T, maxCopii>* nodAux = new Node<T, maxCopii>(value, parent);
            nodAux->parinte = parent;
            parent->copii[parent->nrCopii++] = nodAux;
            return nodAux;
        }
    }

    Node<T, maxCopii>* get_node(Node<T, maxCopii>* parent) {
        if (parent == nullptr)
            return this->rad;
        else
            return parent;
    }
    void delete_node(Node<T, maxCopii>* parent) {
        for (int i = 0; i < parent->nrCopii; i++)
            delete_node(parent->copii[i]);
        delete parent;
    }
    Node<T, maxCopii>* find(std::function<bool(T&)> compare, Node<T, maxCopii>* start = nullptr) {
        if (!start)
            start = rad;
        if (compare(start->val)) return start;
        for (int i = 0; i < start->nrCopii; i++) {
            auto nod = find(compare, start->copii[i]);
            if (nod)
                return nod;
        }
        return nullptr;
    }
    void insert(Node<T, maxCopii>* parent, int index, int val) {
        if (!parent) return;
        Node<T, maxCopii>* nodNou = new Node<T, maxCopii>(val, parent);
        parent->copii[parent->nrCopii++] = nodNou;
        nodNou->parinte = parent;
    }

    void sort(std::function<bool(const T&, const T&)> compare = nullptr, Node<T, maxCopii>* start = nullptr) {
        if (!start) return;

        if (!compare) {
            compare = [](const T& a, const T& b) { return a < b; };
        }

        int n = start->nrCopii;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!compare(start->copii[i]->val, start->copii[j]->val)) {
                    std::swap(start->copii[i], start->copii[j]);
                }
            }
        }
    }

    int count(Node<T, maxCopii>* parent = nullptr) {
        int cnt = 0;
        auto nodActual = get_node(parent);
        for (int i = 0; i < nodActual->nrCopii; i++)
        {
            if (nodActual->copii[i])
            {
                cnt++;
                cnt += count(nodActual->copii[i]);
            }
        }
        return cnt;
    }

};

#endif // TEMPLATE_H