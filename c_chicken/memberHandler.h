#ifndef __MEMBERHANDLER__H__
#define __MEMBERHANDLER__H__
#include "member.h"
#include "handler.h"
#include <string>

using namespace std;

struct MemberNode{
	Member member;
	struct MemberNode* next;
};

class MemberHandler	: public Handler
{
    public:
        MemberNode* mList;
        int num;

        MemberHandler();    
        ~MemberHandler();
        void addMember(Member); 
        void deleteMember(string name); 
        void deleteAll();   
		MemberNode* searchName(string name);
        MemberNode* searchPnum(string pnum);    
        void searchVip();   
        void print();
        void save(string filename); 
        void load(string filename); 

        void sortName();
        void sortPoint();
        void sortVip();

};

#endif // MEMBERHANDLER_H_INCLUDED
