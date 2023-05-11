#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Samochod {
public:
	double cena;
	string rodzaj_silnika;
	Samochod* nast;

	Samochod() : rodzaj_silnika("benzyna"), cena(10000), nast(NULL) {}
	Samochod(Samochod& nowy) : rodzaj_silnika(nowy.rodzaj_silnika), cena(nowy.cena), nast(NULL) {}
	Samochod(double cena_, string typ) : rodzaj_silnika(typ), cena(cena_), nast(NULL) {}
	~Samochod() {
		delete nast;
	}

	void wypisz() {
		cout << "Cena auta: " << cena << " zl, rodzaj silnika: " << rodzaj_silnika << endl;
	}

	void set_cena(double cena_) {
		cena = cena_;
	}

	double get_cena() {
		return cena;
	}

	void set_rodzaj_silnika(string rodzaj_silnika_) {
		rodzaj_silnika = rodzaj_silnika_;
	}

	string get_rodzaj_silnika() {
		return rodzaj_silnika;
	}
};

class Samochod_osobowy : public Samochod {
protected:
	double pojemnosc_bagaznika;
	char typ;
	
public:
	Samochod_osobowy* nast;
	Samochod_osobowy() : Samochod() {
		pojemnosc_bagaznika = 10;
		typ = 'H';
	}

	Samochod_osobowy(double& cena_, string& rodzaj_silnika_, double& pojemnosc_bagaznika_, char& typ_) : Samochod(cena_, rodzaj_silnika_) {
		pojemnosc_bagaznika = pojemnosc_bagaznika_;
		if (typ != 'H' && typ != 'S' && typ != 'K' && typ != 'V') {
			cout << "Podales niepoprawny typ, uznam ze twoj samochod jest Hatchbackiem" << endl;
			typ = 'H';
		}
		else {
			typ = typ_;
		}
	}
	Samochod_osobowy(Samochod_osobowy& nowy) : Samochod(nowy) {
		pojemnosc_bagaznika = nowy.pojemnosc_bagaznika;
		typ = nowy.typ;
	}

	void wypisz() {
		Samochod::wypisz();
		cout << "Pojemnosc bagaznika: " << pojemnosc_bagaznika << " l, typ: " << typ << endl;
	}

	void set_pojemnosc_bagaznika(double pojemnosc) {
		pojemnosc_bagaznika = pojemnosc;
	}
	double get_pojemnosc_bagaznika() {
		return pojemnosc_bagaznika;
	}

	void set_typ(char typ_) {
		typ = typ_;
	}
	double get_typ() {
		return typ;
	}
};

class Urzadzenie_optyczne {
public:
	double zoom, waga;
	Urzadzenie_optyczne* nast;

	Urzadzenie_optyczne() : zoom(2), waga(1), nast(NULL) {}
	Urzadzenie_optyczne(Urzadzenie_optyczne& nowy) : zoom(nowy.zoom), waga(nowy.waga), nast(NULL) {}
	Urzadzenie_optyczne(double zoom_, double waga_) : zoom(zoom_), waga(waga_), nast(NULL) {}
	~Urzadzenie_optyczne() {
		delete nast;
	}

	void wypisz() {
		cout << "Zoom urzadzenia: " << zoom << "x, waga urzadzenia: " << waga << " kg" << endl;
	}

	void set_zoom(double zoom_) {
		zoom = zoom_;
	}

	double get_zoom() {
		return zoom;
	}

	void set_waga(double waga_) {
		waga = waga_;
	}

	double get_waga() {
		return waga;
	}

};

class Osoba {
public:
	string imie, nazwisko, email;
	Osoba* nast;

	Osoba() : imie("Daniel"), nazwisko("Swiatek"), email("daniel.swiatek@zmyslony_hosting.pl"), nast(NULL) {}
	Osoba(Osoba& nowy) : imie(nowy.imie), nazwisko(nowy.nazwisko), email(nowy.email), nast(NULL) {}
	Osoba(string imie_, string nazwisko_, string email_) : imie(imie_), nazwisko(nazwisko_), email(email_), nast(NULL) {}
	~Osoba() {
		delete nast;
	}

	void wypisz() {
		cout << "Imie i nazwisko: " << imie << " " << nazwisko << ", email: " << email << endl;
	}

	void set_imie(string imie_) {
		imie = imie_;
	}

	string get_imie() {
		return imie;
	}

	void set_nazwisko(string nazwisko_) {
		nazwisko = nazwisko_;
	}

	string get_nazwisko() {
		return nazwisko;
	}

	void set_email(string email_) {
		email = email_;
	}

	string get_email() {
		return email;
	}

};

int main() {

	/*Samochod* nowy_s = new Samochod();
	Samochod* aktualny_s = nowy_s;

	for (int i = 0; i < 4; i++) {
		aktualny_s->nast = new Samochod();
		aktualny_s = aktualny_s->nast;
	}

	Urzadzenie_optyczne* nowy_u = new Urzadzenie_optyczne();
	Urzadzenie_optyczne* aktualny_u = nowy_u;

	for (int i = 0; i < 4; i++) {
		aktualny_u->nast = new Urzadzenie_optyczne();
		aktualny_u = aktualny_u->nast;
	}

	Osoba* nowy_o = new Osoba();
	Osoba* aktualny_o = nowy_o;

	for (int i = 0; i < 4; i++) {
		aktualny_o->nast = new Osoba();
		aktualny_o = aktualny_o->nast;
	}

	cout << "Elementy listy samochodow: " << endl;

	aktualny_s = nowy_s;
	while (aktualny_s != NULL) {
		aktualny_s->wypisz();
		aktualny_s = aktualny_s->nast;
	}

	cout << "Elementy listy urzadzen optycznych: " << endl;

	aktualny_u = nowy_u;
	while (aktualny_u != NULL) {
		aktualny_u->wypisz();
		aktualny_u = aktualny_u->nast;
	}

	cout << "Elementy listy osob: " << endl;

	aktualny_o = nowy_o;
	while (aktualny_o != NULL) {
		aktualny_o->wypisz();
		aktualny_o = aktualny_o->nast;
	}

	delete nowy_s;
	delete nowy_o;
	delete nowy_u;*/

	Samochod_osobowy* nowy = new Samochod_osobowy();
	Samochod_osobowy* aktualny = nowy;
	char czy_dalej = 't';
	do{
		double cena, pojemnosc;
		char typ;
		string silnik;
		cout << "Podaj cene samochodu: " << endl;
		cin >> cena;
		aktualny->set_cena(cena);
		cout << "Podaj pojemnosc bagaznika: " << endl;
		cin >> pojemnosc;
		aktualny->set_pojemnosc_bagaznika(pojemnosc);
		cout << "Podaj typ nadwozia: " << endl;
		cin >> typ;
		toupper(typ);
		aktualny->set_typ(typ);
		cout << "Podaj rodzaj silnika: " << endl;
		cin >> silnik;
		aktualny->set_rodzaj_silnika(silnik);
		cout << "Czy chcesz dodac kolejny pojazd?" << endl;
		aktualny->wypisz();
		cin >> czy_dalej;
		
		aktualny->nast = new Samochod_osobowy();
		aktualny = aktualny->nast;
	} while (czy_dalej == 't');



	return 0;
}