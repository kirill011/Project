#pragma once
#include <math.h>
#include <random>
#include <cstdlib>
#include <cassert>

using namespace std;


enum Doljnosti {
	Stajer,
	MladhiyManager,
	Manager,
	StarshiyManager,
	NachalnikOtdela
};
enum Otdeli {
	Administraciya,
	Bezopasnosti,
	PoRaboteSklientami,
	Analitiki
};


class sotrudniki
{
	friend class genDirector;
protected:
	int zarplata;
	int procVipPlan;
	int obshiyZarobotok;
	bool noLishenPremii;
	string FIO;
	Doljnosti Doljnost;
	Otdeli Otdel;
	virtual int podsObshiyZarabotok();
};

class genDirector :sotrudniki
{
public:
	genDirector(int newprocVipPlan, string newFIO, Doljnosti newDoljnost = NachalnikOtdela, Otdeli newOtdel = Administraciya, int newzarplata = 120000, bool newnoLishenPremii = 1);
	void IzmenitZarplatu(sotrudniki* sotrudnik, int newZarplata);
	void povisit(sotrudniki* sotrudnik);
	int getZarplata();
};

class admnistraciya :sotrudniki
{
public:
	admnistraciya(string newFIO, int newprocVipPlan,  Doljnosti newDoljnost, Otdeli newOtdel = Administraciya, int newzarplata = 50000, bool newnoLishenPremii = 1);
	admnistraciya();
	int getZarplata();
};

class bezopasnosti :sotrudniki {
protected:
	int procStabilnostiSistemi;
public:
	int podsObshiyZarabotok();
	int getZarplata();
	bezopasnosti();
	bezopasnosti(int newProcStabilnostiSistemi, int newprocVipPlan, string newFIO, Doljnosti newDoljnost, Otdeli newOtdel = Bezopasnosti, int newzarplata = 35000, bool newnoLishenPremii = 1);
};


class poRaboteSKlientami :sotrudniki
{
private:
	int kolvoZhalob;
	int kolvoKlientov;
public:
	int podsObshiyZarabotok();
	int getZarplata();
	poRaboteSKlientami();
	poRaboteSKlientami(int newKolvoZhalob, int newKolvoKlientov, int newprocVipPlan, string newFIO, Doljnosti newDoljnost, Otdeli newOtdel = PoRaboteSklientami, int newzarplata = 40000, bool newnoLishenPremii = 1);
};

class analitiki :sotrudniki
{
protected:
	int udachniePrognozi;
	int neudachniePrognozi;
public:
	void prognozi();
	int getZarplata();
	int podsObhiyZarabotok();
	analitiki();
	analitiki(string newFIO, Doljnosti newDoljnost, Otdeli newOtdel = Analitiki, int newzarplata = 40000, bool newnoLishenPremii = 1);
	int poluchitPronozi(bool chtoPoluchaem);
};