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
  ASSERT_ANY_THROW(GetPrt('!'));
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
  char s[] = "9+8";
  TString A(s);
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
  char s[] = "9+8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  EXPECT_EQ(17, Rez(B));
}

TEST(Polish, throw_when_math_expression_have_is_uncurrent_symbol)
{
  char s[] = "9!8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, throw_when_math_expression_have_is_uncurrent_kol_skobok)
{
  char s[] = "(9*8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, throw_when_math_expression_is_fuflo_in_begin)
{
  char s[] = "*9*8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, no_throw_when_queue_is_chiki_bamboni)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  B.Put('+');
  ASSERT_NO_THROW(Rez(B));
  ASSERT_EQ(Rez(B), 17);
}

TEST(Polish, throw_when_queue_is_fuflo_in_begin)
{
  TQueue<char> B(7);
  B.Put('+');
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, throw_when_queue_is_fuflo_in_begin_2)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('*');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, throw_when_queue_is_fuflo_1)
{
  TQueue<char> B(10);
  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('[');
  B.Put('9');
  B.Put(']');
  
  B.Put('+');

  B.Put('[');
  B.Put('4');
  B.Put(']');
  
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, throw_when_queue_is_fuflo)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('&');

  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, can_add_two_digit_number) 
{
  char s[] = "43+57";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(100, Rez(B));
}

TEST(Polish, can_subtract) 
{
  char s[] = "9-8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(1, Rez(B));
}

TEST(Polish, can_multiplication)
{
  char s[] = "9*8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(72, Rez(B));
}

TEST(Polish, can_multiplication_3_param) 
{
  char s[] = "9*8*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(144, Rez(B));
}

TEST(Polish, can_multiplication_and_add_whith_hooks) 
{
  char s[] = "(9+8)*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  EXPECT_EQ(34, Rez(B));
}

TEST(Polish, can_multiplication_and_add_whithout_hooks) 
{
  char s[] = "9+8*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  Rez(B);
  EXPECT_EQ(25, Rez(B));
}

TEST(Polish, can_split)
{
  char s[] = "8/2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Polish, can_multi_1) 
{
  char s[] = "(43+57)*43";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4300, Rez(B));
}

TEST(Polish, can_multi_2)
{
  char s[] = "(43+57)/20";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(5, Rez(B));
}

TEST(Polish, can_multi_3) 
{
  char s[] = "(43+57)/(20+5)";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Polish, can_multi_with_negative_first_number) 
{
  char s[] = "-5+(43+57)/20";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(0, Rez(B));
}
