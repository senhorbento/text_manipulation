#include <iostream>
#include <fstream>
#include <list>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>

using namespace std;

#define _LISTA1_ "txt\\lista.txt"
#define _LISTA2_ "txt\\lista2.txt"
#define _RESULTADO_ "txt\\resultado.txt"

void LimparTela() {
	system("cls");
}

void Pause(int v) {
	switch (v) {
	case 1: cout << "Voce pode encontrar o resultado no arquivo resultado.txt\n\n"
                     << "Pressione uma tecla para finalizar o programa e abrir a pasta de destino!\n"; 
                     getchar(); break;
	case 2: cout << "Parece que voce esta executando o programa pela primeira vez.\n"
	             << "Acesse a pasta txt e siga as instrucoes dentro de cada arquivo =\)\n\n"
		     	 << "Pressione uma tecla para finalizar o programa e abrir a pasta!\n"; 
                     getchar(); break;
        case 3: cout << "\nLista finalizada!\n"
                     << "Pressione uma tecla para continuar.\n"; 
                     getchar(); break;
	}
}

int ExisteArquivo(const char* filename){
    struct stat buffer;
    int exist = stat(filename, &buffer);
    return exist;
}

void CriarArquivo(string txt){
	string texto;
	if(txt == _LISTA1_ || txt == _LISTA2_){
		texto = "echo \/\/Remova essas linhas e coloque o texto a ser comparado aqui =\) > " + txt;
		system(texto.c_str());
		texto = "echo \/\/Remove those lines and put text to be compared here =\) >> " + txt;
		system(texto.c_str());
	}
	else;

}

int main() {
	string leitura;
	list <string> lista1, lista2, resultado;
	ifstream input_file;
	ofstream output_file;

	if(ExisteArquivo(_LISTA1_) == -1 || ExisteArquivo(_LISTA2_) == -1){
		system("mkdir txt");
		CriarArquivo(_LISTA1_);
		CriarArquivo(_LISTA2_);
		LimparTela(); 
		Pause(2);
		system("explorer.exe /e, /n, txt");
		return EXIT_FAILURE;
	}

	LimparTela();
        input_file.open(_LISTA1_);
        if (input_file.is_open()) {
            while (!input_file.eof()) {
                 getline(input_file, leitura);
                 if (leitura != "\0") 
                         lista1.push_back(leitura);
            }
            input_file.close();
        }

        input_file.open(_LISTA2_);
        if (input_file.is_open()) {
            while (!input_file.eof()) {
                getline(input_file, leitura);
            	if (leitura != "\0")
                	lista2.push_back(leitura);
            }
            input_file.close();
        }

    	for(auto linha1 : lista1)
   	     for (auto linha2 : lista2)
    	        if(linha1 == linha2)
  	              resultado.push_back(linha1);
    	LimparTela();

  	cout << "Linhas repetidas:" << endl << endl;
 	output_file.open(_RESULTADO_);
 	for (auto linha : resultado) {
 		output_file << linha << endl;
 	        cout << linha << endl;
 	}
 	output_file.close();

	Pause(3);
	LimparTela();
 	Pause(1);
  	system("explorer.exe /e, /n, txt");
	return 0;
}