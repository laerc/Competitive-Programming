// Not finished yet
// The algorithm does not give the correct answer.
#include <bits/stdc++.h>

using namespace std;

double A;
double PI = acos(-1);
int t;

struct point{
	double x, y, z;
};

class Cube{
public:
	point pontos[6];
	point pontosRotated[6];

	Cube(){
		for(int i = 7; i >= 0; i--){
			pontos[i].x = (i&1) > 0 ? -0.5 : 0.5;
			pontos[i].y = (i&2) > 0 ? -0.5 : 0.5;
			pontos[i].z = (i&4) > 0 ? -0.5 : 0.5;
		}
	}
	bool solve(double x){
		for(int i = 0; i < 6; i++){
			pontosRotated[i].y = pontos[i].y*cos(x)-pontos[i].z*sin(x);
			pontosRotated[i].z = pontos[i].y*sin(x)+pontos[i].z*cos(x);
			pontosRotated[i].x = pontos[i].x;
		}
		return area();
	}
	double area(){
		double resp = 0.0;
		for(int i = 0; i<6; i++){
			int nxt = (i+1)%6;
			//printf("%lf %lf", pontosRotated[i].x, pontosRotated[i].z);
			resp += fabs((pontosRotated[i].x * pontosRotated[nxt].z + pontosRotated[nxt].x * pontosRotated[i].z));
		}
		//printf("\n%lf\n",resp);
		return resp;
	}
};

int main (){
	scanf("%d", &t);
	Cube *cube = new Cube();
	for(int ii = 1; ii <= t; ii++){
		scanf("%lf", &A);
		double l = 0.0, h = 90.0;
		for(int i = 0; i < 200 && l < h; i++){
			double m1 = l + ((h-l)/3.0);      
			double m2 = h - ((h-l)/3.0);      
			double x = (PI*m1) / 180.0;
			if(cube->solve(x) < A){
				l = m1;
			}
			else{
				h = m2;
			}
		}
		printf("%lf\n", ((PI*l) / 180.0));
		double ans = cube->area();
		printf("%lf\n", ans);
	}

	return 0;
}