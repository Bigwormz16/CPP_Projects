#include <iostream>
#include <array>

template <typename T, unsigned int I, unsigned int J>
using Matrix = std::array<std::array<T, J>, I>;

typedef std::array<std::array<int, 5>, 5> SqMat_5x5;

int main()
{
	Matrix<int, 3, 4> matrix;
	SqMat_5x5 sqMatrix;

	return 0;
}
