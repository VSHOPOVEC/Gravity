#include "include.hpp"

class Programm {
public:
	class ProgrammFigure;
	class PhysicsField;

	class ProgrammMath {
	public:
		class Vec {
		public:
			//field
			double x, y, z;

			Vec(double x_c, double y_c, double z_c);

			Vec();

			Vec operator + (const Vec& vec);

			Vec operator - (const Vec& vec);

			Vec& operator = (const Vec& vec);

			Vec operator * (double coeff);

			Vec operator / (double coeff);

			static double modulVec(Vec& vec);

			static double cosVec(Vec& vec, Vec& vec1);

			static Vec Normalization(Vec& vec);

			void PrintVec();
		};
	};

	class ProgrammFigure {
	public:
		class Sphere {
		public:
			//fields of Sphere class
			double mass;
			double radius;
			bool status_moveble;
			Programm::ProgrammMath::Vec r_vec = { 0, 0, 0 };//Начальное положение сферы
			Programm::ProgrammMath::Vec current_vec = { 0, 0, 0 }; //Временный вектор, описывающий промежуточное положение сферы
			Programm::ProgrammMath::Vec vel_vec = { 0, 0, 0 };//Начальный вектор скорости

			Sphere(double rad, double m, double x, double y, double z, double vel_x, double vel_y, double vel_z, bool moveble);

			void changeCoordX(double x);

			void changeCoordY(double y);

			void changeCoordZ(double z);

			static double distance(Sphere& Sphere1, Sphere& Sphere2);
		};
	};

	class ProgrammForce {
	public:
		Programm::ProgrammMath::Vec pwrOfGrvtBtwnTwObj(Programm::ProgrammFigure::Sphere& Sphere1, Programm::ProgrammFigure::Sphere& Sphere2); //сила гравитации между двумя объектами
	};

	class Experiment {
	public:
		std::vector <Programm::ProgrammFigure::Sphere> Spheres;
		Programm::Programm::ProgrammMath::Vec xMainVector = { 1.0, 0.0, 0.0 };
		Programm::Programm::ProgrammMath::Vec yMainVector = { 0.0, 1.0, 0.0 };
		Programm::Programm::ProgrammMath::Vec zMainVector = { 0.0, 0.0, 1.0 };

		void toAddSpheres(Programm::ProgrammFigure::Sphere& Sphere) {
			Spheres.push_back(Sphere); 
		}

		static void toRunProgramm() {
			bool statusProgramm = true;
			auto start = std::chrono::high_resolution_clock::now();
			while (statusProgramm) {

			}
			auto end = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration<double>(end - start).count();
		}
	};
};