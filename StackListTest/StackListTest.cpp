#include "gtest.h"
#include "StackList.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_create_create_with_parametr)
{
  ASSERT_NO_THROW(TStackList<int> A(3));
}

TEST(TStackList, can_create_create_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList<int> A(-1));
}

TEST(TStackList, can_create_copy_create)
{
  TStackList<int> S(1);
  ASSERT_NO_THROW(TStackList<int> A(S));
}

TEST(TStackList, can_get_max_size)
{
  TStackList<int> S(15);
  ASSERT_EQ(S.GetMaxSize(), 15);
}

TEST(TStackList, can_get_size)
{
  TStackList<int> S(5);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetSize(), 2);
}

TEST(TStackList, can_put)
{
  TStackList<int> A;

  ASSERT_NO_THROW(A.PutBegin(43));
}

TEST(TStackList, throws_when_in_full_stack_put_elem)
{
  TStackList<int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(TStackList, can_get)
{
  TStackList<int> A;
  A.Put(42);
  EXPECT_EQ(42, A.Get());
}

TEST(TStackList, throws_when_from_empty_stack_get_elem)
{
  TStackList <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}

TEST(TStackList, can_use_empty_check_true)
{
  TStackList<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(TStackList, can_check_empty_print)
{
  TStackList<int> S(5);
  ASSERT_ANY_THROW(S.Print());
}

TEST(TStackList, can_use_empty_check_false)
{
  TStackList<int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, Poryadok_vivoda)
{
  TStackList<int> S(3);
  S.Put(1), S.Put(2), S.Put(3);
  ASSERT_EQ(S.Get(), 3);
  ASSERT_EQ(S.Get(), 2);
  ASSERT_EQ(S.Get(), 1);
}