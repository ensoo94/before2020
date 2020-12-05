#include <iostream>
#include <string>

#include "member.h"

using namespace std;

Member::Member(string pnum, string add, string name)
{
    setPnum(pnum);
    setAdd(add);
    setName(name);
    setPoint(0);	//initial point: 0
    vip = false;
    setUnpaid(0);
}

Member::Member()
{
    setPoint(0);
    vip = false;
    setUnpaid(0);
}

void Member::setPnum(string pnum)	//set phone number
{
    this->pnum = pnum;
}

void Member::setAdd(string add)	//set address
{
    this->add = add;
}

void Member::setName(string name)	//set name
{
    this->name = name;
}

void Member::setPoint(int point)	//set point
{
    this->point = point;
}

string Member::getPnum()		//get phone number
{
    return pnum;
}

string Member::getAdd()	//get address
{
    return add;
}

string Member::getName()	//get name
{
    return name;
}

int Member::getPoint()	//get point
{
    return point;
}

void Member::print()	//print the information
{
    cout << "-------------------------------------------------" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAdd() << endl;
    cout << "Phone number: " << getPnum() << endl;
    cout << "Point: " << getPoint() << endl;
    if(vip)
    {
        cout << "*VIP*" << endl;
        cout << "Unpaid: " << getUnpaid() << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

bool Member::isVip()	//check whether vip or not
{
    return vip;
}

int Member::getUnpaid()	//get unpaid amount of vip
{
    return unpaid;
}

void Member::setUnpaid(int unpaid)	//set unpaid amount of vip
{
    this->unpaid = unpaid;
}

void Member::setVip(bool tf)
{
    vip = tf;
}

void Member::payUnpaid(int pay, OrderHandler &oHandler)	//vip pay their unpaid amount
{
    if(pay > unpaid)
    {
        cout << "Wrong input." << endl;
    }
    else
    {
        oHandler.sell += pay;
        unpaid -= pay;
        cout << "Remaining unpaid: " << unpaid << " won" << endl;
    }
}

void Member::operator=(Member &member)	//operator overloading
{
	this->setPnum(member.getPnum());
	this->setAdd(member.getAdd());
	this->setName(member.getName());
	this->setPoint(member.getPoint());
	this->setVip(member.isVip());
	this->setUnpaid(member.getUnpaid());
}