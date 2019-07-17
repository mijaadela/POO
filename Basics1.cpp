#include<iostream>
using namespace std;

class Cofetarie {
private:
	char* denumire;
	char* adresa;
	const char CIF[8];
public:

	Cofetarie();
	Cofetarie(char* den, char* ad);
	Cofetarie(Cofetarie& copie);
	~Cofetarie();

	//metode de acces
	char* getDenumire();
	char* getAdresa();
	char getCIF();
	void setDenumire(char* den);
	void setAdresa(char* adresa);

	//operatori
	void operator=(Cofetarie &c);

	char operator[](char index);
	Cofetarie operator +(Cofetarie c);
	bool operator!();
	bool operator ==(Cofetarie cofet);
	Cofetarie& operator++(); //forma prefixata
	Cofetarie operator++(int); //forma postfixata


	friend ostream& operator<<(ostream& out, Cofetarie& c);
	friend istream& operator >> (istream& in, Cofetarie& c);
};

Cofetarie::Cofetarie() :CIF("000000") {
	this->denumire = new char[strlen("Necunoscuta") + 1];
	strcpy(this->denumire, "Necunoscuta");
	this->adresa = new char[strlen("Necunoscuta") + 1];
	strcpy(this->adresa, "Necunoscuta");
}

Cofetarie::Cofetarie(char* den, char* ad):CIF("1111111") {
	this->denumire = new char[strlen(den) + 1];
	strcpy(this->denumire, den);
	this->adresa = new char[strlen(ad) + 1];
	strcpy(this->adresa, ad);
}

Cofetarie::Cofetarie(Cofetarie& copie):CIF("1111111") {
	if (copie.denumire != NULL)
	{
		delete[] this->denumire;
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(this->denumire, copie.denumire);
	}
	if (copie.adresa != NULL)
	{
		delete[] this->adresa;
		this->adresa = new char[strlen(copie.adresa) + 1];
		strcpy(this->adresa, copie.adresa);
	}
}

Cofetarie::~Cofetarie() {
	if (this->denumire != NULL)
		delete[] this->denumire;
	if (this->adresa != NULL)
		delete[] this->adresa;
}

char* Cofetarie::getDenumire() {
	return this->denumire;
}

char* Cofetarie::getAdresa() {
	return this->adresa;
}

char Cofetarie::getCIF() {
	return this->CIF[8];
}

void Cofetarie::setDenumire(char* den) {
	if (this->denumire != NULL)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
	}
}

void Cofetarie::setAdresa(char* adresa) {
	if (this->adresa != NULL)
	{
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
	}
}

void Cofetarie::operator=(Cofetarie &c) {
	if (c.getDenumire() != NULL)
	{
		this->denumire = new char[strlen(c.getDenumire()) + 1];
		strcpy(this->denumire, c.getDenumire());
	}
	if (c.getAdresa() != NULL)
	{
		this->adresa = new char[strlen(c.getAdresa()) + 1];
		strcpy(this->adresa, c.getAdresa());
	}
}

char Cofetarie::operator[](char index) {
	return this->adresa[index];
}

Cofetarie Cofetarie::operator +(Cofetarie c) {
	Cofetarie copie = *this;
	char* adresaN = strcat(this->adresa, ", nr ");
	strcat(adresaN, c.adresa);
	strcpy(copie.adresa, adresaN);
	return copie;
}

bool Cofetarie::operator!() {
	if (this->adresa == NULL)
		return false;
	else
		return true;
}

bool Cofetarie::operator ==(Cofetarie cofet) {
	if (strcmp(this->adresa, cofet.adresa) == 0 && strcmp(this->denumire, cofet.denumire) == 0)
		return true;
	else
		return false;
}

Cofetarie& Cofetarie::operator++() {
	char* nou = new char[strlen(this->denumire) + 1];
	if (this->denumire != NULL)
		delete[] this->denumire;
	strcpy(this->denumire, nou);
	return *this;
}

Cofetarie Cofetarie::operator++(int) {
	Cofetarie copie = *this;
	//..
	return copie;
}

ostream& operator<<(ostream& out, Cofetarie& c) {
	out << "Denumirea cofetariei este " << c.denumire << " situata la adresa: " << c.adresa << endl;
	return out;
}

