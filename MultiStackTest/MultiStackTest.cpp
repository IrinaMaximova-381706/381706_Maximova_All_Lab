#include "gtest.h"
#include "MultiStack.h"

TEST(TNewStack, throws_when_create_newstack_with_negative_size)
{
  int *a = NULL;
  ASSERT_ANY_THROW(TNewStack<int> S(-1, a));
}
 
TEST(TNewStack, can_create_newstack)
{
  int *a = NULL;
  ASSERT_NO_THROW(TNewStack<int> S(2, a));
}

TEST(TNewStack, can_create_copy_newstack)
{
  int *a = NULL;
  TNewStack<int> S(2, a);
  ASSERT_NO_THROW(TNewStack<int> Sn(S));
}

TEST(TNewStack, can_get_free_mem)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(3, S.GetFreeMem());
}

TEST(TNewStack, can_get_top)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Put(3);
  S.Put(2);
  ASSERT_EQ(2, S.GetTop());
}

TEST(TNewStack, can_get_size)
{
  int *a = NULL;
  TNewStack<int> S(5, a);
  ASSERT_EQ(5, S.GetSize());
}

TEST(TNewStack, can_set_multistack)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  S.SetMas(10, b);
  ASSERT_EQ(10, S.GetSize());
}

TEST(TNewStack, throw_set_multistack_negative_size)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  ASSERT_ANY_THROW(S.SetMas(-1, b));
}

TEST(TNewStack, can_put_and_get_elem)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(2, S.Get());
  ASSERT_EQ(3, S.Get());
}

TEST(TMStack, can_create_mstack_with_positive_length)
{
  ASSERT_NO_THROW(TMStack<int> A(5, 25));
}

TEST(TMStack, cant_create_mstack_with_negative_length)
{
  ASSERT_ANY_THROW(TMStack<int> A(5, -1));
}

TEST(TMStack, cant_create_mstack_with_negative_kol)
{
  ASSERT_ANY_THROW(TMStack<int> A(0, 10));
}

TEST(TMStack, can_copy_mstack)
{
  TMStack<int> A(5, 25);
  ASSERT_NO_THROW(TMStack<int> B(A));
}

TEST(TMStack, can_get_size)
{
  TMStack<int> A(5, 25);
  ASSERT_EQ(A.GetSize(), 25);
}

TEST(TMStack, can_set_element)
{
  TMStack<int> A(5, 25);
  ASSERT_NO_THROW(A.Set(1, 2));
}

TEST(TMStack, throws_when_set_element_in_full_mstack)
{
  TMStack<int> A(2, 4);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(1, 3);
  A.Set(1, 4);
  ASSERT_ANY_THROW(A.Set(1,6));
}

TEST(TMStack, throws_when_set_element_in_negative_index)
{
  TMStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.Set(-2, 2));
}

TEST(TMStack, can_get_element)
{
  TMStack<int> A(5, 25);
  A.Set(2, 43);
  ASSERT_EQ(43, A.Get(2));
}

TEST(TMStack, can_repack)
{
  TMStack<int> A(2, 6);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(0, 3);
  A.Set(1, 3);
  ASSERT_NO_THROW(A.Set(0,10));
  ASSERT_EQ(A.Get(0), 10);
}

TEST(TMStack, throws_when_get_element_from_negative_index)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  ASSERT_ANY_THROW(A.Get(-1));
}

TEST(TMStack, throws_when_get_element_from_empty_mstack)
{
  TMStack<int> A(2, 5);
  ASSERT_ANY_THROW(A.Get(1));
}

TEST(TMStack, correct_order_return_value)
{
  TMStack <int> A(2, 5);
  A.Set(1, 1);
  A.Set(1, 2);
  A.Set(1, 3);
  ASSERT_EQ(3, A.Get(1));
  ASSERT_EQ(2, A.Get(1));
  ASSERT_EQ(1, A.Get(1));
}

TEST(TMStack, can_check_is_empty)
{
  TMStack<int> A(5, 25);
  ASSERT_TRUE(A.IsEmpty(1));
}

TEST(TMStack, can_check_is_no_empty)
{
  TMStack<int> A(5, 25);
  A.Set(1, 1);
  ASSERT_FALSE(A.IsEmpty(1));
}

TEST(TMStack, can_check_is_full)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  EXPECT_EQ(1, A.IsFull(1));
}

TEST(TMStack, can_check_is_no_full)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  ASSERT_FALSE(A.IsFull(1));
}

TEST(TMStack, throw_when_check_is_full_or_empty)
{
  TMStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.IsFull(-1));
  ASSERT_ANY_THROW(A.IsEmpty(-1));
}