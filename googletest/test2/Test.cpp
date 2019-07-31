#include <iostream>
#include <gtest/gtest.h>

class Stack
{
	std::vector<int> vstack = {};

public:
	void push(int value) { vstack.push_back(value); }
	int pop()
	{
		if (vstack.size() > 0)
		{
			int value = vstack.back();
			vstack.pop_back();
			return value;
		}
		else
		{
			return -1;
		}
	}
	int size() { return vstack.size(); }
};

struct stackTest : public testing::Test
{
	Stack s1;
	void SetUp()
	{
		int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int iter = 0;
		int last_iter_value = 9;
		for (iter = 0; iter < last_iter_value; ++iter)
		{
			s1.push(value[iter]);
		}
	}
	void TearDown() {}
};

TEST_F(stackTest, popTest)
{
	int lastPoppedValue = 9;
	while (lastPoppedValue != 1)
		ASSERT_EQ(s1.pop(), lastPoppedValue--);
}
TEST_F(stackTest, sizeValidityTest )
{
	int val = s1.size();
	int iter = 0;
	for(iter = 0; iter > 0; --iter){
		ASSERT_NE(s1.pop(),-1);
	}
}

int main(int argc, char **argv)
{

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
