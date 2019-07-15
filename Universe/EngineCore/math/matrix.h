
#include <memory.h>
#include <core/ceAssert.h>
#include <core/ceTypes.h>
#include <math/util.h>

template<int row, int column, typename T=f32>
class Matrix
{
	T buffer[row][column];
	using Self = Matrix<row, column, T>;
public:
	Matrix()
	{
		memset(buffer, 0, row * column*sizeof(T));
	}
	//identity
	static Matrix GetIdentity() { 
		Self ret;
		for (u32 i = 0; i < row; ++i) {
			for (u32 j = 0; j < column; ++j) {
				if (i == j) {
					ret.buffer[i][j] = 1;
					continue;
				}
				ret.buffer[i][j] = 0;
			}
		}
		return ret; 
	}

	//determinant
	f32 Determinant() { 
		return 0.0f; 
	}

	//add
	Self operator + (Self& other) {
		Self ret;
		for (u32 i = 0; i < row; ++i) {
			for (u32 j = i; j < column; ++j) {
				ret[i] = buffer[i][j] + other[i][j];
			}
		}
		return ret;
	}

	//sub
	Self operator - (Self& other) {
		Self ret;
		for (u32 i = 0; i < row; ++i) {
			for (u32 j = i; j < column; ++j) {
				ret[i] = buffer[i][j] - other[i][j];
			}
		}
		return ret;
	}
	//div

	//multiplication
	Self operator*(Self other) {

		ecAssert(row == other.column);

		Self ret;

		for (u32 i = 0; i < row; ++i) {
			for (u32 j = i; j < column; ++j) {
				ret[i] = buffer[i][j] + other[i][j];
			}
		}
		return ret;
	}

	//transpose
	void Transpose() 
	{
		for (u32 i = 0; i < row; ++i) {
			for (u32 j = i; j < column; ++j) {
				swap(buffer[i][j],buffer[j][i]);
			}
		}
	}

	//translate
	void SetTranslation(T x, T y, T z){
		buffer[0][column - 1] = x;
		buffer[1][column - 1] = y;
		buffer[2][column - 1] = z;
		buffer[3][column - 1] = 1;
	}

	//transpose
	Self GetTranspose() { Self ret = *this; ret.Transpose(); return ret; }
};

using  Mat22 = Matrix<2, 2>;
using  Mat33 = Matrix<3, 3>;
using  Mat44 = Matrix<4, 4>;