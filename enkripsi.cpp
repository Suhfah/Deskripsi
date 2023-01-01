// enkripsi sembarang berkas dengan
// algoritma XOR sederhana
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

main (int argc, char *argv[])
{
    FILE *Fin, * fout;
    char p,c;
    string K;
    int i;

    Fin = fopen (argv[1], "rb") ;
    if (Fin == NULL)
    {
        cout << "Berkas " << argv[1] << " tidak ada " << endl;
    exit(0) ;
    }

    fout = fopen (argv[2], "wb");

    cout << "Kata Kunci : ";
    cin  >> K;
    cout << "Enkripsi " << argv[2] << "...";
    i = 0;
    while (!feof(Fin))
    {
    p = getc (Fin);
    c = p ^ K[i];

    // Operasi XOR
    putc(c, fout);
    i = (i + 1) % K.length();
    }
    fclose(Fin);
    fclose(fout);
    }

