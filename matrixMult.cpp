#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

//Matrix structure
struct Matrix {
	double values[5][5];
};

//Function Prototypes
Matrix multiply(Matrix &m1, Matrix &m2);
void toString(Matrix &m1);

/**
    This is the matrix multiplication method on nxn matrices.
    @param radius The radius of the circle.
    @return The volume of the sphere.
*/
Matrix multiply(Matrix &m1, Matrix &m2) {
	Matrix product;

	for (int row=0; row < 5; row++) {
		for (int col=0; col < 5; col++) {
			for(int i=0; i < 5; i++) {
				product.values[row][col] += (m1.values[row][i] * m2.values[i][col]);
			}
		}
	}
	return product;
}

/**
    This method turns the matrix into a printable value
	@param double a[][] A matrix.
	@return String 
*/
void toString(Matrix &m1) {
	for (int row=0; row < 5; row++) {
		for (int col=0; col < 5; col++) {
			cout << m1.values[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	Matrix arr1, arr2;

	//Matrix1
	arr1.values[0][0] = 1.0;
	arr1.values[0][1] = 2.0;
	arr1.values[0][2] = 3.0;
	arr1.values[0][3] = 4.0;
	arr1.values[0][4] = 5.0;

	arr1.values[1][0] = 6.0;
	arr1.values[1][1] = 7.0;
	arr1.values[1][2] = 8.0;
	arr1.values[1][3] = 9.0;
	arr1.values[1][4] = 10.0;

	arr1.values[2][0] = 11.0;
	arr1.values[2][1] = 12.0;
	arr1.values[2][2] = 13.0;
	arr1.values[2][3] = 14.0;
	arr1.values[2][4] = 15.0;

	arr1.values[3][0] = 16.0;
	arr1.values[3][1] = 17.0;
	arr1.values[3][2] = 18.0;
	arr1.values[3][3] = 19.0;
	arr1.values[3][4] = 20.0;

	arr1.values[4][0] = 21.0;
	arr1.values[4][1] = 22.0;
	arr1.values[4][2] = 23.0;
	arr1.values[4][3] = 24.0;
	arr1.values[4][4] = 25.0;

	//Matrix2
	arr2.values[0][0] = 1.0;
	arr2.values[0][1] = 2.0;
	arr2.values[0][2] = 3.0;
	arr2.values[0][3] = 4.0;
	arr2.values[0][4] = 5.0;

	arr2.values[1][0] = 6.0;
	arr2.values[1][1] = 7.0;
	arr2.values[1][2] = 8.0;
	arr2.values[1][3] = 9.0;
	arr2.values[1][4] = 10.0;

	arr2.values[2][0] = 11.0;
	arr2.values[2][1] = 12.0;
	arr2.values[2][2] = 13.0;
	arr2.values[2][3] = 14.0;
	arr2.values[2][4] = 15.0;

	arr2.values[3][0] = 16.0;
	arr2.values[3][1] = 17.0;
	arr2.values[3][2] = 18.0;
	arr2.values[3][3] = 19.0;
	arr2.values[3][4] = 20.0;

	arr2.values[4][0] = 21.0;
	arr2.values[4][1] = 22.0;
	arr2.values[4][2] = 23.0;
	arr2.values[4][3] = 24.0;
	arr2.values[4][4] = 25.0;

    //Matrix Multiplication 
    Matrix arr3 = multiply(arr1, arr2);
    toString(arr3);

    //Run-time Analysis
    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    std::chrono::duration<double> time_span;
    for(int i=0; i<10; i++) {
		t1 = std::chrono::steady_clock::now();
		Matrix arr3 = multiply(arr1, arr2);
		t2 = std::chrono::steady_clock::now();
		
		time_span += std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);
		
	}
	std::chrono::duration<double> averageTime = time_span/10.0;
	averageTime *= 1000000000;	//Convert to nanoseconds

	std::cout << "C++ Matrix Mult Average time taken: " << averageTime.count() << " nanoseconds.";
	std::cout << std::endl;
}





