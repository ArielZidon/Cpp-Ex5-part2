#include "OrgChart.hpp"

///what is auto and if name==NULL and if root==NULL && Name == NULL and root==NULL call add_sub!!!!!!!!!!!!!!!!!!!! 
using namespace std;
namespace ariel{

OrgChart::OrgChart()
{
    root.name = "";
    
}

OrgChart &OrgChart::add_root(string name)
{
    if(name.empty())
    {
        throw runtime_error("you cannot give the root a NULL for name..");
    }
    root.name = move(name);
    return *this;
}

bool OrgChart::add_sub_f(node &someNode,string &dad,string &son)
{
    if(someNode.name == dad)
    {
        node temp;
        temp.name = son;
        someNode.sons.push_back(temp);
        return true;
    }

    for(size_t i=0;i<someNode.sons.size();i++)
    {
        if(add_sub_f(someNode.sons[i],dad,son))
        {
            return true;
        }
    }
    return false;
}

OrgChart &OrgChart::add_sub(string dad,string son)
{
    if(son.empty())
    {
        throw runtime_error("there is no dad with this name");
    }

    if(!add_sub_f(root,dad,son))
    {
        throw runtime_error("there is no dad with this name");
    }
    return *this;
}

void OrgChart::iter_level_order()
{
    vector<pnode> v_ordere;
    v_ordere.push_back(&root);
    // pnode t = NULL;

    for(size_t i=0;i<v_ordere.size();i++)
    {
        pnode t = v_ordere[i];
        level_order.push_back(t->name);

        for(size_t j=0;j<t->sons.size();j++)
        {
            v_ordere.push_back(&(t->sons[j]));
        }
    }
}

string* OrgChart::begin_level_order()
{
    if(root.name.empty())
    {
        throw runtime_error("the try is empty");
    }
    level_order.clear();
    iter_level_order();
    return &level_order[0];
}

string* OrgChart::end_level_order()
{
    if(root.name.empty())
    {
        throw runtime_error("the tree is empty!!!");
    }
    return &level_order[level_order.size()];
}

void OrgChart::fill_rev_order()
{
    vector<pnode> v_ordere;
    v_ordere.push_back(&root);
    // pnode t = NULL;

    for(size_t i=0;i<v_ordere.size();i++)
    {
        pnode t = v_ordere[i];

        for(int j=(int)t->sons.size()-1;j>=0;j--) //!!!!!!
        {
            v_ordere.push_back(&(t->sons[(size_t)j]));
        }
    }

    for(int i=(int)v_ordere.size()-1;i>=0;i--)
    {
        string n = v_ordere[(size_t)i]->name;
        rev_order.push_back(n);
    }
}

string* OrgChart::begin_reverse_order()
{   
    if(root.name.empty())
    {
        throw runtime_error("the try is empty");
    }
    rev_order.clear();
    fill_rev_order();
    return &rev_order[0];
}

string* OrgChart::reverse_order()
{
    if(root.name.empty())
    {
        throw runtime_error("the tree is empty!!!");
    }
    return &rev_order[rev_order.size()];
}

void  OrgChart::fill_pre_order(node &ROOT)
{
    pre_order.push_back(ROOT.name);

    for(size_t i= 0;i<ROOT.sons.size();i++)
    {
        fill_pre_order(ROOT.sons[i]);
    }
}

string* OrgChart::begin_preorder()
{
    if(root.name.empty())
    {
        throw runtime_error("the try is empty");
    }
    this->pre_order.clear();
    fill_pre_order(root);
    return &pre_order[0];
}

string* OrgChart::end_preorder()
{
    if(root.name.empty())
    {
        throw runtime_error("the tree is empty!!!");
    }
    return &pre_order[pre_order.size()];
}

ostream &operator<<(ostream &os,OrgChart &organization)
{
    for (auto *it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        os << it<<" ";
    } 
    return os;
}
}