istream& operator >> (istream& in, Cofetarie& c) {
	char bufferDenumire[100];
	cout << "Introduceti denumirea cofetariei: ";
	in >> bufferDenumire;
	c.denumire = new char[strlen(bufferDenumire) + 1];
	strcpy(c.denumire, bufferDenumire);
	char bufferAdresa[300];
	cout << "Introduceti adresa cofetariei: ";
	in >> bufferAdresa;
	c.adresa = new char[strlen(bufferAdresa) + 1];
	strcpy(c.adresa, bufferAdresa);

	return in;
}



class Dulciuri {
private:
	char* denumirePrajitura;
	int cantitate;
	float pretKg;
public:
	Dulciuri();
	Dulciuri(char* den, int cant, float pret);
	Dulciuri(char* den, float pret);
	Dulciuri(Dulciuri &d);
	~Dulciuri();

	//metode de acces
	char* getDenumire();
	int getCantitate();
	float getPret();
	void setDenumire(char* den);
	void setCantitate(int cant);
	void setPret(float pret);

	//operatori
	void operator=(Dulciuri &d);
	char operator[](char index);
	int Dulciuri::operator+(Dulciuri &d);
	bool operator!();
	bool operator ==(Dulciuri dulce);


	friend ostream& operator<<(ostream& out, Dulciuri& d);
	friend istream& operator >> (istream& in, Dulciuri& d);
};

Dulciuri::Dulciuri(){
	this->denumirePrajitura = new char[strlen("Nu exista") + 1];
	strcpy(this->denumirePrajitura, "Nu exista");
	this->cantitate = 0;
	this->pretKg = 0.0;
}

Dulciuri::Dulciuri(char* den, int cant, float pret){
	this->denumirePrajitura = new char[strlen(den) + 1];
	strcpy(this->denumirePrajitura, den);
	this->cantitate = cant;
	this->pretKg = pret;
}

Dulciuri::Dulciuri(char* den, float pret){
	this->denumirePrajitura = new char[strlen(den) + 1];
	strcpy(this->denumirePrajitura, den);
	this->pretKg = pret;
}

Dulciuri::Dulciuri(Dulciuri& copie){
	if (copie.denumirePrajitura != NULL)
	{
		delete[] this->denumirePrajitura;
		this->denumirePrajitura = new char[strlen(copie.denumirePrajitura) + 1];
		strcpy(this->denumirePrajitura, copie.denumirePrajitura);
	}
	this->cantitate = copie.cantitate;
	this->pretKg = copie.pretKg;
}

Dulciuri::~Dulciuri() {
	if (this->denumirePrajitura != NULL)
		delete[] this->denumirePrajitura;
}

char* Dulciuri::getDenumire() {
	return this->denumirePrajitura;
}

int Dulciuri::getCantitate() {
	return this->cantitate;
}

float Dulciuri::getPret() {
	return this->pretKg;
}

void Dulciuri::setDenumire(char* den) {
	if (this->denumirePrajitura != NULL)
	{
		this->denumirePrajitura = new char[strlen(den) + 1];
		strcpy(this->denumirePrajitura, den);

	}
}

void Dulciuri::setCantitate(int cant) {
	if (this->cantitate > 0)
		this->cantitate = cant;
}

void Dulciuri::setPret(float pret) {
	if (this->pretKg > 0)
		this->pretKg = pret;
}

void Dulciuri::operator=(Dulciuri &d) {
	if (d.getDenumire() != NULL)
	{
		this->denumirePrajitura = new char[strlen(d.getDenumire()) + 1];
		strcpy(this->denumirePrajitura, d.getDenumire());
	}
	this->cantitate = d.getCantitate();
	this->pretKg = d.getPret();
}

char Dulciuri::operator[](char index) {
	return this->denumirePrajitura[index];
}

int Dulciuri::operator+(Dulciuri &d) {
	if (this->cantitate =! d.cantitate)
		return this->cantitate + d.cantitate;
	else
		return this->cantitate + this->cantitate;
}

bool Dulciuri::operator!() {
	if (this->pretKg == NULL)
		return false;
	else
		return true;
}

