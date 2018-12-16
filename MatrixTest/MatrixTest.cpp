#include "Matrix.h"

#include <gtest.h>

TEST(Matrix, can_create_matrix_with_not_specified_size)
{
  ASSERT_NO_THROW(TMatrix <int> M());
}

TEST(Matrix, can_create_matrix_with_specified_size)
{
  ASSERT_NO_THROW(TMatrix <int> M(3));
}

TEST(Matrix, throws_when_create_matrix_with_zero_size)
{
  ASSERT_ANY_THROW(TMatrix <int> M(0));
}

TEST(Matrix, throws_when_create_matrix_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix <int> M(-1));
}

TEST(Matrix, throws_when_create_matrix_with_too_large_size)
{
  ASSERT_ANY_THROW(TMatrix <int> M(10001));
}

TEST(Matrix, can_equality_matrix_true)
{
  TMatrix <int> M1(3), M2(3);
  for (int i = 0; i < M1.GetSize(); i++)
    for (int j = 0; j < M1.GetSize() - i; j++)
    {
      M1[i][j] = i;
      M2[i][j] = i;
    }
  ASSERT_TRUE(M1 == M2);
}

TEST(Matrix, can_equality_matrix_false)
{
  TMatrix <int> M1(3), M2(3);
  for (int i = 0; i < M1.GetSize(); i++)
    for (int j = 0; j < M1.GetSize() - i; j++)
    {
      M1[i][j] = i;
      M2[i][j] = i + 1;
    }
  ASSERT_FALSE(M1 == M2);
}

TEST(Matrix, can_equality_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_FALSE(M1 == M2);
}

TEST(Matrix, can_inequality_matrix_true)
{
  TMatrix <int> M1(3), M2(3);
  for (int i = 0; i < M1.GetSize(); i++)
    for (int j = 0; j < M1.GetSize() - i; j++)
    {
      M1[i][j] = i;
      M2[i][j] = i + 1;
    }
  ASSERT_TRUE(M1 != M2);
}

TEST(Matrix, can_inequality_matrix_false)
{
  TMatrix <int> M1(3), M2(3);
  for (int i = 0; i < M1.GetSize(); i++)
    for (int j = 0; j < M1.GetSize() - i; j++)
    {
      M1[i][j] = i;
      M2[i][j] = i;
    }
  ASSERT_FALSE(M1 != M2);
}

TEST(Matrix, can_inequality_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_TRUE(M1 != M2);
}

TEST(Matrix, can_assign_matrix)
{
  TMatrix <int> M1(3), M2(5);
  M1 = M2;
  ASSERT_TRUE(M1 == M2);
}

TEST(Matrix, can_addition_matrix)
{
  TMatrix <int> M1(2), M2(2), MT(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2 - i; j++) {
      M1[i][j] = i + j;
      M2[i][j] = i + j + 2;
      MT[i][j] = M1[i][j] + M2[i][j];
    }
  ASSERT_TRUE(MT == (M1 + M2));
}

TEST(Matrix, thorws_when_addition_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_ANY_THROW(M1 + M2);
}

TEST(Matrix, can_subtraction_matrix)
{
  TMatrix <int> M1(2), M2(2), MT(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2 - i; j++)
    {
      M1[i][j] = i + j;
      M2[i][j] = i + j + 2;
      MT[i][j] = M1[i][j] - M2[i][j];
    }
  ASSERT_TRUE(MT == (M1 - M2));
}

TEST(Matrix, thorws_when_subtraction_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_ANY_THROW(M1 - M2);
}

TEST(Matrix, can_multiplication_matrix)
{
  TMatrix <int> M1(3), M2(3), MT(3);
  M1[0][0] = 1; M1[0][1] = 2; M1[0][2] = 3;
  M1[1][0] = 4; M1[1][1] = 5;
  M1[2][0] = 6;

  M2[0][0] = 3; M2[0][1] = 5; M2[0][2] = 7;
  M2[1][0] = 9; M2[1][1] = 11;
  M2[2][0] = 13;

  MT[0][0] = 3; MT[0][1] = 23; MT[0][2] = 68;
  MT[1][0] = 36; MT[1][1] = 109;
  MT[2][0] = 78;
  ASSERT_TRUE(MT == (M1 * M2));
}

TEST(Matrix, can_delit_matrix)
{
  TMatrix<int> M1(3), M2(3), MT(3);
  int k = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3 - i; j++)
      M1[i][j] = k++;

  M2[0][0] = 1;
  M2[0][1] = 2;
  M2[0][2] = 3;
  M2[1][0] = 1;
  M2[1][1] = 2;
  M2[2][0] = 1;

  MT[0][0] = 1; MT[0][1] = 0; MT[0][2] = 0;
  MT[1][0] = 4; MT[1][1] = -3;
  MT[2][0] = 6;
  ASSERT_TRUE(MT == (M1 / M2));
}

TEST(Matrix, thorws_when_delit_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_ANY_THROW(M1 / M2);
}

TEST(Matrix, thorws_when_multiplication_matrix_with_diff_size)
{
  TMatrix <int> M1(2), M2(3);
  ASSERT_ANY_THROW(M1 * M2);
}