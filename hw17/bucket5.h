#ifndef __bucket5__
#define __bucket5__
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
    std::vector<bucket> buck;
    Node(int twth=23, int twni=0, int thon=0, int thse=0, int foon = 41)
    {
        buck.emplace_back(23,twth);
        buck.emplace_back(29,twni);
        buck.emplace_back(31,thon);
        buck.emplace_back(37, thse);
        buck.emplace_back(41,foon);
    }
    Node(const Node &old){
        this->dist=old.dist;
        for(int i=0; i<old.buck.size(); ++i){
            bucket temp=old.buck.at(i);
            this->buck.push_back(temp);
        }
    }
    bool operator==(const Node& that){
        return(this->buck.at(0).current==that.buck.at(0).current 
        && this->buck.at(1).current==that.buck.at(1).current
        && this->buck.at(2).current==that.buck.at(2).current
        && this->buck.at(3).current==that.buck.at(3).current
        && this->buck.at(4).current==that.buck.at(4).current);
    }
};
#endif
