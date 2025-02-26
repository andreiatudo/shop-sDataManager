#include "Functions.h"

int main(int argc, char* argv[]) 
{
    //std::cout << argv[1] << std::endl;
    //std::cout << argv[2] << std::endl;
    std::ifstream fin(argv[1]);
    std::ifstream gin(argv[2]);
    std::ofstream fout("output_stoc_ramas.txt");
    std::ofstream gout("output_comenzi.txt");
    // g++ -o program *.cpp
    // ./program produse.txt clienti.txt 

    if (fisierGol(argv[1]))
    {
        fout << "Stoc ramas";
        gout << "Nu exista clienti in magazin.";
    }
    else
    {
        int nrProduse;
        fin >> nrProduse;
        fin.ignore();
        Produs* produse = citireStoc(fin, nrProduse);
        if (fisierGol(argv[2]))
        {
            fout << "Stoc ramas\n";
            afisareSlim(fout, produse, nrProduse);
            gout << "Nu exista clienti in magazin.";
            if (produse != nullptr)
            {
                delete[] produse;
            }
        }
        else
        {
            fout << "Stoc ramas\n";
            int nrClienti;
            gin >> nrClienti;
            //std::cout<<nrClienti<<'\n';
            gin.ignore();
            Client* clienti = citireClienti(gin, nrClienti, nrProduse, produse);
            procesareStoc(clienti, nrClienti, nrProduse, produse);
            afisare(fout, gout, produse, clienti, nrProduse, nrClienti);
            if (produse != nullptr)
            {
                delete[] produse;
            }
            if (clienti != nullptr)
            {
                delete[] clienti;
            }
        }
    }
        
    
    
    fin.close();
    gin.close();
    fout.close();
    gout.close();

    return 0;

    //TODO: nu scrieti cod functional aici, implementati clasele sau functii care sa rezolve
    // pastrati main-ul cat mai curat si simplu de inteles
}
