//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX2_MAP_H
#define EX2_MAP_H


#include "Matrix.h"

/**
 * Map object.
 */
class Map {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & id;
        ar & startNode;
        ar & endNode;
        ar & tariff;
        ar & passengers;
        ar & startingTime;
    }
private:
    Matrix* map;
    std::vector<Point> obstacles;

public:
    Map(int sizeX, int sizeY, vector<Point> obstacles);
    bool isPointInMap(Point p);
    AbstractNode* getNode(const AbstractPoint* point);
    ~Map();
    void restartDistances();
};


#endif //EX2_MAP_H
