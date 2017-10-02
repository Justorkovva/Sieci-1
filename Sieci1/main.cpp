#include <iostream>
#include<fstream>
#include<string>
using namespace std;

string nabinarny( int b)
{
    if(b==0) return "0";
    if(b==1) return "1";
    if(b%2 ==0)
        return nabinarny(b/2) + "0";
    else
        return nabinarny(b/2) + "1";
}


int main()
{
    int i,int_char;
    //wczytuje plik. Czy jest różnica między ifstream::binary, a ios::binary? czy to w ogóle potrzebne?
    ifstream infile( "1.txt", ios::binary );
// tworzę drugi plik
  ofstream outfile ("new.txt", ios::binary);

  // obliczam wielkość pliku
  infile.seekg (0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);

  // tablica bajtów char=bajt ?
  //char czy unsigned char?

  char* buffer = new char[size];

  // czytam z pierwszego pliku
  infile.read (buffer,size);

  //Liczę bit parzystości
for(i=0;i<size;i++)
{
    int_char=int(buffer[i]);
    cout<<int_char<<endl;
}
//char na int
//int na string




/*
   for(int i=0;i<size;i++)
  {
  cout<<tab[i];
  }
  */

  //obliczam dla pliku pierwszego

  //dodaje sume kontrolna na koniec pliku

  //dodaje zakłócenia do buffora

  //usuwam sumę kontrolną?

  //obliczam dla pliku drugiego

  //porównuję

  // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);

  //żeby nie tworzyć lagów na komputerze
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
