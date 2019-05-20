//
//  main.cpp
//  BinaryTreeWithParent
//
//  Created by Pavel Murzinov on 27/10/2018.
//  Copyright © 2018 Pavel Murzinov. All rights reserved.
//

#include <iostream>
#include "BinaryParent.h"

int main(int argc, const char * argv[])
{
    Binary<int> Tree;
    
    Tree.add(10);
    Tree.add(5);
    Tree.add(3);
    Tree.add(6);
    Tree.add(20);
    Tree.add(22);
    Tree.add(21);
    Tree.add(23);
    Tree.add(2);
    Tree.add(1);
    Tree.straight(Tree.first());
    cout << endl << "-------------------------------" << endl;
    Tree.symmetric(Tree.first());
    cout << endl << "-------------------------------" << endl;
    Tree.revers(Tree.first());
    cout << endl << "-------------------------------" << endl;

    Tree.deleteNode(Tree.first(), 20);
    Tree.symmetric(Tree.first());
    cout << endl << "-------------------------------" << endl;

    Tree.deleteNode(Tree.first(), 3);
    Tree.symmetric(Tree.first());
    cout << endl << "-------------------------------" << endl;
    
    Tree.deleteNode(Tree.first(), 10);
    Tree.symmetric(Tree.first());
    cout << endl << "-------------------------------" << endl;
    
    Tree.beside(6);
    cout << endl << "-------------------------------" << endl;
    return 0;
}

//Выполняется... Добавление элемента. Вывод элементов требя смособами. Удаление элемента в дереве, если от этого элемента дерево не продолжается.
//Нужно сделать... Удаление элемента из середины и в начале. Поиск двух ближайших элементов.
