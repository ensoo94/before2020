#include <iostream>
#include <string>
#include "order.h"

using namespace std;

Order::Order(Chicken chicken, string name, string add, string pnum)
{
    setChicken(chicken);
    setName(name);
    setAdd(add);
    setPnum(pnum);
    mem = false;
    vip = false;
    unpaid = false;
}

Order::Order()
{
    mem=false;
    vip=false;
    unpaid=false;

}

void Order::setPnum(string pnum)	//set phone number
{
    this->pnum = pnum;
}

void Order::setAdd(string add)	//set address
{
    this->add = add;
}

void Order::setName(string name)	//set name
{
    this->name = name;
}

string Order::getPnum()	//get phone number
{
    return pnum;
}

string Order::getAdd()	//get address
{
    return add;
}

string Order::getName()	//get name
{
    return name;
}

Chicken Order::getChicken()	//get ordered chicken information
{
    return chicken;
}

void Order::setChicken(Chicken chicken)	//set chicken
{
    this->chicken.cname = chicken.cname;
    this->chicken.cprice = chicken.cprice;
    this->chicken.cnum = chicken.cnum;
}

void Order::calCprice()	//calculate chicken price
{
    if(chicken.cname == "Fried")
    {
        chicken.cprice = 8500 * chicken.cnum;
    }
    else if(chicken.cname == "Seasoned")
    {
        chicken.cprice = 9500 * chicken.cnum;
    }
    else if(chicken.cname == "Half")
    {
        chicken.cprice = 10000 * chicken.cnum;
    }
}

int Order::getCprice()	//get chicken price
{
    return chicken.cprice;
}

void Order::print()	//print information
{
    cout << "-------------------------------------------------" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAdd() << endl;
    cout << "Phone number: " << getPnum() << endl;
    cout << "Chicken: " << chicken.cname << " " << chicken.cnum << endl;
	if (vip == true)
	{
		cout << "*VIP*" << endl;
		cout << "Unpaid: ";
		if (unpaid == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
    cout << "-------------------------------------------------" << endl;
}
