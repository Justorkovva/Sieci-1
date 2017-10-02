#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //wczytuje plik. Czy jest różnica między ifstream::binary, a ios::binary.  ?
    ifstream infile( "1.png", ios::binary );

// tworzę drugi plik
  ofstream outfile ("new.png", ios::binary);

  // obliczam wielkość pliku
  infile.seekg (0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);

  // tablica bajtów char=bajt ?
  char* buffer = new char[size];

  // czytam z pierwszego pliku
  infile.read (buffer,size);

  //obliczam dla pliku pierwszego

  //dodaje zakłócenia do buffora

  //obliczam dla pliku drugiego

  //porównuję

  // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);

  delete[] buffer;
  outfile.close();
  infile.close();
  return 0;
   // moge to zrobic na stringach i pojdzie dosc latwo, albo bawic sie w tablice bitow gdzie jest trudniej :/


    //zamienic na binarny   buffor bajtów?  tablica bajtów

    //jakos go przechowac najlepiej nie w stringu, aczkolwiek nie wiem czemu.
    //moze klasa biginteger w javie? to tez string :/

    //jak juz jest wczytany to 3 algorytmy na niego napisac i wyliczyc wartoœci

    //dodac bledy ktorych wartosc mozna zmienic np. 0,1% , 0,01 % . sufit z tej wartosci

    //wyliczyc jeszcze raz wartosci

    //porownac i zapisac recznie w excelu

    //size of , wskaŸniki , diff :(

    // zeby sprawdzic jaki bit to dodac np. 1010 and 0001 jak jest rozne od 0 to na ostanim bylo 1

    //wszystkie pliki sa binarne normalnie wiec nauczyc sie je czytac

    //w krypto 4 zad 2 nwm czy dziala mam zamiane bitow na stringi

    cout << "Hello world!" << endl;
    return 0;
}
