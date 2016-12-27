//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//
#include <gtest/gtest.h>
#include "../src/Defines.h"
#include "../src/Point.h"
#include "../src/MatrixNode.h"

/**
 * test class for point and node classes.
 */
class NodeTest: public:: testing:: Test{
protected:
    Point* p1;
    Point* p2;
    Point* p3;
    MatrixNode* maNode1;
    MatrixNode* maNode2;
    MatrixNode* maNode3;
    AbstractNode* abNode1;
    AbstractNode* abNode2;

    virtual void SetUp(){
        p1 = new Point(P1X, P1Y);
        p2 = new Point(P1X, P1Y);
        p3 = new Point(P2X, P2Y);
        maNode1=new MatrixNode(*p1);
        maNode2 = new MatrixNode(*p2);
        maNode3 = new MatrixNode(*p3);
        abNode1 = maNode1;
        abNode2 = maNode2;
}
    virtual void TearDown(){
        delete p1;
        delete p2;
        delete p3;
        delete maNode1;
        delete maNode2;
        delete maNode3;
}

public:
NodeTest(){}
};


/**
 * PointTest - test the Point class getters and == overloading.
 */
TEST_F(NodeTest, PointTest){

    // Testing getter and == overloading.
    EXPECT_EQ(p1->getX(), p2->getX());
    EXPECT_NE(p1->getX(), p3->getX());
    EXPECT_EQ(true, *p1 == *p2);
    EXPECT_EQ(false, *p1 == *p3);

}

/**
 * NodeTest - test the MatrixNode and AbstractNode
 * getters/setters and == overloading.
 */
TEST_F(NodeTest, NodeTest) {

    // Testing == overloading.
    EXPECT_EQ(true, *maNode1 == *maNode2);
    EXPECT_EQ(false, *maNode2 == *maNode3);
    // Testing neighbours count.
    EXPECT_EQ(0, maNode1->getNeighboursNum());
    maNode1->addNeighbour(maNode2);
    EXPECT_EQ(1, maNode1->getNeighboursNum());
    // Testing get / set of previous node.
    maNode1->setPrev(maNode3);
    EXPECT_EQ(true, *maNode3 == *(maNode1->getPrev()));
    // Testing == overloading of AbstractNode
    EXPECT_EQ(true, *abNode1 == *abNode2);
}

/**
 * printTest - test the print overloading << of
 * Point MatrixNode and AbstractNode classes.
 */
TEST_F(NodeTest, printTest){
    ostringstream output;
    output << *p1;
    ASSERT_EQ(output.str(), "(1,1)");
    ostringstream output2;
    output2 << *maNode1;
    ASSERT_EQ(output2.str(), "(1,1)");
    ostringstream output3;
    output3 << *abNode1;
    ASSERT_EQ(output3.str(), "(1,1)");

}
