#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(){
    
    char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','v','x','y','z'};
    char lettersbig[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','V','X','Y','Z'};
    string text,result;
    
    int verschiebung=0;
    int index;
    

    cout<<"Lege die Verschiebung(Schluessel) der Buchstaben an:";
    cin>>verschiebung;
    cin.ignore();//Ignoriert den Enter damit getline funktioniert 
    
    if(verschiebung<=52&&verschiebung>=-52){
        cout<<"Geben Sie den Text ein der Verschluesselt werden soll:";
        getline (cin, text); //Nimmt den Ganze Zeile und importiert sie in den String |Fixed stop after first blank item 
        char kopie[text.length()];

        for (int i = 0; i < text.length(); i++)//String to Char array ohne Enter button
        {
            kopie[i]=text[i];
        }

        for (int i = 0; i <= sizeof(kopie); i++)//Ist der Buchstabe im Array vorhanden
        {
            int counter=0;
            for(int n=0;n<=sizeof(letters);n++){

                if(kopie[i]==letters[n]){
                    index=n+verschiebung;
                    if(index>25){
                        index=index-26;
                    }
                    result+=letters[index];
                }
                else if(kopie[i]==lettersbig[n]){
                    index=n+verschiebung;
                    if(index>25){
                        index=index-26;
                    }
                    result+=lettersbig[index];
                }
                else{//Zählt die Versuche wenn er gleich 27 ist ,dann befindet sich das Zeichen nicht im Array
                    counter++;
                }
            }
            if (counter==27)
            {
                if(i!=sizeof(kopie)){//Verhindert das Übernehmen vom Entersymbol zum Bestätigen
                    result+=kopie[i];
                }
            }
        }
        cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n"<<result<<"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }
    else{
        cout<<"\n\nVerschiebung ist zu gross oder zu klein.Starte das Programm neu.\n\n";
    }
    system("pause");//Damit mit die Console erst nach User-Input schließt
}