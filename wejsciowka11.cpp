#include <string>
#include <iostream>

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
		cout << "Cena auta: " << cena << " zl, rodzaj silnika: " << rodzaj_silnika <<  endl;
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

	Samochod* nowy_s = new Samochod();
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
	delete nowy_u;

	return 0;
}