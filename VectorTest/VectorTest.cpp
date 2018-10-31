#include "Vector.h"
#include <gtest.h>

TEST(TVector, ploxoi_size)
{
	const int size = 5;
	TVector <int> vector(size);

	EXPECT_EQ(size, vector.GetSize());
}