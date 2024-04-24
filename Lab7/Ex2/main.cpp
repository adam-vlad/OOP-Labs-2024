#include <iostream>
#include "Template.h"

int main() {
    Tree<int, 10> tree(20);
    auto parent = tree.get_node(nullptr);
    printf("radacina: %d\n", parent->val);
    auto parentC1 = tree.add_node(parent, 30);

    auto c1c0 = tree.add_node(parentC1, 25);
    auto c1c1 = tree.add_node(parentC1, 35);
    auto c1c2 = tree.add_node(parentC1, 24);
    auto c1c3 = tree.add_node(parentC1, 21);
    auto c1c4 = tree.add_node(parentC1, 90);


    printf("nr copii radacina: %d\n", parent->nrCopii);
    printf("copil1 al radacinii %d\n", parentC1->val);

    printf("copii lui c1: ");
    for (int i = 0; i < parentC1->nrCopii; i++)
        printf("%d, ", parentC1->copii[i]->val);

    if (tree.find([](const int& val) { return val == 24; }, parent))
    {
        auto nodTest = tree.find([](const int& val) { return val == 24; }, parent);
        nodTest->val = 2999;
        printf("\nvaloarea noua a lui c1c2 este: %d\n", c1c2->val);
    }
    else
    {
        printf("\nvaloarea nu a fost gasita in arbore\n");
    }


    printf("\ninseram un alt copil a lui parentC1\n");
    tree.insert(parentC1, 5, 3);

    printf("copii lui c1: ");
    for (int i = 0; i < parentC1->nrCopii; i++)
        printf("%d, ", parentC1->copii[i]->val);
    printf("\n");

    printf("\ncopii lui c1 sortati sunt: ");
    tree.sort(nullptr, parentC1);
    for (int i = 0; i < parentC1->nrCopii; i++)
        printf("%d, ", parentC1->copii[i]->val);

    printf("\nnumarul de copii ai radacinii este: %d\nnumarul de copii al lui parentC1 este:%d",
        tree.count(parent), tree.count(parentC1));
    printf("\nnumarul de copii al lui c1c4 este: %d", tree.count(c1c4));

    return 0;

}