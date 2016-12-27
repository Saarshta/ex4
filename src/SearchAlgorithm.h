//
// Saar Shtalryd 307838854 & Itay Oktan 203036512
//

#ifndef EX3_SEARCHALGORITHM_H
#define EX3_SEARCHALGORITHM_H


#include <stack>
#include "AbstractNode.h"

/**
 * Abstract SearchAlgorithm class.
 * Different SearchAlgorithm types will inherit from this class.
 */
class SearchAlgorithm {
public:
    virtual std::stack<AbstractNode*> calcTrail(AbstractNode* start, AbstractNode* end)=0;
};


#endif //EX3_SEARCHALGORITHM_H
