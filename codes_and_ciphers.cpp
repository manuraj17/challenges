/*
Codes and Cyphers
[Venturesity - Need for Code]
Manu M R ( manuraj )
manu.elayath@gmail.com
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


//Function to return corresponding alphabet value eg; a= 1
int return_al_val(char c){
    return (c-96);
}

//Function to return corresponding char
char return_char(int x){
    
    int val = (x-1) + 97;
    char temp = (char)val;
    
    return temp;
}


void encrypt(string key, string message)
{
	//cout<<message<<"\n";

	string::iterator i, j;

	j = key.begin();

	for(i = message.begin(); i<message.end(); i++)
	{
		if( *i != ' ' && ( (*i >= 'a' ) && (*i <= 'z' )|| (*i >= 'A')&&(*i <='Z') ) )
		{
			if( j >= key.end() )  { j = key.begin(); } 		
					
			cout<<return_char( ( (
				( return_al_val(tolower(*i)) )  //Converting message to ascii equivalent
				+ 	
				( return_al_val(tolower(*j)) )  //Converting message to ascii equivalent					
				)% 26) +1 );			
			j++;
		}
		else if( *i != ' ')
		{
			cout<<(*i);
		}
	}
	
	cout<<"\n";

}


void decrypt(string key, string message)
{
	//cout<<message<<"\n";

	string::iterator i, j;

	j = key.begin();

	int val;

	for(i = message.begin(); i<message.end(); i++)
	{
		if( *i != ' ' && ( (*i >= 'a' ) && (*i <= 'z' )|| (*i >= 'A')&&(*i <='Z') ) )
		{
			if( j >= key.end() )  { j = key.begin(); } 

			val = 	( ( return_al_val(tolower(*i)) )-( return_al_val(tolower(*j)) ) ) ;

			(val<=0)?cout<< return_char( (26+val)-1):cout<<return_char((val%26)-1);
			
			j++;
		}
		else if( *i != ' ')
		{
			cout<<(*i);
		}
		
	}
	
	cout<<"\n";

}


int main()
{
	string text, key;
	string::iterator i;
	char choice;	
	
	cout<<"Key: ";	
	getline(cin, key, '\n');
		
	cout<<"Is message plaintext (Y/N): ";
	cin>>choice;
	choice = tolower(choice);

	switch(choice)
	{
		case 'y'	:	//cout<<"Encryption\n";
						cout<<"Plaintext: ";
						cin.ignore();
						getline(cin, text, '\n');
						encrypt(key, text);
						break;
		case 'n'	:	//cout<<"Decryption\n";
						cout<<"Ciphertext: ";
						cin.ignore();
						getline(cin, text, '\n');
						decrypt(key, text);
						break;
		default		: 	//cout<<"Exiting..\n";
						break;
	}

	return 0;

}
