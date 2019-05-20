//
//  BinaryParent.h
//  BinaryTreeWithParent
//
//  Created by Pavel Murzinov on 27/10/2018.
//  Copyright © 2018 Pavel Murzinov. All rights reserved.
//

#ifndef BinaryParent_h
#define BinaryParent_h

using namespace std;

template <class t>
class Binary{
private:
    struct Node{
        t value;
        Node *pNextLeft;
        Node *pNextRight;
        Node *pParent;
        
        Node(t val, Node *parent = NULL) : value(val), pParent(parent), pNextLeft(NULL), pNextRight(NULL) {}
    };
    
    Node *head;
    
public:
    Binary();
    void add(t date); //добавление элемента
    
    Binary<t>::Node *first()//возврат указателя на первый узел
    {
        return this->head;
    }
    
    void straight(Node *point);//прямой проход дерева
    void symmetric(Node *point);//симметричный проход по дереву
    void revers(Node *point);//обратный проход по дереву
    
    void deleteNode(Node *point, t date);//удаление узла из дерева
    
    Binary<t>::Node *find(t date, Node *point)//поиск элемента в дереве 
    {
        if (point == NULL)
        {
            cout << date <<" - Not Found!\n";
            return NULL;
        }
        if (point->value == date)
        {
            return point;
        }
        else if (point->value > date)
        {
            return find(date, point->pNextLeft);
        }
        else
        {
            return find(date, point->pNextRight);
        }
    }
    
    void beside(t date);//вывод на экран двух ближайших значений к элементу из дерева
};

template <class t>
Binary<t>::Binary()
{
    head = NULL;
}

template <class t>
void Binary<t>::add(t date) // добавление элемента в дерево
{
    if (this->head == NULL)
    {
        this->head = new Node(date);
    }
    else
    {
        Node *curret = this->head;
        Node *temp_value = NULL;
        bool flag = 0;
        
        while (curret != NULL)
        {
            if (curret->value == date) return;
            
            if (curret->value < date)
            {
                temp_value = curret;
                curret = curret->pNextRight;
                flag = true;
            }
            else
                if (curret->value > date)
                {
                    temp_value = curret;
                    curret = curret->pNextLeft;
                    flag = false;
                }
        }
        
        if (flag)
        {
            temp_value->pNextRight = new Node(date, temp_value);
        }
        else
        {
            temp_value->pNextLeft = new Node(date, temp_value);
        }
    }
}

template<class t>
void Binary<t>::symmetric(Node *point)
{
    if (point != NULL)
    {
        symmetric(point->pNextLeft);
        
        cout << point->value << ' ';
        
        symmetric(point->pNextRight);
    }
}

template <class t>
void Binary<t>::straight(Node *point)
{
    if (point != NULL)
    {
        cout << point->value << ' ';
        
        straight(point->pNextLeft);
        straight(point->pNextRight);
    }
}

template <class t>
void Binary<t>::revers(Node *point)
{
    if (point != NULL)
    {
        revers(point->pNextLeft);
        revers(point->pNextRight);
        
        cout << point->value << ' ';
    }
}

template <class t>
void Binary<t>::deleteNode(Node *point, t date)
{
    if (point == NULL) return;
    
    if (date < point->value)
        deleteNode(point->pNextLeft, date);
    else if (date > point->value)
        deleteNode(point->pNextRight, date);
    else
    {
        if (point->pNextLeft == NULL && point->pNextRight == NULL)
        {
            if (point->pParent->pNextLeft == point)
                point->pParent->pNextLeft = NULL;
            else
                point->pParent->pNextRight = NULL;
            delete point;
        }
        else
        {
            if (point->pNextLeft != NULL && point->pNextRight != NULL)
            {
                if (point->pParent == NULL)
                {
                    point->pNextLeft->pParent = NULL;
                }
                else
                {
                    if (point->pParent->pNextLeft == point)
                    {
                        point->pParent->pNextLeft = point->pNextLeft;
                    }
                    else
                    {
                        point->pParent->pNextRight = point->pNextLeft;
                    }
                }
                
                Node *temp = point->pNextLeft;//начала куска который может повторяться
                
                while (temp->pNextRight != NULL)
                    temp = temp->pNextRight;
                
                point->pNextRight->pParent = temp;
                temp->pNextRight = point->pNextRight;
                
                if (point->pNextLeft->pParent == NULL)
                    this->head = point->pNextLeft;
                
                delete point;
                return;
            }
            else
            {
                if (point->pNextLeft == NULL) //проверка: в какую сторону выходит дерево из узла
                {
                    point->pNextRight->pParent = point->pParent;
                    
                    if (point->pParent->pNextLeft == point)
                    {
                        point->pParent->pNextLeft = point->pNextRight;
                    }
                    else
                    {
                        point->pParent->pNextRight = point->pNextRight;
                    }
                }
                else
                {
                    point->pNextLeft->pParent = point->pParent;
                    
                    if (point->pParent->pNextLeft == point)
                    {
                        point->pParent->pNextLeft = point->pNextLeft;
                    }
                    else
                    {
                        point->pParent->pNextRight = point->pNextRight;
                    }
                }
                delete point;
            }
        }
    }
}

template <class t>
void Binary<t>::beside(t date) //вывод ближайших элементов
{
    Node *curret = find(date, this->head);
    
    if (curret != NULL)
    {
        Node *left = curret->pNextLeft;
        Node *right = curret->pNextRight;
        
        if (left != NULL)
        while (left->pNextRight != NULL)
            left = left->pNextRight;
        
        if (right != NULL)
        while (right->pNextLeft != NULL)
            right = right->pNextLeft;
        
        if (left == NULL)
        {
            cout << "NOT!, ";
        }
        else
        {
            cout << left->value << ", ";
        }
        
        if (right == NULL)
        {
            cout << "NOT!";
        }
        else
        {
            cout << right->value;
        }
    }
}
#endif /* BinaryParent_h */
