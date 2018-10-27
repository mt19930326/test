#include <iostream>
#include <Eigen/Core>
using namespace std;

int main(int argv, char** argc)
{
	
	int m, n;
	cout<<"line ="<<endl;
	cin>>m;
	cout<<"row ="<<endl;
	cin>>n;
	Eigen::MatrixXd matrix_x(m,n);
	cout<<"please input the matrix"<<endl;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>matrix_x(i,j);
		}
	}
	cout<<"input matrix is"<<matrix_x<<endl;
	Eigen::Matrix3d matrix_3 = matrix_x.block(0,0,3,3);
	cout<<"original matrix is"<<matrix_3<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			matrix_3(i,j)=1.0;
		}		
	}

	cout<<"imodified matrix is"<<matrix_3<<endl;
}
