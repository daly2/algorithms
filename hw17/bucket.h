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
    void fill(bucket &poured)
    {
        if(this->max==poured.max){return;}
        while (this->current < this->max && poured.current>0)
        {
            this->current++;
            poured.current--;
        }
    }
    bucket(const bucket & old){
        max=old.max;
        current=old.current;
    }
    bucket(){
        max=-1;
        current=-1;
    }
};
class Node
{
  public:
    int dist;
    int numsteps;
    std::vector<bucket> buck;
    Node(int fo=4, int se=7, int te=0)
    {
        buck.emplace_back(4,fo);
        buck.emplace_back(7, se);
        buck.emplace_back(10,te);
        numsteps = 0;
    }
    Node(const Node &old){
        this->dist=old.dist;
        this->numsteps=old.numsteps;
        for(int i=0; i<old.buck.size(); ++i){
            bucket temp=old.buck.at(i);
            this->buck.push_back(temp);
        }
    }
    bool operator==(const Node& that){
        return(this->buck.at(0).current==that.buck.at(0).current 
        && this->buck.at(1).current==that.buck.at(1).current
        && this->buck.at(2).current==that.buck.at(2).current);
    }
};
#endif
