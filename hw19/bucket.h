#ifndef __bucket__
#define __bucket__
#include <vector>
class bucket
{
  public:
    int max;
    int current;
    bucket(int sz=0, int am=0)
    {
        max = sz;
        current = am;
    }
    int fill(bucket &poured)
    {
        int i;
        while (current < max && poured.current)
        {
            current++;
            poured.current--;
            ++i;
        }
        return i;
    }
};
class node
{
  public:
    bucket four, seven, ten;
    int pre, post;
    int numsteps;
    node(int fo=4, int se=7, int te=0)
    {
        four=*(new bucket(4,fo));
        seven=*(new bucket(7, se));
        ten=*(new bucket(10,te));
        numsteps = 0;
        pre = 0;
        post = 0;
    }
    bool operator==(const node& that){
        if(this->four.current==that.four.current 
        && this->seven.current==that.seven.current
        && this->ten.current==that.ten.current){
            return true;
        }else{
            return false;
        }
    }
};
#endif
