#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

int main( int argv, char** argc)
{
        //初始化四元数，并归一化
	Eigen::Vector4d q1 (0.35,0.2,0.3,0.1), q2 (-0.5,0.4,-0.1,0.2);
        Eigen::Vector4d q11= q1.array().square();
        double sum_p1 = q11.sum();  	
        Eigen::Vector4d q22= q2.array().square();
        double sum_p2 = q22.sum();  	
        Eigen::Quaterniond q1_qua (q1(0)/sum_p1, q1(1)/sum_p1, q1(2)/sum_p1, q1(3)/sum_p1);
        Eigen::Quaterniond q2_qua (q2(0)/sum_p2, q2(1)/sum_p2, q2(2)/sum_p2, q2(3)/sum_p2);
//      cout<<q1_qua.coeffs()<<endl;
//      cout<<q2_qua.coeffs()<<endl;
	
	//四元数变为旋转向量
	Eigen::AngleAxisd r1 = Eigen::AngleAxisd( q1_qua);
	Eigen::AngleAxisd r2 = Eigen::AngleAxisd( q2_qua);
//      cout<<q1_qua.coeffs()<<endl;
//      cout<<q1_qua.coeffs()<<endl;
	
	//旋转向量和平移向量变为欧式变换矩阵
	Eigen::Isometry3d T1=Eigen::Isometry3d::Identity();
	T1.rotate( r1 );
	T1.pretranslate( Eigen::Vector3d (0.3, 0.1, 0.1));
	Eigen::Isometry3d T2=Eigen::Isometry3d::Identity();
	T2.rotate( r2 );
	T2.pretranslate( Eigen::Vector3d (-0.1, 0.5, 0.3));
	cout<<"TCW1="<<T1.matrix()<<endl;
	cout<<"TCW2="<<T2.matrix()<<endl;

	Eigen::Vector3d p (0.5, 0.0, 0.2), p_now;
	p_now=T2*T1.inverse()*p;

	cout<<"result is"<<p_now<<endl;

        return 0;
}
