#include<iostream>
#include<vector>
using namespace std;

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
	//void operator=(Dulciuri &d);
	//char operator[](char index);
	//int Dulciuri::operator+(Dulciuri &d);
	//bool operator!();
	//bool operator ==(Dulciuri dulce);

	friend ostream& operator<<(ostream& out, Dulciuri& d);
	friend istream& operator >> (istream& in, Dulciuri& d);


	virtual void afisarePreturi();
};

Dulciuri::Dulciuri() {
	this->denumirePrajitura = new char[strlen("Nu exista") + 1];
	strcpy(this->denumirePrajitura, "Nu exista");
	this->cantitate = 0;
	this->pretKg = 0.0;
}

Dulciuri::Dulciuri(char* den, int cant, float pret) {
	this->denumirePrajitura = new char[strlen(den) + 1];
	strcpy(this->denumirePrajitura, den);
	this->cantitate = cant;
	this->pretKg = pret;
}

Dulciuri::Dulciuri(char* den, float pret) {
	this->denumirePrajitura = new char[strlen(den) + 1];
	strcpy(this->denumirePrajitura, den);
	this->pretKg = pret;
}

Dulciuri::Dulciuri(Dulciuri& copie) {
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

//void Dulciuri::operator=(Dulciuri &d) {
//	if (d.getDenumire() != NULL)
//	{
//		this->denumirePrajitura = new char[strlen(d.getDenumire()) + 1];
//		strcpy(this->denumirePrajitura, d.getDenumire());
//	}
//	this->cantitate = d.getCantitate();
//	this->pretKg = d.getPret();
//}
//
//char Dulciuri::operator[](char index) {
//	return this->denumirePrajitura[index];
//}
//
//int Dulciuri::operator+(Dulciuri &d) {
//	if (this->cantitate = !d.cantitate)
//		return this->cantitate + d.cantitate;
//	else
//		return this->cantitate + this->cantitate;
//}
//
//bool Dulciuri::operator!() {
//	if (this->pretKg == NULL)
//		return false;
//	else
//		return true;
//}
//
//bool Dulciuri::operator ==(Dulciuri dulce) {
//	if (this->cantitate == dulce.cantitate && this->pretKg == dulce.pretKg && strcmp(this->denumirePrajitura, dulce.denumirePrajitura) == 0)
//		return true;
//	else
//		return false;
//}

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

void Dulciuri::afisarePreturi() {
	cout << "(Apelul functiei din clasa Dulciuri)" << endl;
	if (this->cantitate > 0)
		cout << "Suma totala de plata este: " << this->getPret() << endl;
}


class Tort : public Dulciuri {
public:
	int nrStraturi;
	char* glazura;
	char* forma;

	Tort();
	Tort(int straturi, char* glazura, char* forma, char* denumire, int cant, float pret);

	void afisarePreturi();
};

Tort::Tort() :Dulciuri() {
	this->nrStraturi = 0;
	this->glazura = new char[strlen("Nespecificat") + 1];
	strcpy(this->glazura, "Nespecificat");
	this->forma = new char[strlen("Nespecificat") + 1];
	strcpy(this->forma, "Nespecificat");
}

Tort::Tort(int straturi, char* Glazura, char* Forma, char* denumire, int cant, float pret) :Dulciuri( denumire, cant, pret) {
	this->nrStraturi = straturi;
	this->glazura = new char[strlen(Glazura) + 1];
	strcpy(this->glazura, "Nespecificat");
	this->forma = new char[strlen(Forma) + 1];
	strcpy(this->forma, Forma);
}

void Tort::afisarePreturi() {
	cout << "Preturile din clasa Tort: " << endl;
	this->Dulciuri::afisarePreturi();
}


class Inghetata : public Dulciuri {
public:
	char* aroma;

	Inghetata();
	Inghetata(char * Aroma, char * denumire, int cant, float pret);

	void afisarePreturi();
};

Inghetata::Inghetata() :Dulciuri(){
	this->aroma = new char[strlen("Nespecificat") + 1];
	strcpy(this->aroma, "Nespecificat");
}

Inghetata::Inghetata(char* Aroma, char* denumire, int cant, float pret) :Dulciuri(denumire, cant, pret) {
	this->aroma = new char[strlen(Aroma) + 1];
	strcpy(this->aroma, Aroma);
}

void Inghetata::afisarePreturi() {
	cout << "Preturile din clasa Inghetata: " << endl;
	this->Dulciuri::afisarePreturi();
}

void main() {
	Dulciuri d1("Savarina", 3, 4.5);
	cout << d1.getDenumire() << " " << d1.getPret() << endl;

	Tort t1(3, "Frisca", "Patrat", "Tort Diplomat", 1, 45);
	t1.afisarePreturi();

	Inghetata i1("Capsuni", "Inghetata de capsuni", 4, 12.5);
	i1.afisarePreturi();
}