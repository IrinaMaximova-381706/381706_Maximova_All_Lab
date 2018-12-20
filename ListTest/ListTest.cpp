#include "List.h"
#include <gtest.h>

TEST(Elem, can_get_data)
{
  TElem<int> el(3, 0);
  ASSERT_EQ(el.GetData(), 3);
}

TEST(Elem, can_get_next)
{
  TElem<int>* a = 0;
  TElem<int> el(3, a);
  ASSERT_EQ(el.GetNext(), a);
}

TEST(Elem, can_create_elem_default)
{
  TElem<int> el;
  ASSERT_EQ(el.GetData(), 0);
}

TEST(Elem, can_set_data)
{
  TElem<int> el;
  el.SetData(5);
  ASSERT_EQ(el.GetData(), 5);
}

TEST(Elem, can_set_next)
{
  TElem<int>* a = 0;
  TElem<int> el;
  el.SetNext(a);

  ASSERT_EQ(el.GetNext(), a);
}

TEST(Elem, can_copy_elem)
{
  TElem<int> el(2, 0);
  TElem<int> el2(el);

  ASSERT_EQ(el.GetNext(), el2.GetNext());
  ASSERT_EQ(el.GetData(), el2.GetData());
}


TEST(List, can_check_empty_true)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(List, can_check_empty_false)
{
  TList<int> list;
  list.PutBegin(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(List, can_check_full_true)
{
  TList<int> list;
  ASSERT_TRUE(list.IsFull());
}

TEST(List, can_get_begin)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetBegin(), 3);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 1);
}

TEST(List, can_get_end)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);

  ASSERT_EQ(list.GetEnd(), 3);
}

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(TList<int> list);
}

TEST(List, no_Throw_when_create_copy_of_the_list)
{
  TList<int> otherlist;
  ASSERT_NO_THROW(TList<int> list(otherlist));
}

TEST(List, can_put_begin)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);
  list.PutBegin(1);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(List, can_put_end)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(List, throw_get_begin_and_get_end_when_list_is_empty)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.GetBegin());
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(List, can_copy_list)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  TList<int> list2(list);

  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
}



