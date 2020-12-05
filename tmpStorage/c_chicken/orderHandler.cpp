#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>	
#include "orderHandler.h"

using namespace std;

OrderHandler::OrderHandler()
{
    list = new List();
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
    sell = 0;
    vip = 0;
}

OrderHandler::~OrderHandler()
{
    initializeList();
    delete list;
}

void OrderHandler::addOrder(Order o)	//add order into the list
{
    int price;
    price = o.getCprice();

    if(o.unpaid==false)  //if the customer (vip) will pay later
    {
        sell+=price;
    }
    else{}  //if the customer will pay later, do not increase the income

    if(o.vip==true)	//if the customer is vip
    {
        addVip(o);
    }
    else    //if the customer is not vip
    {
        add(o);
    }
}

void OrderHandler::add(Order o)	//add order
{
    Node* n = new Node();
	n->order.setChicken(o.getChicken());
	n->order.setAdd(o.getAdd());
	n->order.setName(o.getName());
	n->order.setPnum(o.getPnum());
	n->order.vip = o.vip;
	n->order.mem = o.mem;
	n->order.unpaid = o.unpaid;	//copy
    n->next = NULL;

    if(list->size == 0)
    {
        list->front = n;
        list->back = n;
        list->size++;
        return;
    }

    Node* p;
    p=list->front;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = n;
    list->back = p->next;
    list->size++;
    return;
}

void OrderHandler::addVip(Order o)	//add Vip's order
{
    Node* n = new Node();
	n->order.setChicken(o.getChicken());
	n->order.setAdd(o.getAdd());
	n->order.setName(o.getName());
	n->order.setPnum(o.getPnum());
	n->order.vip = o.vip;
	n->order.mem = o.mem;
	n->order.unpaid = o.unpaid;	//copy
    n->next = NULL;

    if(list->size == 0)
    {
        list->front = n;
        list->back = n;
        list->size++;
        vip++;
        return;
    }

    if(vip == 0)
    {
        n->next = list->front;
        list->front = n;
        list->size++;
        vip++;
        return;
    }

    Node* p;
    p=list->front;
    for(int i=0; i<vip-1; i++)
    {
        p = p->next;
    }
    n->next = p->next;
    p->next = n;

    if(vip == list->size)
    {
        list->back = n;
    }
    list->size++;
    vip++;
}

void OrderHandler::completeOrder()	//finished order (the first order)
{
    if(list->size == 0)
    {
        cout << "There is no order now." << endl;
        return;
    }
    else
    {
        Node* p = list->front;
        cout << "Completed following order:" << endl;
        p->order.print();

        if(p->order.vip)
        {
            vip--;
        }
        list->size --;

		list->front = p->next;
        delete p;
        return;
    }
}

int OrderHandler::getSell()	//get current income
{
    return sell;
}

void OrderHandler::load(string filename)	//load order list from a file
{
    ifstream fin;
	
	fin.open(filename.c_str());
	if (fin.fail())
	{
		cout << "Failed to open file. Check the directory." << endl;
		fin.close();
		return;
	}

    if(list->size != 0)
    {
        char c;
        cout << "There already exist orders. Do you want to delete them? (y/n)" << "> " << endl;
        cin >> c;
        if(c == 'n')
        {
            cout << "Canceled loading." << endl;
            return;
        }
        else
        {
            initializeList();
        }
    }

    string str;
    int num;
    fin >> num;
	getline(fin, str);	//clear \n

    string token[9];
    int index=0;

	int newsell = 0;

    for(int i=0; i<num; i++)
    {
		index = 0;
        getline(fin, str);

        int tmp;

        while(1)
        {
            tmp = str.find("|");
            if(tmp == string::npos) break;  //cannot find
            token[index++] = str.substr(0, tmp);
            str = str.substr(tmp+1);
        }

        token[index] = str;

        Chicken c;
        c.cname = token[0];
        c.cnum = atoi(token[1].c_str());
        c.cprice = atoi(token[2].c_str());

        Order o(c, token[3], token[4], token[5]);
        o.mem = bool(atoi(token[6].c_str()));
        o.vip = bool(atoi(token[7].c_str()));
        o.unpaid = atoi(token[8].c_str());

		if (o.unpaid == false)
		{
			newsell += c.cprice;
		}

        add(o);
    }

	sell = newsell;

    fin.close();
    cout << "--- Loaded " << filename << " ---" << endl;
}

void OrderHandler::save(string filename)	//save the list into the file
{
    if(list->front == NULL)
    {
        cout << "There is nothing to save!" << endl;
        return;
    }

    ofstream fout;

	fout.open((filename+".order").c_str());
	if (fout.fail())
	{
		cout << "Failed to open file. Check the directory." << endl;
		fout.close();
		return;
	}

    Node* p;
    p = list->front;

    fout << list->size << endl;

    for(p = list->front; p!=NULL; p=p->next)
    {
        Chicken c = p->order.getChicken();
        fout << c.cname << "|" << c.cnum << "|" << c.cprice << "|" << p->order.getName() << "|" << p->order.getAdd() << "|" << p->order.getPnum() << "|" << p->order.mem << "|" << p->order.vip << "|" << p->order.unpaid << endl;
    }

    fout.close();
    cout << "--- Saved " << filename+".order" << " ---" << endl;
}

void OrderHandler::initializeList()    //initialize the list (do not delete the list, only delete the elements)
{
    Node* p = list->front;

    for(p = list->front; p!=NULL; )
    {
        list->front = p->next;
        delete p;
        p=list->front;
    }

    list->front = NULL;
    list->back = NULL;
    list->size = 0;
    vip = 0;
}

void OrderHandler::print()	//print all orders
{
	Node* p;
	if (list->size == 0)
	{
		cout << "Nothing to print!" << endl;
		return;
	}
	for (p = list->front; p != NULL; p = p->next)
	{
		p->order.print();
	}
}