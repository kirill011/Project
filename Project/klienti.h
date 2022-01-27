#pragma once
#include <math.h>
#include <random>
#include "Sotrudniki.h"
using namespace std;

class Klienti
{
protected:
	string fio;
	int vozrast;
	bool vBrake;
	int profit;
	int Zarplata;
};

class obmenValut : Klienti
{
private:
	int kursPokupki;
	int kursProdaji;
	int kolvoVoluti;
public:
	int raschetProfita();
	obmenValut();
	obmenValut(string newFIO, int newKursPokupki, int newKursProdaji, int newKolvoVoluti);
};

class vkladi : protected Klienti
{
protected:
	int summa;
	int stavka;
	analitiki* Analitic;
};

class srochnie :vkladi
{
private:
	int srok;
public:
	int raschetProfita();
	srochnie();
	srochnie(analitiki* newAnalitic, string newFIO, int newSumma, int newStavka, int newSrok);
};


class doVostreb :vkladi
{
private:
	int chianfanelly;
public:
	int ch();
	int raschetProfita();
	doVostreb();
	doVostreb(string newFIO, int newSumma, int newStavka);
};

class krediti :protected Klienti
{
protected:
	int summaZaprashivaemaya;
	int summaItogovaya;
	int stavka;
	int srok;
	bool odobreno;
public:
	virtual void raschetSummiItogovoi();
	int raschetProfita();
	virtual void odobreniye();
};

class potrebitelskieKrediti : protected krediti
{
public:
	krediti::raschetProfita;
	potrebitelskieKrediti();
	potrebitelskieKrediti(string newFIO, int newVozrast, bool newVBrake, int newZarplata, int newSummaZaprashivaemaya, int newSrok, int newStavka = 10);
};

class ipotechnieKrediti : protected krediti
{
public:
	krediti::raschetProfita;
	void raschetLigot();
	ipotechnieKrediti();
	ipotechnieKrediti(string newFIO, int newVozrast, bool newVBrake, int newZarplata, int newSummaZaprashivaemaya, int newSrok, int newStavka = 10);
};