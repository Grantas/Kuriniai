#include <iostream>
#include <iomanip>
#include <fstream>
#include "Singleton.h"
using namespace std;

const char Grybai[] = "Grybai.txt";
const char Rez[] = "Rezultatai.txt";
const int MAX = 100;
void Ivedimas(int &n, int Diena[], int Menuo[], int Mase[], int Raudona[], int Baravykai[]);
void Skaiciavimas(int n, int Diena[], int Menuo[], int Mase[], int Raudona[], int Baravykai[], int &DerlingiausiaM, int &DerlingiausiaD, int &BaravykaiM, int &BaravykaiD, int &RaudonaM, int &RaudonaD);
void Isvedimas(int &DerlingiausiaM, int &DerlingiausiaD, int &BaravykaiM, int &BaravykaiD, int &RaudonaM, int &RaudonaD);


int main()
{
	int n = 0, Diena[MAX], Menuo[MAX], Mase[MAX], Raudona[MAX], Baravykai[MAX], DerlingiausiaD = 0, DerlingiausiaM = 0, BaravykaiM = 0, BaravykaiD = 0, RaudonaM = 0, RaudonaD = 0;
	Ivedimas(n, Diena, Menuo, Mase, Raudona, Baravykai);
	Skaiciavimas (n, Diena, Menuo, Mase, Raudona, Baravykai, DerlingiausiaM, DerlingiausiaD, BaravykaiM, BaravykaiD, RaudonaM, RaudonaD);
	Isvedimas(DerlingiausiaM, DerlingiausiaD, BaravykaiM, BaravykaiD, RaudonaM, RaudonaD);
	Singleton::Instance()->writeToLogFile();
	system("pause");
	return 0;
}
void Ivedimas (int &n, int Diena[], int Menuo[], int Mase[], int Raudona[], int Baravykai[])
{
	int i = 0;
	ifstream fd(Grybai);
	fd >> n;
	for (n; i < n; i ++)
	{
		fd >> Menuo[i];
		fd >> Diena[i];
		fd >> Mase[i];
		fd >> Baravykai[i];
		fd >> Raudona[i];
	}
	fd.close();
}
void Skaiciavimas(int n, int Diena[], int Menuo[], int Mase[], int Raudona[], int Baravykai[], int &DerlingiausiaM, int &DerlingiausiaD, int &BaravykaiM, int &BaravykaiD, int &RaudonaM, int &RaudonaD)
{
	int i = 0, maxM = 0, maxB = 0, maxR = 0;

	for (n; i < n; i++)
	{
		if (maxM < Mase[i])
		{
			maxM = Mase[i];
			DerlingiausiaM = Menuo[i];
			DerlingiausiaD = Diena[i];
		}
		if (maxB < Baravykai[i])
		{
			maxM = Baravykai[i];
			BaravykaiM = Menuo[i];
			BaravykaiD = Diena[i];
		}
		if (maxM < Raudona[i])
		{
			maxM = Raudona[i];
			RaudonaM = Menuo[i];
			RaudonaD = Diena[i];
		}
	}
}
void Isvedimas(int &DerlingiausiaM, int &DerlingiausiaD, int &BaravykaiM, int &BaravykaiD, int &RaudonaM, int &RaudonaD)
{
	ofstream fr (Rez);
	fr << "Derlingiausia diena: " << DerlingiausiaM << " " << DerlingiausiaD << endl;
	fr << "Derlingiausia baravyku diena: " << BaravykaiM << " " << BaravykaiD << endl;
	fr << "Derlingiausia raudonvirsiu diena: " << RaudonaM << " " << RaudonaD << endl;

}