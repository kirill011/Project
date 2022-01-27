#include <iostream>
#include "Sotrudniki.h";
#include "klienti.h"
#include <Windows.h>


// ИМЕНА ПИШИТЕ БЕЗ ПРОБЕЛА!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int rejimRaboti;
	int stopSot = 0;
	int stopKl = 0;
	///////////////////////////////////
	int countAdmins = 0;
	int countBezopasniki = 0;
	int countPoRab = 0;
	int countAnalitiki = 0;
	//////////////////////////////////////////
	genDirector* director = 0;
	admnistraciya** adminsNach = 0;
	bezopasnosti** bezopasnikiNach = 0;
	poRaboteSKlientami** poRabNach = 0;
	analitiki** ansNach = 0;
	///////////////////////////////////////////
	int countObmen = 0;
	int countPotKred = 0;
	int countIpKred = 0;
	int countDoVostr = 0;
	int countSroch = 0;
	/////////////////////////////////////////////
	obmenValut** obmensNach = 0;
	potrebitelskieKrediti** potKredsNach = 0;
	ipotechnieKrediti** ipKredsNach = 0;
	doVostreb** doVosrtrebsNach = 0;
	srochnie** srochniesNach = 0;
	/////////////////////////////////////////////
	while (true)
	{
		cout << "Выберете режим работы \n 1 - изменить БД \n 2 - подсчитать прибыль \n 3 - выйти" << endl;
		cin >> rejimRaboti;
		if (rejimRaboti == 1)
		{
			int cheloveki;
			cout << "Выберите кого добавить\n 1 - сотрудники\n 2 - клиенты" << endl;
			cin >> cheloveki;
			if (cheloveki == 1)
			{
				stopSot = 0;
				while (!stopSot)
				{
					int sozSot;
					cout << "Выберите кого создать\n 1 - ген.Директор\n 2 - отдел администрации \n 3 - отдел безопасности \n 4 - отдел по работе с клиентами \n 5 - отдел аналитики\n 6 - выйти" << endl;
					cin >> sozSot;
					switch (sozSot)
					{
					case 1:
					{
						string genFIO;
						int genProc;
						cout << "Введите данные ген. Директора в формате\n ФИО \n Процент выполнения плана" << endl;
						cin >> genFIO;
						cin >> genProc;
						genDirector genDir(genProc, genFIO);
						director = &genDir;
						break;
					}
					case 2:
					{
						cout << "Введите количество сотрудников " << endl;
						cin >> countAdmins;
						admnistraciya** admins = new admnistraciya*[countAdmins];
						for (int i = 0; i < countAdmins; i++)
						{
							string adFIO;
							int adProc;
							int adDolj;
							cout << "Введите данные " << i + 1 << " сотрудника в формате\n ФИО \n Процент выполнения плана \n Должность(Stajer - 0, MladhiyManager - 1, Manager - 2, StarshiyManager - 3, NachalnikOtdela - 4)" << endl;
							cin >> adFIO;
							cin >> adProc;
							cin >> adDolj;
							admnistraciya newAdmin(adFIO, adProc, Doljnosti(adDolj));
							admins[i] = &newAdmin;
						}
						adminsNach = admins;
						break;
					}
					case 3:
					{
						cout << "Введите количество сотрудников " << endl;
						cin >> countBezopasniki;
						bezopasnosti** bezopasniki = new bezopasnosti*[countBezopasniki];
						for (int i = 0; i < countBezopasniki; i++)
						{
							string bezFIO;
							int bezProc;
							int procStab;
							int bezDolj;
							cout << "Введите данные " << i + 1 << " сотрудника в формате\n ФИО \n Процент выполнения плана \n Должность(Stajer - 0, MladhiyManager - 1, Manager - 2, StarshiyManager - 3, NachalnikOtdela - 4)\n Процент стабтльности системы" << endl;
							cin >> bezFIO;
							cin >> bezProc;
							cin >> bezDolj;
							cin >> procStab;
							bezopasnosti newbezopasnosti(procStab, bezProc, bezFIO, Doljnosti(bezDolj));
							bezopasniki[i] = &newbezopasnosti;
						}
						bezopasnikiNach = bezopasniki;
						break;
					}
					case 4:
					{
						cout << "Введите количество сотрудников " << endl;
						cin >> countPoRab;
						poRaboteSKlientami** poRab = new poRaboteSKlientami*[countPoRab];
						for (int i = 0; i < countPoRab; i++)
						{
							string poRabFIO;
							int poRabKolZhal;
							int poRabKolKl;
							int poRabProc;
							int poRabDolj;
							cout << "Введите данные " << i + 1 << " сотрудника в формате\n ФИО \n Процент выполнения плана \n Должность(Stajer - 0, MladhiyManager - 1, Manager - 2, StarshiyManager - 3, NachalnikOtdela - 4)\n Количество клиентов \n количество жалоб" << endl;
							cin >> poRabFIO;
							cin >> poRabProc;
							cin >> poRabDolj;
							cin >> poRabKolKl;
							cin >> poRabKolZhal;
							poRaboteSKlientami newPoRab(poRabKolZhal, poRabKolKl, poRabProc, poRabFIO, Doljnosti(poRabDolj));
							poRab[i] = &newPoRab;
						}
						poRabNach = poRab;
						break;
					}
					case 5:
					{
						cout << "Введите количество сотрудников " << endl;
						cin >> countAnalitiki;
						analitiki** ans = new analitiki*[countAnalitiki];
						ansNach = ans;
						for (int i = 0; i < countAnalitiki; i++)
						{
							string anFIO;
							int anProc;
							int anDolj;
							cout << "Введите данные " << i + 1 << " сотрудника в формате\n ФИО \n Должность(Stajer - 0, MladhiyManager - 1, Manager - 2, StarshiyManager - 3, NachalnikOtdela - 4)" << endl;
							cin >> anFIO;
							cin >> anDolj;
							analitiki newAn(anFIO, Doljnosti(anDolj));
							ans[i] = &newAn;
						}
						break;
					}
					case 6: stopSot = 1; break;
					default:
						cout << "Можно выбрать только 1-6" << endl;
						break;
					}
				}
			}
			if (cheloveki == 2)
			{
				stopKl = 0;
				while (!stopKl)
				{
					int sozKl;
					cout << "Выберите кого создать\n 1 - обмен валют\n 2 - потребительские кредиты \n 3 - ипотечные кредиты \n 4 - вклады до востребования \n 5 - срочные вклады \n 6 - выйти" << endl;
					cin >> sozKl;
					switch (sozKl)
					{
					case 1:
					{
						cout << "Введите количество клиентов " << endl;
						cin >> countObmen;
						obmenValut** obmens = new obmenValut*[countObmen];
						for (int i = 0; i < countObmen; i++)
						{
							string obFIO;
							int obKursPok;
							int obKursProd;
							int obKolvoVal;
							cout << "Введите данные " << i + 1 << " клиента в формате\n ФИО \n Курс покупки \n Курс продажи \n Количество валюты " << endl;
							cin >> obFIO;
							cin >> obKursPok;
							cin >> obKursProd;
							cin >> obKolvoVal;
							obmenValut newObmen(obFIO, obKursPok, obKursProd, obKolvoVal);
							obmens[i] = &newObmen;
						}
						obmensNach = obmens;
						break;
					}
					case 2:
					{
						cout << "Введите количество клиентов " << endl;
						cin >> countPotKred;
						potrebitelskieKrediti** potKreds = new potrebitelskieKrediti*[countPotKred];
						for (int i = 0; i < countPotKred; i++)
						{
							string potKrFIO;
							int potKrVozrast;
							bool potKrVbrake;
							int potKrZarplata;
							int potKrSumma;
							int potKredSrok;
							cout << "Введите данные " << i + 1 << " клиента в формате\n ФИО \n Возраст \n Семейное положение(1 - в браке, 0 - не в браке) \n Доход \n Запрашиваемая сумма \n Срок" << endl;
							cin >> potKrFIO;
							cin >> potKrVozrast;
							cin >> potKrVbrake;
							cin >> potKrZarplata;
							cin >> potKrSumma;
							cin >> potKredSrok;
							potrebitelskieKrediti newPotKr(potKrFIO, potKrVozrast, potKrVbrake, potKrZarplata, potKrSumma, potKredSrok);
							potKreds[i] = &newPotKr;
						}
						potKredsNach = potKreds;
						break;
					}
					case 3:
					{
						cout << "Введите количество клиентов " << endl;
						cin >> countIpKred;
						ipotechnieKrediti** ipKreds = new ipotechnieKrediti * [countIpKred];
						for (int i = 0; i < countIpKred; i++)
						{
							string ipKrFIO;
							int ipKrVozrast;
							bool ipKrVbrake;
							int ipKrSumma;
							int ipZarplata;
							int ipKrSrok;
							cout << "Введите данные " << i + 1 << " клиента в формате\n ФИО \n Возраст \n Семейное положение(1 - в браке, 0 - не в браке) \n Доход \n Запрашиваемая сумма \n Срок" << endl;
							cin >> ipKrFIO;
							cin >> ipKrVozrast;
							cin >> ipKrVbrake;
							cin >> ipZarplata;
							cin >> ipKrSumma;
							cin >> ipKrSrok;
							ipotechnieKrediti newIpKr(ipKrFIO, ipKrVozrast, ipKrVbrake, ipZarplata, ipKrSumma, ipKrSrok);
							ipKreds[i] = &newIpKr;
						}
						ipKredsNach = ipKreds;
						break;
					}
					case 4:
					{
						cout << "Введите количество клиентов " << endl;
						cin >> countDoVostr;
						doVostreb** doVostrebs = new doVostreb * [countDoVostr];
						for (int i = 0; i < countDoVostr; i++)
						{
							string doVostrebFIO;
							int doVostrebSumma;
							int doVostrebStavka;
							cout << "Введите данные " << i + 1 << " клиента в формате\n ФИО \n Сумма вклада \n Ставка " << endl;
							cin >> doVostrebFIO;
							cin >> doVostrebSumma;
							cin >> doVostrebStavka;
							doVostreb newDoVostreb(doVostrebFIO, doVostrebSumma, doVostrebStavka);
							doVostrebs[i] = &newDoVostreb;
						}
						doVosrtrebsNach = doVostrebs;
						break;
					}
					case 5:
					{
						cout << "Введите количество клиентов " << endl;
						cin >> countSroch;
						srochnie** srochnies = new srochnie * [countSroch];
						for (int i = 0; i < countSroch; i++)
						{
							string srochFIO;
							int srochSumma;
							int srochbStavka;
							int analiticID;
							int srok;
							cout << "Введите данные " << i + 1 << " клиента в формате\n ФИО \n Сумма вклада \n Ставка \n срок \n Аналитик(1 - "<< countAnalitiki << ")"<< endl;
							cin >> srochFIO;
							cin >> srochSumma;
							cin >> srochbStavka;
							cin >> srok;
							cin >> analiticID;
							srochnie newSrochnie(ansNach[analiticID - 1],srochFIO, srochSumma, srochbStavka, srok);
							srochnies[i] = &newSrochnie;
						}
						srochniesNach = srochnies;
					}
					case 6: stopKl = 1; break;
					default:
					{
						cout << "Можно выбрать только 1-6" << endl;
						break;
					}
					if (cheloveki != 1 && cheloveki != 2)
					{
						cout << "Можно выбрать только 1 и 2" << endl;
						break;
					}
					}
				}
			}
		}
		if (rejimRaboti == 2)
		{
			cout << "Идет подсчёт прибыли" << endl;
			//////////////////////////////////////////////////////////////////////////
			int zarplati = 0;
			zarplati = zarplati + director->getZarplata();
			for (int i = 0; i < countAdmins; i++)
			{
				zarplati = zarplati + adminsNach[i]->getZarplata();
			}
			for (int i = 0; i < countBezopasniki; i++)
			{
				zarplati = zarplati + bezopasnikiNach[i]->getZarplata();
			}
			for (int i = 0; i < countPoRab; i++)
			{
				zarplati = zarplati + poRabNach[i]->getZarplata();
			}
			for (int i = 0; i < countAnalitiki; i++)
			{
				zarplati = zarplati + ansNach[i]->getZarplata();
			}
			/////////////////////////////////////////////////////////////////////////
			int obsProfit = 0;
			for (int i = 0; i < countObmen; i++)
			{
				obsProfit = obsProfit + obmensNach[i]->raschetProfita();
			}
			for (int i = 0; i < countPotKred; i++)
			{
				obsProfit = obsProfit + potKredsNach[i]->raschetProfita();
			}
			for (int i = 0; i < countIpKred; i++)
			{
				obsProfit = obsProfit + ipKredsNach[i]->raschetProfita();
			}
			for (int i = 0; i < countDoVostr; i++)
			{
				obsProfit = obsProfit + doVosrtrebsNach[i]->raschetProfita();
			}
			for (int i = 0; i < countSroch; i++)
			{
				obsProfit = obsProfit + srochniesNach[i]->raschetProfita();
			}
			///////////////////////////////////////////////////////////////////////
			cout << "Общая прибыль составила: " << obsProfit - zarplati << endl;
		}
		if (rejimRaboti == 3)
		{
			return 1;
		}
		if (rejimRaboti != 1 && rejimRaboti != 2 && rejimRaboti != 3)
		{
			cout << "Режим работы может быть только 1, 2 или 3" << endl;
		}
	}
}