#include "gtest/gtest.h"
#include "linkedlist.h"

TEST(linkedList, stores_values) {
    SingleLinkedList sll;
    sll.push_front(4);

    auto result = sll.peek_front();
    ASSERT_EQ(result.is_initialized(), true);
    ASSERT_EQ(result.get(), 4);

    sll.push_front(5);
    result = sll.peek_front();
    ASSERT_EQ(result.is_initialized(), true);
    ASSERT_EQ(result.get(), 5);
}

TEST(linkedList, pops_values) {
    SingleLinkedList sll;
    sll.push_front(1);
    sll.push_front(9);

    auto result = sll.pop_front();
    ASSERT_EQ(result.is_initialized(), true);
    ASSERT_EQ(result.get(), 9);

    result = sll.peek_front();
    ASSERT_EQ(result.is_initialized(), true);
    ASSERT_EQ(result.get(), 1);
}