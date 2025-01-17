#include "ClassProgramm.hpp"

//Operators Programm::Programm::Vec::Vec

Programm::ProgrammMath::Vec::Vec(double x_c, double y_c, double z_c): x(x_c), y(y_c), z(z_c) {}

Programm::ProgrammMath::Vec::Vec() :z(0), y(0), x(0) {}

Programm::ProgrammMath::Vec Programm::ProgrammMath::Vec::operator+(const Vec& vec){return Vec(this->x + vec.x, this->y + vec.y, this->z + vec.z);}

Programm::ProgrammMath::Vec Programm::ProgrammMath::Vec::operator-(const Vec& vec){return Vec(this->x - vec.x, this->y - vec.y, this->z - vec.z);}

Programm::ProgrammMath::Vec& Programm::ProgrammMath::Vec::operator=(const Vec& vec){Vec t_vec; t_vec.x = vec.x; t_vec.y = vec.y; t_vec.z = vec.z; return t_vec;}

Programm::ProgrammMath::Vec Programm::ProgrammMath::Vec::operator*(double coeff){return Vec(this->x * coeff, this->y * coeff, this->z * coeff);}

Programm::ProgrammMath::Vec Programm::ProgrammMath::Vec::operator/(double coeff) {if (coeff) { return Vec(this->x * coeff, this->y * coeff, this->z * coeff); }; throw "Division by zero!";}

//Methods Programm::ProgrammMath::Vec 

double Programm::ProgrammMath::Vec::modulVec(Vec& vec){return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);}

double Programm::ProgrammMath::Vec::cosVec(Vec& vec, Vec& vec1){return (vec.x * vec1.x + vec1.y * vec.y + vec.z * vec1.z) / (modulVec(vec) * modulVec(vec1));}

Programm::ProgrammMath::Vec Programm::ProgrammMath::Vec::Normalization(Vec& vec)
{
	double modul = modulVec(vec);
	if (modul) {
		vec.x = vec.x / modul; vec.y = vec.y / modul; vec.z = vec.z / modul;
		return vec; 
	}
	else {
		throw "Division by zero in modul!"; 
	}
}

void Programm::ProgrammMath::Vec::PrintVec() { std::cout << "[ " << x << ", " << y << ", " << z << "] "; }

//Constructur Programm::ProgrammFigure::Sphere

Programm::ProgrammFigure::Sphere::Sphere(double rad, double m, double x, double y, double z, double vel_x, double vel_y, double vel_z, bool moveble)
{
	if(moveble){
		r_vec = Programm::ProgrammMath::Vec(x, y, z);
		vel_vec = Programm::ProgrammMath::Vec(vel_x, vel_y, vel_z);
		radius = rad;
		mass = m; 
		status_moveble = true;
	}
	else {
		r_vec = Programm::ProgrammMath::Vec(x, y, z);
		vel_vec = Programm::ProgrammMath::Vec(0, 0, 0);
		radius = rad;
		mass = m;
		status_moveble = false;
	}
}

//Methods Programm::ProgrammFigure::Sphere

void Programm::ProgrammFigure::Sphere::changeCoordX(double x) { current_vec.x = x + r_vec.x; }

void Programm::ProgrammFigure::Sphere::changeCoordY(double y) { current_vec.y = y + r_vec.y; }

void Programm::ProgrammFigure::Sphere::changeCoordZ(double z) { current_vec.z = z + r_vec.z; }

double Programm::ProgrammFigure::Sphere::distance(Sphere& Sphere1, Sphere& Sphere2)
{
	Programm::ProgrammMath::Vec temp_Vec = (Sphere2.current_vec - Sphere1.current_vec);
    return Programm::ProgrammMath::Vec::modulVec(temp_Vec);
}
//Methods Programm::ProgrammForce::pwrOfGrvtBtwnTwObj force beetwen two objects

Programm::ProgrammMath::Vec Programm::ProgrammForce::pwrOfGrvtBtwnTwObj(Programm::ProgrammFigure::Sphere& Sphere1, Programm::ProgrammFigure::Sphere& Sphere2)
{
	double distance = Programm::ProgrammFigure::Sphere::distance(Sphere1, Sphere2); 
	double modul_GrvtForce = Gravity_const * (Sphere1.mass * Sphere2.mass) / (distance * distance);
	Programm::ProgrammMath::Vec vec_force = (Sphere1.r_vec - Sphere2.r_vec);
	auto vec_force_current = Programm::ProgrammMath::Vec::Normalization(vec_force);
	return vec_force_current * modul_GrvtForce; 
}
