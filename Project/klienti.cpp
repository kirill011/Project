#include <math.h>
#include <random>
#include <cstdlib>
#include <cassert>
#include"klienti.h"

using namespace std;

int obmenValut::raschetProfita()
{
	profit = (kursProdaji - kursPokupki) * kolvoVoluti;
	return profit;
}
obmenValut::obmenValut(string newFIO, int newKursPokupki, int newKursProdaji, int newKolvoVoluti)
{
	fio = newFIO;
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
	kursPokupki = newKursPokupki;
	kursProdaji = newKursProdaji;
	kolvoVoluti = newKolvoVoluti;
	profit = raschetProfita();
};
obmenValut::obmenValut() {
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
};

int srochnie::raschetProfita()
{
	return profit = summa * (Analitic->poluchitPronozi(0)) / (Analitic->poluchitPronozi(1)) - summa * stavka / 100;
};
srochnie::srochnie(analitiki* newAnalitic, string newFIO, int newSumma, int newStavka, int newSrok)
{
	Analitic = newAnalitic;
	fio = newFIO;
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
	summa = newSumma;
	stavka = newStavka;
	srok = newSrok;
	profit = raschetProfita();
};
srochnie::srochnie() 
{
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
};


int doVostreb::ch()
{
	int a = rand() % 100;
	if (a < 99)
	{
		return 1;
	}
	else
		return -1;
}
int doVostreb::raschetProfita()
{
	return summa * chianfanelly * 2 - summa * stavka;
};
doVostreb::doVostreb(string newFIO, int newSumma, int newStavka)
{
	fio = newFIO;
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
	summa = newSumma;
	stavka = newStavka;
	chianfanelly = ch();
	profit = raschetProfita();
};
doVostreb::doVostreb()
{
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
};

void krediti::raschetSummiItogovoi()
{
	summaItogovaya = srok * summaZaprashivaemaya * (stavka + (stavka / pow(1 + stavka, srok) - 1));
};
int  krediti::raschetProfita()
{
	profit = odobreno * (summaItogovaya - summaZaprashivaemaya);
	return profit;
};
void  krediti::odobreniye()
{
	if ((summaZaprashivaemaya * (stavka + (stavka / pow(1 + stavka, srok) - 1))/srok) / Zarplata < 0.3)
	{
		odobreno = 1;
	}
	else
	{
		odobreno = 0;
	}
};

potrebitelskieKrediti::potrebitelskieKrediti(string newFIO, int newVozrast, bool newVBrake, int newZarplata, int newSummaZaprashivaemaya, int newSrok, int newStavka)
{
	fio = newFIO;
	vozrast = newVozrast;
	vBrake = newVBrake;
	Zarplata = newZarplata;
	summaZaprashivaemaya = newSummaZaprashivaemaya;
	stavka = newStavka;
	srok = newSrok;
	raschetSummiItogovoi();
	odobreniye();
	profit = raschetProfita();
};
potrebitelskieKrediti::potrebitelskieKrediti()
{
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
};

void ipotechnieKrediti::raschetLigot()
{
	if (vozrast <= 25 && vBrake == 1)
		stavka = stavka / 2;
};
ipotechnieKrediti::ipotechnieKrediti(string newFIO, int newVozrast, bool newVBrake, int newZarplata, int newSummaZaprashivaemaya, int newSrok, int newStavka)
{
	fio = newFIO;
	vozrast = newVozrast;
	vBrake = newVBrake;
	Zarplata = newZarplata;
	summaZaprashivaemaya = newSummaZaprashivaemaya;
	stavka = newStavka;
	srok = newSrok;
	raschetLigot();
	raschetSummiItogovoi();
	odobreniye();
	profit = raschetProfita();
};
ipotechnieKrediti::ipotechnieKrediti()
{
	vozrast = 0;
	vBrake = 0;
	Zarplata = 0;
};