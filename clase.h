class Exceptie :public std::exception {
public:
	virtual const char* what() const noexcept override
	{
		return "Exista o eroare!";
	}
};
class CnpInvalid : public Exceptie {
public:
virtual const char* what() const noexcept override
	{
		return "CNP invalid";
	}
};
class NumarTelefonInvalid : public Exceptie {
public:
virtual const char* what() const noexcept override
	{
		return "Numar de telefon invalid";
	}
};

class Abonament {
public:
	Abonament() {/* cout << "Constructor Default Abonament\n";*/ }
	~Abonament() { /*cout << "Destructor Default Abonament\n";*/ }
	Abonament(std::string _nume_abonament, float _pret, int _perioada) {
		//cout << "Constructor cu parametru Abonament\n";
		nume_abonament = _nume_abonament;
		pret = _pret;
		perioada = _perioada;
	}
	Abonament(const Abonament& a) {
		nume_abonament = a.nume_abonament;
		pret = a.pret;
		perioada = a.perioada;
		//cout << "Constructor de copiere Abonament\n";
	}
	//supraincarcarea operatorului =
	Abonament& operator=(const Abonament& a) {
		nume_abonament = a.nume_abonament;
		pret = a.pret;
		perioada = a.perioada;
		return *this;
	}
	//getter nume
	std::string get_nume_abonament() {
		return nume_abonament;
	}
	//getter pret
	float get_pret() {
		return pret;
	}
	//getter perioada
	int get_perioada() {
		return perioada;
	}

	//setter  nume
	void set_nume_abonament(std::string _nume_abonament) {
		nume_abonament = _nume_abonament;
	}
	//setter pret
	void set_pret(float _pret) {
		pret = _pret;
	}
	//setter perioada
	void set_perioada(int _perioada) {
		perioada = _perioada;
	}

	//functie virtuala pura
	virtual void afisare();
	//functie virtuala pura
	virtual void citire();
protected:
	std::string nume_abonament;
	float pret;
	int perioada;
};

class Abonament_Premium : public Abonament {
public:
	Abonament_Premium() { /*cout << "Constructor Default Abonament_Premium\n";*/ }
	~Abonament_Premium() { /*cout << "Destructor Default Abonament_Premium\n";*/ }
	//constructor cu parametrii
	Abonament_Premium(std::string _nume_abonament, float _pret, int _perioada, int _reducere) :Abonament(_nume_abonament, _pret, _perioada) {
		//cout << "Constructor cu parametru Abonament_Premium\n";
		reducere = _reducere;
	}
	Abonament_Premium(int _reducere,Abonament& a) :Abonament(a){
		reducere = _reducere;	
		//cout << "Constructor cu parametru Abonament_Premium\n";
	}
	//constructor de copiere
	Abonament_Premium(const Abonament_Premium& a) {
		reducere = a.reducere;
		//cout << "Constructor de copiere Abonament_Premium\n";
	}
	
	//supraincarcarea operatorului =
	Abonament_Premium& operator=(const Abonament_Premium& a) {
		Abonament::operator=(a);
		reducere = a.reducere;
		return *this;
	}
	
	//getter reducere
	int get_reducere() {
		return reducere;
	}
	//setter reducere
	void set_reducere(int _reducere) {
		reducere = _reducere;
	}
	//functie virtuala de afisare
	void afisare();
	//functie virtuala de citire
	void citire();
	
private:
	int reducere;
};

class Persoana {
public:
	Persoana() {/* cout << "Constructor Default Persoana\n";*/ }
	~Persoana() {/* cout << "Destructor Default Persoana\n";*/ }
	Persoana(int _id, std::string _nume, std::string _cnp) {
		//cout << "Constructor cu parametru Persoana\n";
		id = _id;
		nume = _nume;
		
		if(_cnp.length()!=13)
			throw Exceptie();
		cnp = _cnp;
	}
	Persoana(const Persoana& p) {
		id = p.id;
		nume = p.nume;
		cnp = p.cnp;
		//cout << "Constructor de copiere Persoana\n";
	}
	//supraincarcarea operatorului =
	Persoana& operator=(const Persoana& p) {
		id = p.id;
		nume = p.nume;
		if (p.cnp.length() != 13)
			throw Exceptie();
		cnp = p.cnp;
		return *this;
	}
	//getter id
	int get_id() {
		return id;
	}
	//getter nume
	std::string get_nume() {
		return nume;
	}
	//getter cnp
	std::string get_cnp() {
		return cnp;
	}
	//setter id
	void set_id(int _id) {
		id = _id;
	}
	//setter nume
	void set_nume(std::string _nume) {
		nume = _nume;
	}
	//setter cnp
	void set_cnp(std::string _cnp) {
		if (_cnp.length() != 13)
			throw Exceptie();
		cnp = _cnp;
	}
	//functie virtuala de citire
	virtual void citire();
	//functie virtuala de afisare
	virtual void afisare();
	
private:
	int id;
	std::string nume;
	std::string cnp;
};

