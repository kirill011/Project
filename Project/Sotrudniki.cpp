#include <math.h>
#include <random>
#include <cstdlib>
#include <cassert>
#include "Sotrudniki.h"

using namespace std;


int sotrudniki::podsObshiyZarabotok()
{
	if (procVipPlan <= 70)
	{
		noLishenPremii = 0;
	}
	if (procVipPlan <= 95)
	{
		obshiyZarobotok = zarplata + zarplata * 0.05 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (procVipPlan <= 110 && procVipPlan > 95)
	{
		obshiyZarobotok = zarplata + zarplata * 0.1 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (procVipPlan <= 120 && procVipPlan > 110)
	{
		obshiyZarobotok = zarplata + zarplata * 0.15 * noLishenPremii + zarplata * Doljnost / 20;
	}
	return obshiyZarobotok;
}

void genDirector::IzmenitZarplatu(sotrudniki* sotrudnik, int newZarplata)
{
	sotrudnik->zarplata = newZarplata;                           // Potom Razobrat'sya
};
void genDirector::povisit(sotrudniki* sotrudnik)
{
	sotrudnik->Doljnost = Doljnosti(Doljnost + 1);
};

int genDirector::getZarplata()
{
	return obshiyZarobotok;
}

genDirector::genDirector(int newprocVipPlan, string newFIO, Doljnosti newDoljnost, Otdeli newOtdel , int newzarplata, bool newnoLishenPremii )
{
	//assert(Doljnost != NachalnikOtdela);
	zarplata = newzarplata;
	procVipPlan = newprocVipPlan;
	noLishenPremii = newnoLishenPremii;
	FIO = newFIO;
	Doljnost = newDoljnost;
	Otdel = newOtdel;
	obshiyZarobotok = podsObshiyZarabotok();
};

admnistraciya::admnistraciya(string newFIO, int newprocVipPlan, Doljnosti newDoljnost, Otdeli newOtdel, int newzarplata, bool newnoLishenPremii)
{
	zarplata = newzarplata;
	procVipPlan = newprocVipPlan;
	noLishenPremii = newnoLishenPremii;
	FIO = newFIO;
	Doljnost = newDoljnost;
	Otdel = newOtdel;
	obshiyZarobotok = podsObshiyZarabotok();
};

admnistraciya::admnistraciya()
{
	zarplata = 0;
	procVipPlan = 0;
	noLishenPremii = 0;
};
int admnistraciya::getZarplata()
{
	return obshiyZarobotok;
}

int bezopasnosti::podsObshiyZarabotok() {
	if (procStabilnostiSistemi <= 70)
	{
		noLishenPremii = 0;
	}
	if (procStabilnostiSistemi <= 80)
	{
		obshiyZarobotok = zarplata + zarplata * 0.05 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (procStabilnostiSistemi <= 90 && procStabilnostiSistemi > 80)
	{
		obshiyZarobotok = zarplata + zarplata * 0.1 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (procStabilnostiSistemi <= 100 && procStabilnostiSistemi > 90)
	{
		obshiyZarobotok = zarplata + zarplata * 0.15 * noLishenPremii + zarplata * Doljnost / 20;
	}
	return obshiyZarobotok;
};
bezopasnosti::bezopasnosti(int newProcStabilnostiSistemi, int newprocVipPlan, string newFIO, Doljnosti newDoljnost, Otdeli newOtdel, int newzarplata, bool newnoLishenPremii)
{
	zarplata = newzarplata;
	procVipPlan = newprocVipPlan;
	noLishenPremii = newnoLishenPremii;
	FIO = newFIO;
	Doljnost = newDoljnost;
	Otdel = newOtdel;
	procStabilnostiSistemi = newProcStabilnostiSistemi;
	obshiyZarobotok = podsObshiyZarabotok();
}

bezopasnosti::bezopasnosti()
{
	zarplata = 0;
	procVipPlan = 0;
	noLishenPremii = 0;
}

int bezopasnosti::getZarplata()
{
	return obshiyZarobotok;
}

int poRaboteSKlientami::podsObshiyZarabotok()
{
	if (kolvoZhalob / kolvoKlientov >= 0.20)
	{
		noLishenPremii = 0;
	}
	if (kolvoZhalob / kolvoKlientov <= 0.15)
	{
		obshiyZarobotok = zarplata + zarplata * 0.05 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (kolvoZhalob / kolvoKlientov < 0.15 && kolvoZhalob / kolvoKlientov >= 10)
	{
		obshiyZarobotok = zarplata + zarplata * 0.1 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (kolvoZhalob / kolvoKlientov < 10)
	{
		obshiyZarobotok = zarplata + zarplata * 0.15 * noLishenPremii + zarplata * Doljnost / 20;
	}
	return obshiyZarobotok;
}
poRaboteSKlientami::poRaboteSKlientami(int newKolvoZhalob, int newKolvoKlientov, int newprocVipPlan, string newFIO, Doljnosti newDoljnost, Otdeli newOtdel, int newzarplata, bool newnoLishenPremii)
{
	zarplata = newzarplata;
	procVipPlan = newprocVipPlan;
	noLishenPremii = newnoLishenPremii;
	FIO = newFIO;
	Doljnost = newDoljnost;
	Otdel = newOtdel;
	kolvoZhalob = newKolvoZhalob;
	kolvoKlientov = newKolvoKlientov;
	obshiyZarobotok = podsObshiyZarabotok();
};

poRaboteSKlientami::poRaboteSKlientami()
{
	zarplata = 0;
	procVipPlan = 0;
	noLishenPremii = 0;
};

int poRaboteSKlientami::getZarplata()
{
	return obshiyZarobotok;
}

void analitiki::prognozi()
{
	udachniePrognozi = rand() % 101;
	neudachniePrognozi = rand() % 101;
}
int analitiki::podsObhiyZarabotok()
{
	if (udachniePrognozi / neudachniePrognozi <= 1.1)
	{
		noLishenPremii = 0;
	}
	if (udachniePrognozi / neudachniePrognozi >= 1.2)
	{
		obshiyZarobotok = zarplata + zarplata * 0.05 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (udachniePrognozi / neudachniePrognozi > 1.2 && udachniePrognozi / neudachniePrognozi <= 1.3)
	{
		obshiyZarobotok = zarplata + zarplata * 0.1 * noLishenPremii + zarplata * Doljnost / 20;
	}
	if (udachniePrognozi / neudachniePrognozi > 1.3)
	{
		obshiyZarobotok = zarplata + zarplata * 0.15 * noLishenPremii + zarplata * Doljnost / 20;
	}
	return obshiyZarobotok;
}
analitiki::analitiki(string newFIO, Doljnosti newDoljnost, Otdeli newOtdel, int newzarplata, bool newnoLishenPremii)
{
	FIO = newFIO;
	Doljnost = newDoljnost;
	Otdel = newOtdel;
	prognozi();
	obshiyZarobotok = podsObshiyZarabotok();
	zarplata = newzarplata;
	noLishenPremii = newnoLishenPremii;
}

analitiki::analitiki()
{
	noLishenPremii = 0;
	zarplata = 0;
}

int analitiki::poluchitPronozi(bool chtoPoluchaem)
{
	if (chtoPoluchaem == 0)
	{
		return udachniePrognozi;
	}
	else
	{
		return neudachniePrognozi;
	}
}

int analitiki::getZarplata()
{
	return obshiyZarobotok;
}