bool Dulciuri::operator ==(Dulciuri dulce) {
	if (this->cantitate == dulce.cantitate && this->pretKg == dulce.pretKg && strcmp(this->denumirePrajitura, dulce.denumirePrajitura) == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Dulciuri& d) {
	out << "Denumirea prajiturii este " << d.denumirePrajitura << " Are pretul: " << d.pretKg << " si s-au cumparat: " << d.cantitate << " bucati." << endl;
	return out;
}

istream& operator >> (istream& in, Dulciuri& d) {
	char bufferDenumire[100];
	cout << "Introduceti denumirea prajiturii: ";
	in >> bufferDenumire;
	d.denumirePrajitura = new char[strlen(bufferDenumire) + 1];
	strcpy(d.denumirePrajitura, bufferDenumire);
	cout << "Introduceti pretul:";
	in >> d.pretKg;
	cout << "Introduceti cantitatea:";
	in >> d.cantitate;
	return in;
}



class Utilitati {
private:
	char numeServicii[10];
	float pretFactura;
	char* bunuriMateriale;
	static int luniAmortizare;
public:
	Utilitati();
	Utilitati(char servicii[10], float pret, char* bunuri);
	Utilitati(char servicii[10], float pret);
	Utilitati(Utilitati &copie);
	~Utilitati();

	//metode de acces
	char getServicii();
	float getSuma();
	char* getBunuri();
	int getAmortizare();
	void setServicii(char serv[10]);
	void setSuma(float suma);
	void setBunuri(char* bunuri);
	void setAmortizare(int amortizare);

	//operatori
	void operator=(Utilitati &u);
	char operator[](char index);
	friend Utilitati operator-(Utilitati u, float p);
	bool operator!();
	bool operator ==(Utilitati util);

	friend ostream& operator<<(ostream& out, Utilitati& u);
	friend istream& operator >> (istream& in, Utilitati& u);
};

int Utilitati::luniAmortizare = 0;

Utilitati::Utilitati() {
	strcpy(this->numeServicii, "Necunoscute");
	this->pretFactura = 0.0;
	this->bunuriMateriale = new char[strlen("Necunoscute") + 1];
	strcpy(this->bunuriMateriale, "Necunoscute");
	this->luniAmortizare++;
}

Utilitati::Utilitati(char servicii[10], float pret, char* bunuri){
	strcpy(this->numeServicii, servicii);
	this->pretFactura = 0.0;
	this->bunuriMateriale = new char[strlen(bunuri) + 1];
	strcpy(this->bunuriMateriale, bunuri);
	this->luniAmortizare++;
}

Utilitati::Utilitati(char servicii[10], float pret) {
	strcpy(this->numeServicii, servicii);
	this->pretFactura = 0.0;
	this->luniAmortizare++;
}

Utilitati::Utilitati(Utilitati &copie) {
	if (copie.numeServicii != NULL)
	{
		delete[] this->numeServicii;
		strcpy(this->numeServicii, copie.numeServicii);
	}
	this->pretFactura = copie.pretFactura;
	if (copie.bunuriMateriale != NULL)
	{
		delete[] this->bunuriMateriale;
		this->bunuriMateriale = new char[strlen(copie.bunuriMateriale) + 1];
		strcpy(this->bunuriMateriale, copie.bunuriMateriale);
	}
	this->luniAmortizare++;
}

Utilitati::~Utilitati(){
	if (this->bunuriMateriale != NULL)
		delete[] this->bunuriMateriale;
	this->luniAmortizare--;
}

char Utilitati::getServicii() {
	return this->numeServicii[10];
}

float Utilitati::getSuma() {
	return this->pretFactura;
}

char* Utilitati::getBunuri() {
	return this->bunuriMateriale;
}

int Utilitati::getAmortizare() {
	return this->luniAmortizare;
}

void Utilitati::setServicii(char serv[10]) {
	if (this->numeServicii != NULL)
		strcpy(this->numeServicii, serv);
}

void Utilitati::setSuma(float suma) {
	if(this->pretFactura > 0)
		this->pretFactura = suma;
}

void Utilitati::setBunuri(char* bunuri) {
	if (this->bunuriMateriale != NULL)
	{
		this->bunuriMateriale = new char[strlen(bunuri) + 1];
		strcpy(this->bunuriMateriale, bunuri);
	}
}

void Utilitati::setAmortizare(int amortizare) {
	if (this->luniAmortizare > 0)
		this->luniAmortizare = amortizare;
}

void Utilitati::operator=(Utilitati &u) {
	this->pretFactura = u.getSuma();
	if (u.getBunuri() != NULL)
	{
		this->bunuriMateriale = new char[strlen(u.getBunuri()) + 1];
		strcpy(this->bunuriMateriale, u.getBunuri());
	}
	this->luniAmortizare = u.getAmortizare();
}

char Utilitati::operator[](char index) {
	return this->bunuriMateriale[index];
}

Utilitati operator-(Utilitati u, float p) {
	Utilitati copie = u;
	copie.pretFactura -= p;
	return copie;
}

bool Utilitati::operator!() {
	if (this->luniAmortizare == NULL)
		return false;
	else
		return true;
}

bool Utilitati::operator ==(Utilitati util) {
	if (this->pretFactura == util.pretFactura )
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Utilitati& u) {
	out << "Factura contine serviciile: " << u.numeServicii << " si are valoarea: " << u.pretFactura << " Utilajele folosite sunt: " << u.bunuriMateriale << " care se amortizeaza si in luna: " << u.luniAmortizare << endl;
	return out;
}

istream& operator >> (istream& in, Utilitati& u) {
	char bufferServicii[100];
	cout << "Introduceti serviciile: ";
	in >> bufferServicii;
	strcpy(u.numeServicii, bufferServicii);
	cout << "Introduceti pretul facturii:";
	in >> u.pretFactura;
	char bufferBunuri[100];
	cout << "Introduceti utilajele: ";
	in >> bufferBunuri;
	u.bunuriMateriale = new char[strlen(bufferBunuri) + 1];
	strcpy(u.bunuriMateriale, bufferBunuri);
	cout << "Luna amortizare:";
	in >> u.luniAmortizare;
	return in;
}

class Alimente {
private:
	char* denumire;
	int cantitate;
	float pret;
public:
	Alimente();
	Alimente(char* den, int cant, float p);
	Alimente(Alimente &copie);
	~Alimente();

	//metode de acces
	char* getDenumire();
	int getCantitate();
	float getPret();
	void setDenumire(char* den);
	void setCantitate(int cant);
	void setPret(float pret);

};

Alimente::Alimente() {
	this->denumire = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumire, "Necunoscut");
	this->cantitate = 0;
	this->pret = 0;
}

