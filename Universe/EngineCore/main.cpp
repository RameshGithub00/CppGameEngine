#include <math/matrix.h>

int main()
{
	
	Mat44 mat44 = Mat44::GetIdentity();
	mat44.SetTranslation(5, 4, 2);
	Mat44 transposed = mat44.GetTranspose();

	Mat44 mul = mat44*transposed;

	return 0;
}