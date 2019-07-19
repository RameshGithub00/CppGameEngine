
#include <memory.h>
#include <core/ceAssert.h>
#include <core/ceTypes.h>
#include <math/util.h>

namespace math
{
	template<u32 ROW, u32 COLUMN, typename T>
	class Matrix
	{
		T buffer[ROW][COLUMN];
		using Self = Matrix<ROW, COLUMN, T>;
	public:

		static const u32 m_Row = ROW;
		static const u32 m_Column = COLUMN;

		Matrix()
		{
			memset(buffer, 0, m_Row * m_Column * sizeof(T));
		}
		//identity
		static Matrix GetIdentity() {
			Self ret;
			for (u32 i = 0; i < m_Row; ++i) {
				for (u32 j = 0; j < m_Column; ++j) {
					if (i == j) {
						ret.buffer[i][j] = 1;
						continue;
					}
					ret.buffer[i][j] = 0;
				}
			}
			return ret;
		}

		//add
		Self operator + (Self& other) {
			Self ret;
			for (u32 i = 0; i < m_Row; ++i) {
				for (u32 j = i; j < column; ++j) {
					ret[i] = buffer[i][j] + other[i][j];
				}
			}
			return ret;
		}

		//sub
		Self operator - (Self& other) {
			Self ret;
			for (u32 i = 0; i < m_Row; ++i) {
				for (u32 j = i; j < column; ++j) {
					ret[i] = buffer[i][j] - other[i][j];
				}
			}
			return ret;
		}
		//div

		//multiplication
		Self operator*(Self other) {

			ecAssert(m_Row == other.m_Column);

			Matrix<ROW, other.m_Column, T> ret;

			u32 myRow = ROW;
			u32 otherColumn = other.m_Column;

			u32 myColAndOtherRow = COLUMN;//has to be same

			T result = 0.0f;

			for (u32 r1 = 0; r1 < myRow; ++r1) {
				for (u32 c2 = 0; c2 < otherColumn; c2++) {
					result = 0.0f;
					for (u32 rc = 0; rc < myColAndOtherRow; ++rc) {
						result += buffer[r1][rc] * other.buffer[rc][c2];
					}
					ret.buffer[r1][c2] = result;
				}
			}
			return ret;
		}

		//transpose
		void Transpose()
		{
			for (u32 i = 0; i < m_Row; ++i) {
				for (u32 j = i; j < m_Column; ++j) {
					ecSwap(buffer[i][j], buffer[j][i]);
				}
			}
		}

		//translate
		void SetTranslation(T x, T y, T z) {
			buffer[0][m_Column - 1] = x;
			buffer[1][m_Column - 1] = y;
			buffer[2][m_Column - 1] = z;
			buffer[3][m_Column - 1] = 1;
		}

		//transpose
		Self GetTranspose() { Self ret = *this; ret.Transpose(); return ret; }

		//determinant

		f32 Determinant();

		Self GetInverse()
		{
			return *this;
		}

	};

	//using  Mat22 = Matrix<f32, 2, 2>;
	//using  Mat33 = Matrix<f32, 3, 3>;
	//using  Mat44 = Matrix<f32, 4, 4>;

	using  Mat22 = Matrix< 2, 2, f32>;
	using  Mat33 = Matrix< 3, 3, f32>;
	using  Mat44 = Matrix< 4, 4, f32>;


	template<u32 row = 2, u32 column = 2, typename T>
	f32 Matrix<row, column, T>::Determinant()
	{
		return 0.0f;
	}
}

//template<u32 row = 3, u32 column = 3, typename T>
//f32 Matrix<3, 3, T>::Determinant()
//{
//	return 0.0f;
//}
//
//template<u32 row = 4, u32 column = 4, typename T>
//f32 Matrix<row, column, T>::Determinant()
//{
//	return 0.0f;
//}