Alimente::Alimente(char* den, int cant, float p) {
	this->denumire = new char[strlen(den) + 1];
	strcpy(this->denumire, den);
	this->cantitate = cant;
	this->pret = p;
}

Alimente::Alimente(Alimente &copie) {
	if (copie.denumire != NULL)
	{
		delete[] this->denumire;
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(this->denumire, copie.denumire);
	}
	this->cantitate = copie.cantitate;
	this->pret = copie.pret;
}

Alimente::~Alimente(){
	if(this->denumire != NULL)
		delete[] this->denumire;
}

char* Alimente::getDenumire() {
	return this->denumire;
}

int Alimente::getCantitate() {
	return this->cantitate;
}

float Alimente::getPret() {
	return this->pret;
}

void Alimente::setDenumire(char* den) {
	if (this->denumire != NULL)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
	}
}

void Alimente::setCantitate(int cant) {
	this->cantitate = cant;
}

void Alimente::setPret(float pret) {
	this->pret = pret;
}



class Personal {
private:
	const char* CNP;
	float salariu;
	char* nume_prenume;
	char bonus[5];
public:
	Personal();
	Personal(char* cnp, float salariu, char* nume, char bonus[10]);
	Personal(char* cnp, float salariu, char* nume);
	Personal(Personal &copie);
	~Personal();

	//metode de acces
	//const char* getCNP();
	float getSalariu();
	char* getNume();
	char getBonus();
	void setSalariu(float sal);
	void setNume(char* nume);
	void setBonus(char bonus[5]);

	//operatori
	void operator=(Personal &p);
	char operator[](char index);
	float operator+(Personal &p);
	bool operator!();
	bool operator ==(Personal pers);

	friend ostream& operator<<(ostream& out, Personal& p);
	friend istream& operator >> (istream& in, Personal& p);
};

