#include "ClassB.h"
#include <gtest/gtest.h>

TEST(subB1, normal){
	ClassB target = {};
	ASSERT_EQ(8, target.subB1(12,4));
}

TEST(subB2, normal){
	ClassB target = {};
	ASSERT_EQ(6, target.subB2(12,6));
}
