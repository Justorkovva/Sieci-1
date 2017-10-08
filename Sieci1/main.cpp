#include <iostream>
#include<fstream>
#include<string>
#include <math.h>
#include <cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int i,j,int_char,length,bit_total_1=0, bit_mod2_1,algorytm=1,m,bit_mod,n,liczba,reszta,ten,a=0,err,error,two=0,x,y;
    string crc;
    bool doubl=false;
    double er;
    char crc2[80]="0";
    ifstream infile( "1.jpg", ios::binary );
    ofstream outfile ("new.jpg", ios::binary);

  infile.seekg (0,infile.end);  // obliczam wielkość pliku
  long size = infile.tellg();
  infile.seekg (0);

  char* buffer = new char[size+1];
    infile.read (buffer,size);

buffer[size+1]='0'; //zeruje sume kontrolna

cout<<" Ktory algorytm chcesz wybrac? \n 1 - bit parzystosci \n 2 - suma modulo \n 3 - Cykliczny kod nadmiarowy  \n 0 - Wyjscie"<<endl;
cin>>algorytm;
if(algorytm==0) return 0;
cout<<" Jak beda dodawane bledy? \n 1 - z powtorzeniami \n 2 - bez powtorzen"<<endl;
cin>>error;

while(two<2)
{
    switch(algorytm) { // algorytm bedzie liczony dwa razy
  case 1:  //Licze bit parzystości
{
    bit_total_1=0;
for(i=0;i<size;i++)
{    for(j=0;j<8;j++) {
        if((buffer[i] >> j) & 1)
            bit_total_1++;
    }}
bit_mod2_1=bit_total_1 % 2;
cout<<"Bit parzystosci wyliczony wynosi : "<<bit_mod2_1<<endl<<endl;
if(two<1) // sume kontrolna dodaje tylko z apierwszym razem
buffer[size+1]=char(bit_mod2_1); //Dodaje sume kontrolna, przechowuje ja w int zmienionym na char
    break;
}
  case 2:   //Licze sume modulo
{
    if(two<1)
    {cout<<"Podaj modulo "<<endl;
    cin>>m;}

    bit_total_1=0;
      for(i=0;i<size;i++) {
    for(j=0;j<8;j++) {
    if((buffer[i] >> j) & 1)
        bit_total_1++;
    }}

bit_mod=bit_total_1 % m;
cout<<"Suma modulo wynosi : "<<bit_mod<<endl<<endl;
if(two<1)
buffer[size+1]=char(bit_mod); //suma kontrolna
    break;
}
  case 3: //CRC
{
     {/*
      cout<<"Ilo bitowy kod CRC chcesz otrzymac?"<<endl;
      cin>>n;
      cout<<"Podaj CRC (o jeden wiecej bit niz podales przed chwila)"<<endl;
      cin>>crc;
      */}
     a=0;
     crc="1011011"; n=6; //jak zmieniac to razem!
     ten=10;
     liczba=floor(size/ten);  // ile bedzie przejsc petli i resztka
     reszta= size % ten;

    // pierwszy raz uzupelniam ciag
     if(liczba>0)
     {  for(i=0;i<ten;i++) {
            for(j=0;j<8;j++)
                { (((buffer[i] >> j) & 1) ? crc2[(i*8)+j]='1' : crc2[(i*8)+j]='0');
     }}}  // for(i=0;i<80;i++){cout<<crc2[i];}

while(a<liczba) // dziele po 10 bajtow za kazdym razem
{ a++;
    for(j=0;j<((8*ten)-n);j++) // dziele przez crc po kazdym bicie
    { if(crc2[j]=='1')
        {for(m=0;m<=n;m++) // XOR
            { if(((crc2[j+m]=='1') && (crc[m]=='1')) || ((crc2[j+m]=='0') && (crc[m]=='0')))
                { crc2[j+m]= '0' ;}
                else
                { crc2[j+m] = '1';}
}  // for(i=0;i<80;i++){cout<<crc2[i];}cout<<endl;
}}
    for(i=0;i<n;i++) // koncowke przerzucam na poczatek do dalszego dzielenia
     {crc2[i]=crc2[80-n+i];}
//for(i=0;i<80;i++){cout<<crc2[i];}cout<<endl;

    if(a<liczba) // dodaje znowu do 10 bajtow
     { for(i=0;i<ten;i++) {
            for(j=0;j<8;j++)
                { if(((i*ten)+j )>=n)
                    {(((buffer[i+(ten*a)] >> j) & 1) ? crc2[(i*8)+j]='1' : crc2[(i*8)+j]='0');}
}}}  //for(i=0;i<80;i++){cout<<crc2[i];}cout<<endl;
} //koniec petli

for(i=0;i<n;i++) {crc2[80-n+i]='0';} //zera na koncu

for(i=0;i<reszta;i++) { // dodaje resztke bitow do policzenia
        for(j=0;j<8;j++)
            { if(((i*ten)+j )>=n)
                    {(((buffer[i+(ten*a)] >> j) & 1) ? crc2[(i*8)+j]='1' : crc2[(i*8)+j]='0');}}}

    for(j=0;j<((8*ten)-n);j++) // dzielenie znowu
    { if(crc2[j]=='1')
        {for(m=0;m<=n;m++) // XOR
            { if(((crc2[j+m]=='1') && (crc[m]=='1')) || ((crc2[j+m]=='0') && (crc[m]=='0')))
                { crc2[j+m]= '0' ;}
                else
                { crc2[j+m] = '1';}
            } // for(i=0;i<80;i++){cout<<crc2[i];}cout<<endl;
    }}
    cout<<"Kod CRC dla wynosi  ";
     for(i=n;i>0;i--){cout<<crc2[(ten*8-i)];}
     cout<<endl<<endl;
    break;
}
  default:
{
  cout<<endl<<"Wybrales zla wartosc"<<endl;
    }
                    }

//dodanie bledow
if(error==1)
{
     cout<<"Ile procent bledow?"<<endl;
      cin>>er;
      err=ceil((er*(size+1))/100); //ilosc bledow

    for(i=0;i<err;i++){
    x=rand() % (size+1) ;
    y= rand() % 8;
    buffer[x] ^= 1 << y;
    }
}
else if(error==2)
{
     cout<<"Ile procent bledow?"<<endl;
      cin>>er;
      err=ceil((er*(size+1))/100); //ilosc bledow
       int tab[err]; //powtorzenia sprawdze w tablicy

       for(i=0;i<err;i++) {
        doubl=false;
        while(!doubl){ //ponowne losowanie
            doubl=true;
        x=rand() % ((size+1)*8) ;
            for(j=0;j<i;j++){
                if(x==tab[j])
                    doubl=false;
            }}
            y = x % 8;
       x=floor(x/8);
        buffer[x] ^= 1 << y;
        }

}
error=0; //zeby juz sie wiecej nie dodalo
two++; //zeby petla przesza dokladnie dwa razy
}
cout<<"Suma kontrolna zwraca  "<<int(buffer[size+1])<<endl;

  // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);


  delete[] buffer; //żeby nie tworzyć lagów na komputerze
  outfile.close();
  infile.close();
  return 0;
}

//cout<<int(buffer[size+1]); //zwraca 1 lub 0

    //porownac i zapisac recznie w excelu
    //size of , wskazniki , diff :(
    // zeby sprawdzic jaki bit to dodac np. 1010 and 0001 jak jest rozne od 0 to na ostanim bylo 1
    //w krypto 4 zad 2 nwm czy dziala mam zamiane bitow na stringi

 //   buffer w bicie
/* buffer[size+1] |=bit_mod2_1<<0; //nie jestem pewna tego zapisu, i tak zajmie 1 bajt w charze, to tak będzie łatwiej
buffer[size+1] ^= (-bit_mod2_1 ^ buffer[size+1]) & (1 << 0);
cout<<((buffer[size+1] >> 0) & 1)<<endl;
*/

/*string binary(int b)
{
    if(b==0) return "0";
    if(b==1) return "1";
    if(b%2 ==0)
        return binary(b/2) + "0";
    else
        return binary(b/2) + "1";
}
*/

//https://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit
