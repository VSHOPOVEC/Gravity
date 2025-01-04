#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <stdexcept>


class Programm {
public:
	class Vec {
	public:
		double x, y, z;
		Vec(double x_c, double y_c, double z_c):x(x_c), y(y_c), z(z_c){}
		Vec():x(0), y(0), z(0) {}
		Vec operator + (const Vec& vec) {
			return Vec(this->x + vec.x, this->y + vec.y, this->z + vec.z);
		}
		Vec operator - (const Vec& vec) {
			return Vec(this->x - vec.x, this->y - vec.y, this->z - vec.z);
		}
		Vec operator = (const Vec& vec) {
			Vec t_vec; t_vec.x = vec.x; t_vec.y = vec.y; t_vec.z = vec.z;
			return t_vec; 
		}
		Vec operator * (double coeff) {
			return Vec(this->x*coeff, this->y* coeff, this->z*coeff);
		}
		Vec operator / (double coeff) {
			if (coeff != 0) {
				return Vec(this->x / coeff, this->y / coeff, this->z / coeff);
			}
			else {
				return Vec(); 
			}
		}
		static double modulVec(Vec& vec) {
			return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		}
		static double cosVec(Vec& vec,Vec& vec1) {
			return (vec.x * vec1.x + vec1.y * vec.y + vec.z * vec1.z) / (modulVec(vec) * modulVec(vec1));
		}
		void PrintVec() {
			std::cout << "[ " << x << ", " << y << ", " << z << "] "; 
		}
	};
	class Sphere {
	public:
		double mass;
		double radius;
		Programm::Vec r_vec = { 0, 0, 0 };//Начальное положение сферы
		Programm::Vec current_vec = { 0, 0, 0 }; //Временный вектор, описывающий промежуточное положение сферы
		Sphere(double rad, double m, double x, double y, double z): radius(rad), mass(m), r_vec(Programm::Vec(x, y, z)), current_vec(Programm::Vec(x, y, z)) {}
		void changeCoordX(double x) { current_vec.x = x + r_vec.x; }
		void changeCoordY(double y) { current_vec.y = y + r_vec.y; }
		void changeCoordZ(double z) { current_vec.z = z + r_vec.z; }
		static double distance(Sphere& Sphere1, Sphere& Sphere2){
			Programm::Vec temp_Vec = (Sphere2.current_vec - Sphere1.current_vec);
			return Programm::Vec::modulVec(temp_Vec);
		}
	};
	class GravityField {
	public:
		void AddSphereIntoSpaces(Sphere& Sphere) {
			sphereVector.push_back(Sphere);
		}
		void savePtFunction(std::function<double(double x, double y)> function) {
			equp_field = function;
		}
		double callPtFunction(double x, double y) {
			return equp_field(x, y);
		}
		double powerOfGravity(Sphere &Sphere) {
			return Sphere.mass * coeff_gravity; 
		}
		Programm::Vec xMainVector = { 1.0, 0.0, 0.0 };
		Programm::Vec yMainVector = { 0.0, 1.0, 0.0 };
		Programm::Vec zMainVector = { 0.0, 0.0, 1.0 };
	private:
		std::function<double(double, double)> equp_field;
		double coeff_gravity = 0; 
		std::vector<Sphere> sphereVector;
	};
	class Experement {
	public:
		double powerOfGravityBeetwenSpheres(Sphere& Sphere1, Sphere& Sphere2) {
			double distance_ = Programm::Sphere::distance(Sphere1, Sphere2);
			return (Sphere1.mass * Sphere2.mass) / (distance_ * distance_);
		}
		double acceleration(Sphere& Sphere, double powerOfGravityBeetwenSpheres) {
			return powerOfGravityBeetwenSpheres / Sphere.mass;
		}
		bool main(GravityField& expGravityField,Sphere& Sphere1, Sphere& Sphere2, double Current_time) {
			Programm::Vec Vec_force_1 = (Sphere1.r_vec - Sphere2.r_vec)*(-1);
			Programm::Vec Vec_force_2 = Vec_force_1 * (-1); 
			double modulOfPower = powerOfGravityBeetwenSpheres(Sphere1, Sphere2); 
			double proj_v1_x = Programm::Vec::cosVec(Vec_force_1, expGravityField.xMainVector); double proj_v1_y = Programm::Vec::cosVec(Vec_force_1, expGravityField.yMainVector); double proj_v1_z = Programm::Vec::cosVec(Vec_force_1, expGravityField.zMainVector);
			double proj_v2_x = Programm::Vec::cosVec(Vec_force_2, expGravityField.xMainVector); double proj_v2_y = Programm::Vec::cosVec(Vec_force_2, expGravityField.yMainVector); double proj_v2_z = Programm::Vec::cosVec(Vec_force_2, expGravityField.zMainVector);
			double force_proj_v1_x = proj_v1_x * modulOfPower; double force_proj_v1_y = proj_v1_y * modulOfPower; double force_proj_v1_z = proj_v1_z * modulOfPower;
			double force_proj_v2_x = proj_v2_x * modulOfPower; double force_proj_v2_y = proj_v2_y * modulOfPower; double force_proj_v2_z = proj_v2_z * modulOfPower;

			double vel_proj_v1_x = (force_proj_v1_x / Sphere1.mass) * Current_time; double vel_pro1_v1_y = (force_proj_v1_y / Sphere1.mass) * Current_time; double vel_proj_v1_z = (force_proj_v1_z / Sphere1.mass) * Current_time;
			double vel_proj_v2_x = (force_proj_v2_x / Sphere2.mass) * Current_time; double vel_pro1_v2_y = (force_proj_v2_y / Sphere2.mass) * Current_time; double vel_proj_v2_z = (force_proj_v2_z / Sphere2.mass) * Current_time;

			double add_coord_v1_x = vel_proj_v1_x * Current_time; double add_coord_v1_y = vel_pro1_v1_y * Current_time; double add_coord_v1_z = vel_proj_v1_z * Current_time;
			double add_coord_v2_x = vel_proj_v2_x * Current_time; double add_coord_v2_y = vel_pro1_v2_y * Current_time; double add_coord_v2_z = vel_proj_v2_z * Current_time;
			Sphere1.changeCoordX(add_coord_v1_x); Sphere1.changeCoordY(add_coord_v1_y); Sphere1.changeCoordZ(add_coord_v1_z);
			Sphere2.changeCoordX(add_coord_v2_x); Sphere2.changeCoordY(add_coord_v2_y); Sphere2.changeCoordZ(add_coord_v2_z);
			if (Programm::Sphere::distance(Sphere1, Sphere2) < Sphere1.radius + Sphere2.radius) {
				return true;
			}
			else {
				return false;
			}
		}
	};
	static void toRunProgramm(Experement& exp, GravityField& expGravityField, Sphere& Sphere1, Sphere& Sphere2) {
		auto start = std::chrono::high_resolution_clock::now();
		while (true) {
			if (exp.main(expGravityField, Sphere1, Sphere2, std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count())) {
				break; 
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration<double>(end - start).count();
	}
};



int main() {
	Programm::Sphere Sphere1(1, 10000000, 1, 1, 1);//rad, mass,x,y,z
	Programm::Sphere Sphere2(1, 1, 1000, 1000, 0);
	Programm::GravityField expGravityField;
	Programm::Experement Exp1;
	Programm::toRunProgramm(Exp1, expGravityField, Sphere1, Sphere2); 
	return 0;
}