#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "member.h"
#include "order.h"
#include "memberHandler.h"
#include "orderHandler.h"

int main(void)
{
    MemberHandler mHandler;
    OrderHandler oHandler;

    string input;

	cout << string(100, '\n');	//clear screen

    while(1)
    {
		cout << "\n\n*** Chicken-4-Jo member/order management system *** "<< endl;
		cout << "Type the menu. (Member, Order, Clear, Exit)" << endl << "> ";
        cin >> input;
        if(input == "Member")	//Member mode
        {
            cout << "\nMember management mode. Type the menu. (Insert, DeleteOne, DeleteAll, Display, Search, Sort, Save, Load, Main)" << endl << "> ";
            cin >> input;

            if(input == "Insert")
            {
                string name, pnum, add;
                cout << "Add a member." << endl << "Type your name." << endl << "> ";
                cin >> name;
                cout << "Type your phone number." << endl <<"> ";
                cin >> pnum;
                cout << "Type your address." << endl << "> ";
                cin >> add;

                Member m(pnum, add, name);
				MemberNode* mp = mHandler.searchName(name);
				if (mp == NULL)
				{
					mHandler.addMember(m);
					cout << "Added below member:" << endl;
					m.print();
				}
				else
				{
					cout << "The customer " << name << " is already a member." << endl;
					cout << "Information:" << endl;
					mp->member.print();
				}
				/*
                bool tf = mHandler.addMember(m);
				if (tf)
				{
					cout << "Added below member:" << endl;
					m.print();
				}
				else
				{
					cout << "The customer " << name << " is already a member." << endl;
					cout << "Information:" << endl;
					MemberNode* mp = mHandler.searchName(name);
				}
				*/
            }
            else if(input == "DeleteOne")
            {
                cout << "Type the name of member want to delete." << endl << "> ";
                cin >> input;

                mHandler.deleteMember(input);
            }
            else if(input == "DeleteAll")
            {
                cout << "Do you want to delete all members? (y/n)" << endl << "> ";
                char c;
                cin >> c;
                if(c == 'y')
                {
                    mHandler.deleteAll();
					cout << "Deleted all members!" << endl;
                }
                else if(c == 'n')
                {
                    cout << "Cancled." << endl;
                }
            }
            else if(input == "Display")
            {
                mHandler.print();
            }
            else if(input == "Search")
            {
                cout << "Type the condition to search. (Vip, Name, Pnum)" << endl << "> ";
                cin >> input;
                if(input == "Vip")
                {
                    mHandler.searchVip();
                }
                else if(input == "Name")
                {
                    cout << "Type the name to search." << endl << "> ";
                    cin >> input;
                    MemberNode* mp = mHandler.searchName(input);
                    if(mp!=NULL)    mp->member.print();
					else
					{
						cout << "The member does not exist." << endl;
					}
                }
                else if(input == "Pnum")
                {
                    cout << "Type the phone number to search." << endl << "> ";
                    cin >> input;
                    MemberNode* mp = mHandler.searchPnum(input);
                    if(mp!=NULL)    mp->member.print();
					else
					{
						cout << "The member does not exist." << endl;
					}
                }
                else
                {
                    cout << "Wrong option. Back to the main menu." << endl;
                }
            }
            else if(input == "Sort")
            {
                cout << "Type the condition to sort. (Vip, Name, Point)" << endl << "> ";
                cin >> input;
                if(input == "Vip")
                {
                    mHandler.sortVip();
                    mHandler.print();
                }
                else if(input == "Name")
                {
                    mHandler.sortName();
                    mHandler.print();
                }
                else if(input == "Point")
                {
                    mHandler.sortPoint();
                    mHandler.print();
                }
                else
                {
                    cout << "Wrong option. Back to the main menu." << endl;
                }
            }
            else if(input == "Save")
            {
                cout << "Type the name of save file." << endl;
                cout << "> ";
                cin >> input;
                mHandler.save(input);
            }
            else if(input == "Load")
            {
                cout << "Type the name of load file. (.member file)" << endl;
                cout << "> ";
                cin >> input;
				if (input.find(".member") == string::npos)
				{
					cout << "Wrong file! Choose .member file." << endl;
				}
				else
				{
					mHandler.load(input);
				}
            }
            else if(input == "Main")
            {
                cout << "Back to the main menu." << endl;
            }
            else
            {
                cout << "Wrong menu. Back to the main menu." << endl;
            }
        }
        else if(input == "Order")	//Order mode
        {
            cout << "\nOrder management mode. Type the menu. (Add, Complete, ShowIncome, Display, Pay, Save, Load, Main)" << endl << "> ";   //외상 지불 처리
            cin >> input;
            if(input == "Add")
            {
                Chicken c;
                string name, add, pnum;
                cout << "******* MENU *******" << endl;
				cout << "Fried 8,500 won" << endl;
				cout << "Seasoned 9,500 won" << endl;
				cout << "Half and Half 10,000 won" << endl;
                cout << "********************" << endl;
                cout << "Type the order information." << endl;
                cout << "Chicken Type (Fried, Seasoned, Half): ";
                cin >> c.cname;
                cout << "Chicken number: ";
                cin >> c.cnum;
                if((c.cname != "Fried") && (c.cname != "Seasoned") && (c.cname != "Half"))
                {
                    cout << "That chicken type does not exist. Back to the main menu." << endl;
                    continue;
                }

                cout << "Customer name: ";
                cin >> name;
                cout << "Address: ";
                cin >> add;
                cout << "Phone number: ";
                cin >> pnum;

                Order o(c, name, add, pnum); 
                o.calCprice();
				cout << "The price is " << o.getCprice() << " won." << endl;

                MemberNode *m = mHandler.searchName(name);
				if(m != NULL)
                {
                    o.mem = true;
                    if(m->member.isVip()==true)
                    {
                        o.vip = true;
                        cout << "Do you want to pay it later? (y/n)" << endl << "> ";
                        char c;
                        cin >> c;
                        if(c=='y')
                        {
                            o.unpaid = true;
                            m->member.setUnpaid(m->member.getUnpaid()+o.getCprice());
                        }
                        else
                        {
                            //ignore if the customer paid already
                        }
                    }
                    m->member.setPoint(m->member.getPoint()+(o.getCprice()/10));  //point up
                    cout << "Current point is " << m->member.getPoint() << " point." << endl;
                    if((m->member.getPoint() > 3000) && (m->member.isVip()==false))	//make vip
                    {
                        m->member.setVip(true);
                        cout << "Congratulations! You were upgraded to VIP!" << endl;
                    }
                }

                oHandler.addOrder(o);
            }
            else if(input == "Complete")
            {
                oHandler.completeOrder();
            }
            else if(input == "ShowIncome")
            {
                cout << "Current income: " << oHandler.getSell() << " won" << endl;
            }
            else if(input == "Display")
            {
				oHandler.print();
            }
            else if(input == "Pay")
            {
                cout << "Type the name of VIP customer." << endl;
                cout << "> ";
                cin >> input;
                MemberNode *m = mHandler.searchName(input);
				if (m == NULL)
				{
					cout << "That customer does not exist." << endl;
					continue;
				}
                if(m->member.isVip() == false)
                {
                    cout << "That customer is not VIP." << endl;
                    continue;
                }
				else
				{
					cout << "Current unpaid amount is " << m->member.getUnpaid() << " won. Type the amount to pay." << endl;
					cout << "> ";
					int pay;
					cin >> pay;
					m->member.payUnpaid(pay, oHandler);
				}
            }
            else if(input == "Save")
            {
                cout << "Type the file name to save." << endl;
                cout << "> ";
                cin >> input;
                oHandler.save(input);
            }
            else if(input == "Load")
            {
                cout << "Type the file name to load. (.order file)" << endl;
                cout << "> ";
                cin >> input;
				if (input.find(".order") == string::npos)
				{
					cout << "Wrong file! Choose .order file." << endl;
				}
				else
				{
					oHandler.load(input);
				}
            }
            else if(input == "Main")
            {
                cout << "Back to the main menu." << endl;
            }
            else
            {
                cout << "Wrong menu. Back to the main menu." << endl;
            }
        }
		else if (input == "Clear")
		{
			//clear;
			cout << string(100, '\n');
		}
        else if(input == "Exit")
        {
			if (mHandler.num > 0)
			{
				cout << "There are some members did not saved. Do you want to save? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "Type the name of save file." << endl;
					cout << "> ";
					cin >> input;
					mHandler.save(input);
				}
			}
			if (oHandler.list->size > 0)
			{
				cout << "There are some orders did not saved. Do you want to save? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "Type the file name to save." << endl;
					cout << "> ";
					cin >> input;
					oHandler.save(input);
				}
			}
            cout << "Exit the program." << endl;
            return 0;
        }
        else
        {
            cout << "Wrong menu. Type again." << endl;
        }
    }

    return 0;
}
