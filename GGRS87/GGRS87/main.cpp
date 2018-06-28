#include <math.h>
#include <ostream>
#include <iostream>

#define PI 3.1415926535897932384626433832795

using namespace std;

void ToGreekGrid(double lat, double lng, double &Easting, double &Northing)
{
	lat = lat * PI / 180.0;
	lng = lng * PI / 180.0;
	double a = 6378137.0;
	double b = 6356752.31424518;
	double e2 = (pow(a, 2) - pow(b, 2)) / pow(a, 2);
	double v = a / sqrt(1 - e2 * (sin(lat) * sin(lat)));
	double X = v * cos(lat) * cos(lng);
	double Y = v * cos(lat) * sin(lng);
	double Z = (v * (1 - e2)) * sin(lat);
	double px = 199.723;
	double py = -74.03;
	double pz = -246.018;
	double rw = 0;
	double rf = 0;
	double rk = 0;
	double ks = 1;
	double c1 = cos(rw);
	double c2 = cos(rf);
	double c3 = cos(rk);
	double s1 = sin(rw);
	double s2 = sin(rf);
	double s3 = sin(rk);
	double D11 = c2 * c3;
	double D21 = -c2 * s3;
	double D31 = sin(rf);
	double D12 = s1 * s2 * c3 + c1 * s3;
	double D22 = -s1 * s2 * s3 + c1 * c3;
	double D32 = -s1 * c2;
	double D13 = -c1 * s2 * c3 + s1 * s3;
	double D23 = c1 * s2 * s3 + s1 * c3;
	double D33 = c1 * c2;
	double X1 = px + ks * (D11 * X + D12 * Y + D13 * Z);
	double Y1 = py + ks * (D21 * X + D22 * Y + D23 * Z);
	double Z1 = pz + ks * (D31 * X + D32 * Y + D33 * Z);
	lng = atan2(Y1, X1);
	double lat0 = atan2(Z1, sqrt(X1 * X1 + Y1 * Y1));
	b = 6356752.31414036;
	e2 = (pow(a, 2) - pow(b, 2)) / pow(a, 2);
	while (abs(lat - lat0) > 0.0000000001)
	{
		double No = a / sqrt(1 - e2 * sin(lat0) * sin(lat0));
		double h = sqrt(X1 * X1 + Y1 * Y1) / cos(lat0) - No;
		lat = lat0;
		lat0 = atan(Z1 / sqrt(X1 * X1 + Y1 * Y1) * (1 / (1 - e2 * No / (No + h))));
	}
	lng = lng - 24 * PI / 180;
	double m0 = 0.9996;
	double es2 = (pow(a, 2) - pow(b, 2)) / (pow(b, 2));
	double V = sqrt(1 + es2 * cos(lat) * cos(lat));
	double eta = sqrt(es2 * cos(lat) * cos(lat));
	double Bf = atan(tan(lat) / cos(V * lng) * (1 + eta * eta / 6 * (1 - 3 * sin(lat) * sin(lat)) * lng * lng * lng * lng));
	double Vf = sqrt(1 + es2 * cos(Bf) * cos(Bf));
	double etaf = sqrt(es2 * cos(Bf) * cos(Bf));
	double n = (a - b) / (a + b);
	double r1 = (1 + n * n / 4 + n * n * n * n / 64) * Bf;
	double r2 = 3.0 / 2.0 * n * (1 - n * n / 8) * sin(2 * Bf);
	double r3 = 15.0 / 16.0 * n * n * (1 - n * n / 4) * sin(4 * Bf);
	double r4 = 35.0 / 48.0 * n * n * n * sin(6 * Bf);
	double r5 = 315.0 / 512.0 * n * n * n * n * sin(8 * Bf);
	Northing = a / (1 + n) * (r1 - r2 + r3 - r4 + r5) * m0 - 0.001 + 4202812 - 4207988.1206046063;
	double ys = tan(lng) * cos(Bf) / Vf * (1 + etaf * etaf * lng * lng * cos(Bf) * cos(Bf) * (etaf * etaf / 6 + lng * lng / 10));
	ys = log(ys + sqrt(ys * ys + 1));
	Easting = m0 * pow(a, 2) / b * ys + 500000;
	return; // new double[] { Easting, Northing };
}

int main(void) {

	double x, y, east=0.0, north=0.0;
	x = -20987;
	y = 25577;
	ToGreekGrid(x, y, east, north);

	cout << east << "," << north;

	return 0;
}