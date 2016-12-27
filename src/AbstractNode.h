//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX1_ADV_PROGRAMMING_ABSTRACTNODE_H
#define EX1_ADV_PROGRAMMING_ABSTRACTNODE_H


#include <vector>
#include <iostream>
using namespace std;

/**
 * Class AbstractNode.
 * An abstract class which represents the idea of a node, which is a part of
 * a data structure.
 */
class AbstractNode {
private:
    int distance;
    AbstractNode* prevNode;
    int currNeighboursNum;

protected:
    virtual ostream& print(ostream& os) const= 0;
    void increaseNeighboursNum();
    AbstractNode();
    virtual ~AbstractNode();
    bool isObst;
public:
    virtual std::vector<AbstractNode*> getNeighbours()= 0;
    virtual bool operator==(const AbstractNode& other)= 0;
    virtual bool operator!=(const AbstractNode& other)= 0;
    friend ostream& operator << (ostream& os, const AbstractNode& node);
    int getDistance();
    void setDistance(int dist);
    AbstractNode* getPrev();
    void setPrev(AbstractNode* other);
    int getNeighboursNum();
    bool isIsObst() const;
    void setIsObst(bool isObst);
};


#endif //EX1_ADV_PROGRAMMING_ABSTRACTNODE_H