class Abonat : public Persoana {
public:
	Abonat() { /*cout << "Constructor Default Abonat\n";*/ }
	~Abonat() {
		/*cout << "Destructor Default Abonat\n"; */}
	//constructor cu parametrii
	Abonat(std::string _nr_telefon, std::string _nume_abonament, float _pret, int _perioada ,int _id, std::string _nume, std::string _cnp):Persoana(_id,_nume,_cnp) {
		//cout << "Constructor cu parametru Abonat\n";
		nr_telefon = _nr_telefon;
		if (_nr_telefon.size()!=10)
			throw Exceptie();
		x =  new Abonament(_nume_abonament, _pret, _perioada);
	}
	Abonat(std::string _nr_telefon, std::string _nume_abonament, float _pret, int _perioada, Persoana& p):Persoana(p) {
		//cout << "Constructor cu parametru Abonat\n";
		nr_telefon = _nr_telefon;
		if (_nr_telefon.size() != 10)
			throw Exceptie();
		x = new Abonament(_nume_abonament, _pret, _perioada);
	}
	Abonat(std::string _nr_telefon, Abonament& a, Persoana& p) :Persoana(p) {
		//cout << "Constructor cu parametru Abonat\n";
		if (_nr_telefon.size() != 10)
			throw Exceptie();
		nr_telefon = _nr_telefon;
		x = &a;
	}
	//constructor de copiere
	Abonat(const Abonat& a) :Persoana(a), x(a.x) {
		nr_telefon = a.nr_telefon;
		//cout << "Constructor de copiere Abonat\n";
	}
	//supraincarcarea operatorului =
	Abonat& operator=(const Abonat& a) {
		Persoana::operator=(a);
		nr_telefon = a.nr_telefon;
		x = a.x;
		return *this;
	}
	 
	//getter nr_telefon	
	std::string getNrTelefon() const{
		return nr_telefon;
	}
	//getter abonament
	Abonament* getAbonament(){
		return x;
	}

	
	//setter
	void setNrTelefon(const std::string _nr_telefon) {
		
		if (_nr_telefon.size() != 10)
			throw Exceptie();
		nr_telefon = _nr_telefon;
	}
	//functie virtuala de citire
	void citire();
	//functie virtuala de afisare
	void afisare();
	


protected:
	std::string nr_telefon;
	Abonament* x;
};


//class Abonat : public Persoana {
//public:
//	Abonat() : x(nullptr) { /*cout << "Constructor Default Abonat\n";*/ }
//	~Abonat() { delete x; /*cout << "Destructor Default Abonat\n";*/ }
//	//constructor cu parametrii
//	Abonat(std::string _nr_telefon, std::string _nume_abonament, float _pret, int _perioada, int _id, std::string _nume, std::string _cnp)
//		: Persoana(_id, _nume, _cnp), x(new Abonament(_nume_abonament, _pret, _perioada)) {
//		//cout << "Constructor cu parametru Abonat\n";
//		nr_telefon = _nr_telefon;
//		if (_nr_telefon.size() != 10)
//			throw Exceptie();
//	}
//	Abonat(std::string _nr_telefon, std::string _nume_abonament, float _pret, int _perioada, Persoana& p)
//		: Persoana(p), x(new Abonament(_nume_abonament, _pret, _perioada)) {
//		//cout << "Constructor cu parametru Abonat\n";
//		nr_telefon = _nr_telefon;
//		if (_nr_telefon.size() != 10)
//			throw Exceptie();
//	}
//	Abonat(std::string _nr_telefon, Abonament_Premium& a, Persoana& p)
//		: Persoana(p), x(new Abonament_Premium(a)) {
//		//cout << "Constructor cu parametru Abonat\n";
//		if (_nr_telefon.size() != 10)
//			throw Exceptie();
//		nr_telefon = _nr_telefon;
//	}
//	//constructor de copiere
//	Abonat(const Abonat& a) : Persoana(a), x(a.x ? new Abonament(*a.x) : nullptr) {
//		nr_telefon = a.nr_telefon;
//		//cout << "Constructor de copiere Abonat\n";
//	}
//	//supraincarcarea operatorului =
//	Abonat& operator=(const Abonat& a) {
//		Persoana::operator=(a);
//		nr_telefon = a.nr_telefon;
//		delete x;
//		x = a.x ? new Abonament(*a.x) : nullptr;
//		return *this;
//	}
//
//	//getter nr_telefon
//	std::string getNrTelefon() const {
//		return nr_telefon;
//	}
//	//getter abonament
//	Abonament* getAbonament() {
//		return x;
//	}
//
//	//setter
//	void setNrTelefon(const std::string _nr_telefon) {
//
//		if (_nr_telefon.size() != 10)
//			throw Exceptie();
//		nr_telefon = _nr_telefon;
//	}
//	//functie virtuala de citire
//	void citire();
//	//functie virtuala de afisare
//	void afisare();
//
//protected:
//	std::string nr_telefon;
//	Abonament* x;
//};

