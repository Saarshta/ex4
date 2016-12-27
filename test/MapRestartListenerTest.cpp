//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//
#include <gtest/gtest.h>
#include "../src/Map.h"
#include "../src/MapRestartListener.h"

/**
 * TripTest - test for the Trip class.
 */
class MapRestartListenerTest: public:: testing:: Test{
protected:
    Map* map;
    std::vector<Point> obstacles;
    Point p1;
    Point p2;
    AbstractNode* node1;
    AbstractNode* node2;
    MapRestartListener* listener;
    virtual void SetUp(){
        map = new Map(5, 5, obstacles);
        p1 = Point(2,2);
        p2 = Point(0,0);
        listener = new MapRestartListener(map);
        node1 = map->getNode(&p1);
        node2 = map->getNode(&p2);
    }
    virtual void TearDown(){
       delete map;
        delete listener;
    }

public:
    MapRestartListenerTest(){}


};

TEST_F(MapRestartListenerTest, RestartTest) {
    node1->setDistance(1);
    node2->setDistance(2);
    ASSERT_EQ(1, node1->getDistance());
    ASSERT_EQ(2, node2->getDistance());
    listener->restartMap();
    EXPECT_EQ(-1, node1->getDistance());
    EXPECT_EQ(-1, node2->getDistance());
}