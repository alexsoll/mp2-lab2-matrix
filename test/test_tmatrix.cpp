#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);

	EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);

	EXPECT_NE(&m1, &m);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);

	EXPECT_EQ(4, m[0].GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-1][-1] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(4);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(4);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	m1 = m;
	EXPECT_EQ(m[0].GetSize(), m1[0].GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(4);
	EXPECT_EQ(true, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(4);
	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	EXPECT_EQ(false, m == m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(4);
	TMatrix<int> res(4);
	TMatrix<int> exp(4);
	for (int i = 0; i < m[0].GetSize(); i++)
		for (int j = i; j < m[0].GetSize(); j++) {
			m[i][j] = 3;
			m1[i][j] = 1;
			exp[i][j] = 4;
		}
	res = m + m1;
	EXPECT_EQ(true, exp == res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(4);
	TMatrix<int> res(4);
	TMatrix<int> exp(4);
	for (int i = 0; i < m[0].GetSize(); i++) {
		for (int j = i; j < m[0].GetSize(); j++) {
			m[i][j] = 3;
			m1[i][j] = 1;
			exp[i][j] = 2;
		}
	}
	res = m - m1;
	EXPECT_EQ(true, exp == res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(4);
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m - m1);
}

