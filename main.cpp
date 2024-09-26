#include <iostream>
#include <string>

using namespace std;

const int dimensioneMax=100;

struct paziente {
    string nome;
    string cognome;
    string dataAccettazione;
    string dataDimissione;
};

//prototipi
void CaricaVettore(paziente v[], int &n);
void stampaDimessoInData(paziente v[], int n);
void registraDimissione(paziente v[], int n);
void registraNuovoPaziente(paziente v[], int &n);
int Menu();

int main() {
    
    int n;
    int scelta;
    paziente pazienti[dimensioneMax];
    
    CaricaVettore(pazienti,n);
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                stampaDimessoInData(pazienti,n);
            break;
            case 2:
                registraDimissione(pazienti,n);
            break;
            case 3:
                registraNuovoPaziente(pazienti,n);
            break;
            case 0:
                cout<<"Esci"<<endl;
            break;
            default:
                cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}

int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Visualizza pazienti dimessi in una certa data"<<endl;
  cout<<"2-Registra dimissione"<<endl;
  cout<<"3-Registra nuovo paziente"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

void CaricaVettore(paziente v[], int &n) {

    cout<<"Quanti pazienti vuoi registrare ? : ";
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Inserisci il nome del paziente: ";
        cin>>v[i].nome;
        cout<<"Inserisci il cognome del paziente: ";
        cin>>v[i].cognome;
        cin.ignore();
        cout<<"Inserisci la data di accettazione: ";
        getline(cin, v[i].dataAccettazione);
        cout<<"Inserisci la data di dimissione: ";
        getline(cin, v[i].dataDimissione);
        cout<<endl;
    }
    
    cout<<endl;

}

void stampaDimessoInData(paziente v[], int n) {
    
    string data;
            
    cin.ignore();
    cout<<"Inserisci data di dimissione: ";
    getline(cin, data);
    
    for(int i=0; i<n; i++) {
        if(data==v[i].dataDimissione) {
            cout<<endl;
            cout<<"Nome del paziente: "<<v[i].nome<<endl;
            cout<<"Cognome del paziente: "<<v[i].cognome<<endl;
            cout<<"Data di accettazione: "<<v[i].dataAccettazione<<endl;
            cout<<"Data di dimissione: "<<v[i].dataDimissione<<endl;
            cout<<endl;
        }
    }
    
    cout<<endl;
    
}

void registraDimissione(paziente v[], int n) {
    
    string nome;
    string cognome;
    string dataAttuale;
    
    
    cout<<"Inserisi il nome del paziente: ";
    cin>>nome;
    cout<<"Inserisci il cognome del paziente: ";
    cin>>cognome;
    cin.ignore();
    cout<<"Inserisci la data attuale: ";
    getline(cin, dataAttuale);
    
    for(int i=0; i<n; i++) {
        if(nome==v[i].nome&&cognome==v[i].cognome) {
            v[i].dataDimissione=dataAttuale;
        }
    }
    
    cout<<"Dimissione effettuata."<<endl;
    
    cout<<endl;
    
    
}

void registraNuovoPaziente(paziente v[], int &n) {
    
    int nuoviPazienti;
    int k=n;
    
    cout<<"Quanti nuovi pazienti vuoi registrare ? : ";
    cin>>nuoviPazienti;
    
    for(int i=k; i<=nuoviPazienti; i++) {
        cout<<endl;
        cout<<"Inserisci il nome del paziente: ";
        cin>>v[i].nome;
        cout<<"Inserisci il cognome del paziente: ";
        cin>>v[i].cognome;
        cin.ignore();
        cout<<"Inserisci la data di accettazione: ";
        getline(cin, v[i].dataAccettazione);
        cout<<"Inserisci la data di dimissione: ";
        getline(cin, v[i].dataDimissione);
        cout<<endl;
        n++;
    }
    
    cout<<endl;
    
    cout<<"Registrazione effettuata."<<endl;
    
    cout<<endl;
    
    
}
