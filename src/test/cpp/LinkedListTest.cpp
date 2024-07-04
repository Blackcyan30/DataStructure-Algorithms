#include "gtest/gtest.h"
#include "LinkedList.h"
using namespace std;

// Test fixture for LinkedList
class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<int> list;

    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
        list.clear();
    }
};

// Test the constructor
TEST_F(LinkedListTest, Constructor) {
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

// Test append
TEST_F(LinkedListTest, Append) {
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.getSize(), 3);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.peekFront(), 1);
}

// Test prepend
TEST_F(LinkedListTest, Prepend) {
    list.prepend(1);
    list.prepend(2);
    list.prepend(3);

    EXPECT_EQ(list.getSize(), 3);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.peekFront(), 3);
}

// Test insertAt
TEST_F(LinkedListTest, InsertAt) {
    list.append(1);
    list.append(3);
    list.insertAt(1, 2);

    EXPECT_EQ(list.getSize(), 3);
    EXPECT_FALSE(list.isEmpty());

    EXPECT_EQ(list.pop(0)->val, 1);
    EXPECT_EQ(list.pop(0)->val, 2);
    EXPECT_EQ(list.pop(0)->val, 3);
}

// Test pop with index
TEST_F(LinkedListTest, PopWithIndex) {
    list.append(1);
    list.append(2);
    list.append(3);

    Node<int>* node = list.pop(1);
    EXPECT_EQ(node->val, 2);
    delete node;

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_FALSE(list.isEmpty());

    EXPECT_EQ(list.pop(0)->val, 1);
    EXPECT_EQ(list.pop(0)->val, 3);
}

// Test pop without index (should pop the last element)
TEST_F(LinkedListTest, PopWithoutIndex) {
    list.append(1);
    list.append(2);
    list.append(3);

    Node<int>* node = list.pop();
    EXPECT_EQ(node->val, 3);
    delete node;

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_FALSE(list.isEmpty());

    EXPECT_EQ(list.pop(0)->val, 1);
    EXPECT_EQ(list.pop(0)->val, 2);
}

// Test clear
TEST_F(LinkedListTest, Clear) {
    list.append(1);
    list.append(2);
    list.append(3);
    list.clear();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

// Test find
TEST_F(LinkedListTest, Find) {
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_TRUE(list.find(2));
    EXPECT_FALSE(list.find(4));
}

// Test copy constructor
TEST_F(LinkedListTest, CopyConstructor) {
    list.append(1);
    list.append(2);
    list.append(3);

    LinkedList<int> copiedList(list);

    EXPECT_EQ(copiedList.getSize(), 3);
    EXPECT_FALSE(copiedList.isEmpty());
    EXPECT_EQ(copiedList.pop(0)->val, 1);
    EXPECT_EQ(copiedList.pop(0)->val, 2);
    EXPECT_EQ(copiedList.pop(0)->val, 3);
}

// Test assignment operator
TEST_F(LinkedListTest, AssignmentOperator) {
    list.append(1);
    list.append(2);
    list.append(3);

    LinkedList<int> assignedList;
    assignedList = list;

    EXPECT_EQ(assignedList.getSize(), 3);
    EXPECT_FALSE(assignedList.isEmpty());
    EXPECT_EQ(assignedList.pop(0)->val, 1);
    EXPECT_EQ(assignedList.pop(0)->val, 2);
    EXPECT_EQ(assignedList.pop(0)->val, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
