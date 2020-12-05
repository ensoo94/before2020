#ifndef __ORDERHANDLER__H__
#define __ORDERHANDLER__H__

#include "order.h"
#include "handler.h"
#include <string>

using namespace std;


struct Node
{
    Order order;
	Node* next;
};

struct List
{
    Node* front;
	Node* back;
	int size;
};



class OrderHandler : public Handler
{
    public:
        List* list;
        int sell;
        int vip;

        OrderHandler();
        ~OrderHandler();
        void addOrder(Order);
        void add(Order);
        void addVip(Order);
        void completeOrder();
        int getSell();

        void print();  //all order
        void save(string);    //save to txt file
        void load(string);    //load from txt file

        void initializeList();
};

#endif // ORDERHANDLER_H_INCLUDED
