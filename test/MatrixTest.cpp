////
//// Saar Shtalryd 307838854 & Itay Oktan 203036512
////
//#include <gtest/gtest.h>
//#include "../src/Defines.h"
//#include "../src/Point.h"
//#include "../src/MatrixNode.h"
//#include "../src/Matrix.h"
//#include <stack>
//#include "../src/Bfs.h"
//
//
//
//
//
///**
// *  MatrixTest - test of the Matrix class.
// */
//class MatrixTest: public:: testing:: Test{
//protected:
//
//    Matrix* matrix;
//    Bfs* bfs;
//
//    virtual void SetUp(){
//        matrix = new Matrix(MATRIX_SIZE_X, MATRIX_SIZE_Y);
//        bfs = new Bfs();
//}
//    virtual void TearDown(){
//        delete matrix;
//        delete bfs;
//}
//
//public:
//    MatrixTest(){}
//};
//
//
//
///**
// *  MatrixInputValidation - Testing input validity of Matrix class.
// */
//TEST_F(MatrixTest, MatrixInputValidation){
//
//    try{
//        Matrix(-1,5);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "invalid size");
//    }
//    try{
//        Matrix(0,0);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "invalid size");
//    }
//    try{
//        Matrix(0,-1);
//    } catch (std::invalid_argument& err){
//        ASSERT_STREQ(err.what(), "invalid size");
//    }
//}
//
//
//
//
///**
// * MatrixTestFunctions - test the function of Matrix class.
// */
//TEST_F(MatrixTest, MatrixTestFunctions){
//
//    // Testing getNode of the Matrix.
//    for(int i=0; i<MATRIX_SIZE_Y;i++){
//        for(int j=0; j<MATRIX_SIZE_X;j++){
//            MatrixNode maNode(Point(j,i));
//            Point point(j,i);
//            EXPECT_EQ(true, maNode == *(matrix->getNode(&(point))));
//        }
//    }
//    Point point(-1,0);
//    //Testing non-valid inputs of getNode.
//    EXPECT_EQ(true, NULL == (matrix->getNode(&point)));
//    point = Point(MATRIX_SIZE_X, MATRIX_SIZE_Y);
//    EXPECT_EQ(true, NULL == (matrix->getNode(&point)));
//}
//
//
//
///**
// *  BfsTest - testing the bfs algorithm, which the Matrix uses.
// */
//TEST_F(MatrixTest, BfsTest) {
//    // test empty trail - nodes that are not connected.
//    Point point;
//    MatrixNode maNode(Point(0,0));
//    MatrixNode maNode2(Point(1,0));
//    stack<AbstractNode*> emptyStack = bfs->calcTrail(&maNode, &maNode2);
//    EXPECT_EQ(0, emptyStack.size());
//    //test valid trail from 0,0 to 2,2
//    stack<AbstractNode*> trailStack;
//    point = Point(0,0);
//    MatrixNode* startNodePtr = matrix->getNode(&point);
//    point = Point(2,2);
//    MatrixNode* endNodePtr = matrix->getNode(&point);
//    trailStack = bfs->calcTrail(startNodePtr, endNodePtr);
//    ASSERT_EQ(5, trailStack.size());
//    ASSERT_EQ(true, maNode == *((MatrixNode*)(trailStack.top())));
//    trailStack.pop();
//    maNode = MatrixNode(Point(0,1));
//    ASSERT_EQ(true, maNode == *((MatrixNode*)(trailStack.top())));
//    trailStack.pop();
//    maNode = MatrixNode(Point(0,2));
//    ASSERT_EQ(true, maNode == *((MatrixNode*)(trailStack.top())));
//    trailStack.pop();
//    maNode = MatrixNode(Point(1,2));
//    ASSERT_EQ(true, maNode == *((MatrixNode*)(trailStack.top())));
//    trailStack.pop();
//    maNode = MatrixNode(Point(2,2));
//    ASSERT_EQ(true, maNode == *((MatrixNode*)(trailStack.top())));
//    //Testing a trail to itself - supposed to be empty.
//    trailStack = bfs->calcTrail(startNodePtr, startNodePtr);
//    ASSERT_EQ(0, trailStack.size());
//
//     /* Testing trail out of boundaries isn't needed because the algorithm is
//     * receiving MatrixNodes of the matrix, which are inside the matrix.
//     * Both cases have been checked - nodes who are connected to each other,
//     * and nodes who are not.
//     */
//
//}