class Clienti {
public:
	Clienti() { /*cout << "Constructor Default Clienti";*/ }
	~Clienti() {/* cout << "Destructor Default Clienti";*/ }
	//constructor cu parametrii
	Clienti(std::vector <std::shared_ptr<Abonat>> _client) {
		//cout << "Constructor cu parametru Clienti\n";
		client = _client;
	}
	//constructor de copiere
	Clienti(const Clienti& c) {
		client = c.client;
		//cout << "Constructor de copiere Clienti\n";
	}
	//getter
	std::vector <std::shared_ptr<Abonat>> getClient() {
		return client;
	}
	//functie de adaugare abonat
	void adaugaAbonat(Abonat& _Abonat) {
		client.push_back(std::make_unique<Abonat>(_Abonat));
	}
	//functie de stergere ultimul abonat
	void stergeAbonat() {
		client.pop_back();
	}
	//functie de afisare a tuturor abonatilor
	void afisare() {
		for (auto c = client.begin(); c != client.end(); c++)
			(*c)->afisare();
	}

	int numar_abonati_premium() {
		int numar = 0;
		for (int i = 0; i < client.size();i++) {
			if (dynamic_cast<Abonament_Premium*>(client[i]->getAbonament())) {
				numar++;
			}
		}
		return numar;
	}

	float suma_totala() {
		float suma = 0;
		for (int i = 0; i < client.size(); i++) {
			if (dynamic_cast<Abonament_Premium*>(client[i]->getAbonament())) {
				Abonament_Premium* abonament_premium = dynamic_cast<Abonament_Premium*>(client[i]->getAbonament());
				suma += ((abonament_premium->get_pret()) * (abonament_premium->get_perioada())) - (abonament_premium->get_reducere());
			}
			else {
				suma += (client[i]->getAbonament()->get_pret())*(client[i]->getAbonament()->get_perioada());
			}
		}
		return suma;
	}

private:
	std::vector <std::shared_ptr<Abonat>>client;
};





//functie virtuala de citire
void Abonament::citire() {
	std::cout << "Nume Abonament:\n";
	std::cin >> nume_abonament;
	std::cout << "Pret:\n";
	std::cin >> pret;
	std::cout << "Perioada:\n";
	std::cin >> perioada;
}
//functie virtuala de afisare
void Abonament::afisare() {
	std::cout << "Nume Abonament:" << nume_abonament << '\n';
	std::cout << "Pret:" << pret << '\n';
	std::cout << "Perioada:" << perioada << '\n';
}
void Abonament_Premium::afisare() {
	Abonament::afisare();
	std::cout << "Reducere:" << reducere << '\n';
}
//functie virtuala de citire
void Abonament_Premium::citire() { 
	Abonament::citire();
	std::cout << "Reducere:\n";
	std::cin >> reducere;
}
//functie virtuala de citire
void Persoana::citire() {
	std::cout << "Id:\n";
	std::cin >> id;
	std::cout << "Nume:\n";
	std::cin >> nume;
	std::cout << "CNP:\n";
	std::cin >> cnp;
	if (cnp.size() != 13) {
		//cout << "CNP invalid\n";
		throw CnpInvalid();
	}
}
//functie virtuala de afisare
void Persoana::afisare() {
	std::cout << "Id: " << id << "\n";
	std::cout << "Nume: " << nume << "\n";
	std::cout << "CNP: " << cnp << "\n";
}
//functie virtuala de citire
void Abonat::citire() {
	Persoana::citire();
	std::cout << "Numar Telefon:\n";
	std::cin >> nr_telefon;
	if (nr_telefon.size() != 10) {
		throw NumarTelefonInvalid();
	}
	if(x==nullptr)
		x = new Abonament();
	x->citire();
}
//functie virtuala de afisare
void Abonat::afisare() {
	Persoana::afisare();
	std::cout << "Numar Telefon: " << nr_telefon << "\n";
	std::cout << "Abonament: ";
	x->afisare();
	std::cout << "\n";
}