Personal::Personal() :CNP("2940201464545") {
	this->salariu = 0;
	this->nume_prenume = new char[strlen("Anonim") + 1];
	strcpy(this->nume_prenume, "Anonim");
	strcpy(this->bonus, "Nu exista");
}

Personal::Personal(char* cnp, float salariu, char* nume, char bonus[10]):CNP(cnp){
	this->salariu = salariu;
	this->nume_prenume = new char[strlen(nume) + 1];
	strcpy(this->nume_prenume, nume);
	strcpy(this->bonus, bonus);
}

Personal::Personal(char* cnp, float salariu, char* nume) :CNP(cnp) {
	this->salariu = salariu;
	this->nume_prenume = new char[strlen(nume) + 1];
	strcpy(this->nume_prenume, nume);
}

Personal::Personal(Personal &copie):CNP(copie.CNP) {
	this->salariu = copie.salariu;
	if (this->nume_prenume != NULL)
	{
		delete[] this->nume_prenume;
		this->nume_prenume = new char[strlen(copie.nume_prenume) + 1];
		strcpy(this->nume_prenume, copie.nume_prenume);
	}
	strcpy(this->bonus, copie.bonus);
}

Personal::~Personal() {
	if (this->nume_prenume != NULL)
		delete[] this->nume_prenume;
}

float Personal::getSalariu() {
	return this->salariu;
}

char* Personal::getNume() {
	return this->nume_prenume;
}

char Personal::getBonus() {
	return this->bonus[5];
}

void Personal::setSalariu(float sal) {
	if (this->salariu > 0)
		this->salariu = sal;
}

void Personal::setNume(char* nume) {
	if (this->nume_prenume != NULL)
	{
		this->nume_prenume = new char[strlen(nume) + 1];
		strcpy(this->nume_prenume, nume);
	}
}

void Personal::setBonus(char bonus[5]){
	if (this->bonus != NULL)
		strcpy(this->bonus, bonus);
}

void Personal::operator=(Personal &p) {
	this->salariu = p.getSalariu();
	if (p.getNume() != NULL)
	{
		this->nume_prenume = new char[strlen(p.getNume()) + 1];
		strcpy(this->nume_prenume, p.getNume());
	}
	strcpy(this->bonus, p.bonus);
}

float Personal::operator+(Personal &p) {
	if (this->salariu < p.salariu)
		return this->salariu + 10;
	else
		return this->salariu;
}

char Personal::operator[](char index) {
	return this->nume_prenume[index];
}

bool Personal::operator!() {
	if (this->salariu == NULL)
		return false;
	else
		return true;
}

bool Personal::operator ==(Personal pers) {
	if (this->salariu == pers.salariu && strcmp(this->nume_prenume, pers.nume_prenume) == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Personal& p) {
	out << "Salariatul: " << p.nume_prenume << " cu CNP-ul: " << p.CNP << " are salariul: " << p.salariu << " si a primit un nr de " << p.bonus << " bonus-uri" << endl;
	return out;
}

istream& operator >> (istream& in, Personal& p) {
	cout << "Introduceti salariul:";
	in >> p.salariu;
	char bufferNume[100];
	cout << "Introduceti nume salatiat: ";
	in >> bufferNume;
	strcpy(p.nume_prenume, bufferNume);
	char Bonus[100];
	cout << "Introduceti bonus-ul: ";
	in >> Bonus;
	strcpy(p.bonus, Bonus);
	return in;
}

void main() {
	Cofetarie c1;
	cout << c1;
	Cofetarie c2("Mar-Vio", "Str. Viitorului");
	if (c1.getAdresa() == c2.getAdresa())
		cout << "Cofetariile sunt una si acceasi" << endl;
	else
		cout << "Nu este vorba de acceasi cofetarie" << endl;

	Dulciuri d1;
	cin >> d1;

	Utilitati u1("Electricitate, Gaze", 240, "Cuptor");
	Utilitati u3;
	u3 = u1;
	cout << u3 << endl;

	Alimente a2("Faina", 20, 30);
	cout << a2.getDenumire() << endl;

	Personal p1;
	cin >> p1;
	cout << "Noul salariu: " << p1.getSalariu() + 20;
}