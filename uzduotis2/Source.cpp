#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int Cn = 21;
const char Cduom[] = "duom.txt";
const char Crez[] = "rezultatai.txt";
struct Auto {
	char pv[Cn];
	int kelias;
	double kuras;
	double vidKuras;
};
void ivedimas(const char fv[], Auto sar[], int& kiek);
void isvedimas(const char fv[], Auto sar[], int kiek);
void vidurkis(Auto sar[], int kiek);
void rikiavimas(Auto sar[], int kiek);
int daugiausiaKM(Auto sar[], int kiek);
int main() {
	Auto duomenys[Cn];
	int kiek;
	ivedimas(Cduom, duomenys, kiek);
	vidurkis(duomenys, kiek);
	rikiavimas(duomenys, kiek);
	isvedimas(Crez, duomenys, kiek);
	return 0;
}

void ivedimas(const char fv[], Auto sar[], int& kiek) {
	ifstream fd(fv);
	kiek = 0;
	while(!fd.eof()){
		fd.get(sar[kiek].pv, sizeof sar[kiek].pv);		
		fd >> sar[kiek].kelias >> sar[kiek].kuras;
		fd.ignore();
		kiek++;
	}
	fd.close();
}
void isvedimas(const char fv[], Auto sar[], int kiek) {
	ofstream fr(fv);
	int iDid = daugiausiaKM(sar, kiek);
	for (int i = 0; i < kiek; i++) {
		fr << sar[i].pv << setw(6) << left << setprecision(3)<< sar[i].vidKuras << endl;
	}
	fr << "Daugiausiai km. nuvaziavo: " << sar[iDid].pv << endl;
	fr.close();
}
void vidurkis(Auto sar[], int kiek) {
	for (int i = 0; i < kiek; i++) {
		sar[i].vidKuras = 100 * sar[i].kuras / sar[i].kelias;
	}
}
void rikiavimas(Auto sar[], int kiek) {
	Auto naujas[Cn];
	for (int i = 0; i < kiek - 1; i++) {
		for (int j = i + 1; j < kiek; j++) {
			if (sar[j].vidKuras < sar[i].vidKuras) {
				naujas[i] = sar[j];
				sar[j] = sar[i];
				sar[i] = naujas[i];
			}
		}
	}
}
int daugiausiaKM(Auto sar[], int kiek) {
	int iDid = 0;
	int did = sar[0].kelias;
	for (int i = 1; i < kiek; i++) {
		if (sar[i].kelias > iDid)
			iDid = i;
	}
	return iDid;
}