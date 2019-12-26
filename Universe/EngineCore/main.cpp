
#include "precompiled.h"

using namespace ce;

int main()
{
	
	Mat44 mat44 = Mat44::GetIdentity();
	mat44.SetTranslation(5, 4, 2);
	Mat44 transposed = mat44.GetTranspose();

	transposed.Determinant();

	Mat33 mat33 = Mat33::GetIdentity();
	mat33.Determinant();

	Mat44 mul = mat44*transposed;

	Vec3 v1(1, 0, 0);
	Vec3 v2(0, 1, 0);

	Vec3 v1v2 = v1 + v2;

	String str = v1v2.getDescription();

	std::cout << str;

	int n; std::cin >> n;
	return 0;
}