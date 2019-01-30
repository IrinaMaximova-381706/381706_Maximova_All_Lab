#include "gtest.h"
#include "Polish.h"

TEST(Polish, can_get_priority)
{

  ASSERT_EQ(1, GetPrt(')'));
  ASSERT_EQ(1, GetPrt('('));
  ASSERT_EQ(2, GetPrt('+'));
  ASSERT_EQ(2, GetPrt('-'));
  ASSERT_EQ(3, GetPrt('*'));
  ASSERT_EQ(3, GetPrt('/'));
  ASSERT_EQ(-1, GetPrt('!'));
}

TEST(Polish, can_check_is_op)
{
  ASSERT_EQ(1, IsOp(')'));
  ASSERT_EQ(1, IsOp('('));
  ASSERT_EQ(1, IsOp('+'));
  ASSERT_EQ(1, IsOp('-'));
  ASSERT_EQ(1, IsOp('*'));
  ASSERT_EQ(1, IsOp('/'));
  ASSERT_EQ(false, IsOp('4'));
  ASSERT_EQ(false, IsOp('!'));
}

TEST(Polish, can_convert_to_pol)
{
  string A = "9+8";
  TQueue<char> B;
  B = ConvertToPol(A);
  ASSERT_EQ(B.Get(), '[');
  ASSERT_EQ(B.Get(), '9');
  ASSERT_EQ(B.Get(), ']');
  ASSERT_EQ(B.Get(), '[');
  ASSERT_EQ(B.Get(), '8');
  ASSERT_EQ(B.Get(), ']');
  ASSERT_EQ(B.Get(), '+');
}

TEST(Polish, can_add)
{
  string A = "9+8";
  TQueue<char> B;
  B = ConvertToPol(A);
  EXPECT_EQ(17, Rez(B));
}

TEST(Poland, can_add_two_digit_number) 
{
  string A = "43+57";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(100, Rez(B));
}

TEST(Poland, can_subtract) 
{
  string A = "9-8";
  TQueue<char> B(ConvertToPol(A));

  EXPECT_EQ(1, Rez(B));
}

TEST(Poland, can_multiplication)
{
  string A = "9*8";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(72, Rez(B));
}

TEST(Poland, can_multiplication_3_param) 
{
  string A = "9*8*2";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(144, Rez(B));
}

TEST(Poland, can_multiplication_and_add_whith_hooks) 
{
  string A = "(9+8)*2";
  TQueue<char> B(ConvertToPol(A));

  EXPECT_EQ(34, Rez(B));
}

TEST(Poland, can_multiplication_and_add_whithout_hooks) 
{
  string A = "9+8*2";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(25, Rez(B));
}

TEST(Poland, can_split)
{
  string A = "8/2";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Poland, can_multi_1) 
{
  string A = "(43+57)*43";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4300, Rez(B));
}

TEST(Poland, can_multi_2)
{
  string A = "(43+57)/20";
  TQueue<char> B(ConvertToPol(A));

  EXPECT_EQ(5, Rez(B));
}

TEST(Poland, can_multi_3) 
{
  string A = "(43+57)/(20+5)";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Poland, can_multi_with_negative_first_number) 
{
  string A = "-5+(43+57)/20";
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(0, Rez(B));
}
