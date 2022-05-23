#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define sons_num 100
using namespace std;

namespace ariel{

    typedef struct node{
        string name;
        vector <struct node> sons;
    }node, *pnode;

    // template<class T>
    class OrgChart
    {
        node root;
        vector<string> level_order;
        void iter_level_order();

        vector<string> rev_order;
        void fill_rev_order();

        vector<string> pre_order;
        void fill_pre_order(node &ROOT);

        bool add_sub_f(node &someNode,string &dad,string &son);
        
        public:

        OrgChart &add_root(string name);   
        OrgChart &add_sub(string dad,string son);

        string *begin_level_order();
        string *end_level_order();
      
        string *begin_reverse_order();
        string *reverse_order();

        string *begin_preorder();
        string *end_preorder();

        string *begin(){ return begin_level_order();}
        string *end(){return end_level_order();}

        OrgChart();
        // ~OrgChart(){};

        friend ostream &operator<<(ostream &os,OrgChart &organization);

    };
}