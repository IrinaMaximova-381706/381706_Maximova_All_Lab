#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list_with_not_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> L());
}

TEST(ArrList, can_create_list_with_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> L(3));
}

TEST(ArrList, can_create_copy_empty_list)
{
  TArrList <int> L(1);
  L.PutStart(1);
  TArrList <int> L2(L);
  ASSERT_EQ(L.GetStart(), L2.GetStart());
}

TEST(ArrList, can_create_copy_not_empty_list)
{
  TArrList <int> L(3);

  ASSERT_NO_THROW(TArrList <int> L2(L));
}

TEST(ArrList, throws_when_create_list_with_size_eq_zero)
{
  ASSERT_ANY_THROW(TArrList <int> L(0));
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> L(-1));
}

TEST(ArrList, can_get_and_put_start)
{
  TArrList <int> L(2);
  L.PutStart(1);
  L.PutStart(2);
  ASSERT_EQ(2, L.GetStart());
  ASSERT_EQ(1, L.GetStart());
}

TEST(ArrList, can_put_and_get_end)
{
  TArrList <int> L(2);
  L.PutEnd(1);
  L.PutEnd(2);
  ASSERT_EQ(2, L.GetEnd());
  ASSERT_EQ(1, L.GetEnd());
}

TEST(ArrList, can_use_full_check_false)
{
  TArrList <int> L(1);
  ASSERT_FALSE(L.IsFull());
}

TEST(ArrList, can_use_full_check_true)
{
  TArrList <int> L(1);
  L.PutStart(5);
  ASSERT_TRUE(L.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
  TArrList <int> L(1);
  L.PutStart(5);
  ASSERT_FALSE(L.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
  TArrList <int> L(1);
  ASSERT_TRUE(L.IsEmpty());
}

TEST(ArrList, throws_when_in_full_list_put_start_elem)
{
  TArrList <int> L(1);
  L.PutStart(1);
  ASSERT_ANY_THROW(L.PutStart(2));
}

TEST(ArrList, throws_when_in_full_list_put_finish_elem)
{
  TArrList <int> L(1);
  L.PutStart(1);
  ASSERT_ANY_THROW(L.PutEnd(2));
}

TEST(ArrList, throws_when_in_empty_list_get_start_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.GetStart());
}

TEST(ArrList, throws_when_in_empty_list_get_end_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.GetEnd());
}

TEST(ArrList, true_posledovatelnost_vivoda)
{
  TArrList <int> L(5);
  L.PutStart(1); // 1
  L.PutEnd(2);   // 1 2
  L.PutStart(3); // 3 1 2
  L.PutEnd(4);   // 3 1 2 4
  L.PutStart(5); // 5 3 1 2 4 
  ASSERT_EQ(4, L.GetEnd());     // 5 3 1 2  
  ASSERT_EQ(5, L.GetStart());   // 3 1 2
  ASSERT_EQ(2, L.GetEnd());     // 3 1 
  ASSERT_EQ(3, L.GetStart());   // 1
  ASSERT_EQ(1, L.GetEnd());     // empty
}

TEST(ArrList, throws_when_in_empty_list_get_elem)
{
  TArrList <int> L(10);
  ASSERT_ANY_THROW(L.Get(3));
}

TEST(ArrList, throws_when_in_full_list_put_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(1);
  L.PutEnd(1);

  ASSERT_ANY_THROW(L.Put(1, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_put_elem)
{
  TArrList <int> L(4);
  L.PutEnd(1);
  L.PutEnd(1);
  L.PutEnd(1);

  ASSERT_ANY_THROW(L.Put(10, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_get_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(1);
  L.PutEnd(1);

  ASSERT_ANY_THROW(L.Get(10));
}

TEST(ArrList, can_get_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(2);
  L.PutEnd(3);

  ASSERT_EQ(L.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
  TArrList <int> L(4);
  L.PutEnd(1);
  L.PutEnd(2);
  L.PutEnd(3);
  L.Put(2, 10);

  ASSERT_EQ(L.Get(1), 2);
  ASSERT_EQ(L.Get(1), 10);
}