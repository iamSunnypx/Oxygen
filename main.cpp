//------------------------Header files--------------------------------//
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<shellapi.h>
#include<fstream>
#include <ctime>
#include"someImportantFunctions.h"
#include"general.cpp"




using namespace std;


class reg  // For registeration
{
    public:
    string username , password ;

    string word , temp , word1, temp1;

};

class login   // for login
{
public:
    string lusername , lpassword;
};

//-------------------------global variables--------------------//
string user, m_word,  s_word;

      //----------user-----main word-------simple word-------//
int pos,l_pos;
           //-------------position-----last position-------//


//------------------FUNCTION PROTOTYPES----------------------//

void intro();
void training();
void open_file(string);
void play_music(string);
void typing(string);
void repeat();
void help();
void custom();
void orderNotFound();




//-------------All possible intents---------//
//string hello


//--------------------Main Function---------------------------//
int main(){



    reg r;
login l;

    int ch ;

    string word;

    cout<<"---------------------------------AUTHORIZATION TERMINAL-------------------------\n\n\n ";

    cout<<"------Please enter your choice(press 1 for register else press 2 for login) :\n";

    cin>>ch;





    switch(ch)
    {
    case 1 :
        {

            cout<<"\t\t\t\t------------Registeration Page------------\n";


        cout<<"----Please enter the username \n ";
        cin>>r.username;
        ofstream ob("user.txt",ios::out);
        ob<<r.username;
        ob.close();
        cout<<"-----Please enter the password \n ";
        cin>>r.password;
        ofstream ob1("pass.txt",ios::out);
        ob1<<r.password;
        ob1.close();

        }



    case 2 :
        {



            cout<<"\t\t\t\t---------------Login page-----------------\n";



                cout<<" username \n ";
                cin>>l.lusername;
                cout<<" password \n ";
                cin>>l.lpassword;


ifstream infile;
    infile.open ("user.txt");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (infile >> r.word) {

        r.temp = r.word;
    }

    infile.close();

    ifstream ifile;
    ifile.open ("pass.txt");
    if (!ifile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (ifile >> r.word1) {

        r.temp1 = r.word1;
    }

    ifile.close();

    if(l.lusername==r.temp && l.lpassword==r.temp1)

    {
        system("COLOR A");
        cout<<"\t\t\t\t----------------Authorization Successfull-------------------\n";
        Sleep(500);




    }
    else{
            system("COLOR C");
        cout<<"\t\t\t\t-------------------Unauthorized access not allowed--------------\n";

    exit(1);

    }
    break;

        }


    default :

        {
           cout<<"---------------Incorrect choice------------ ";
        exit(1);

        break;

        }
        }


system("COLOR C");


   //introduce itself



cout<<"\n\t";
typing("How Can I help you ? (type 'help' to get help)");



    repeat();//repeat the input from user



    }









//-----------------------------Repeat function-------------------------//
void repeat()
{




while(m_word!="exit")
{



cout<<" \nType Here  ---> ";

getline(cin,user);   // get command from user

pos=user.find(" "); //set position to find the main command
m_word=user.substr(0,pos);
l_pos=user.find('\0');
s_word=user.substr(pos+1,l_pos);


//-----------check conditions--------------//

        if(m_word=="open")
        {
              open_file(s_word);
              repeat();
        }




                else if(m_word=="restart")
   {
		cout<<"Your system will be restarted in 20 seconds\n";
		system("say.vbs \Your system will be restarted in 20 seconds\"");
		system("c:\\windows\\system32\\shutdown /r /t 20\n\n");
		repeat();

   }

   else if(m_word=="shutdown")
   {
        cout<<"Your system will be shutdown after 20 seconds \n";
        system("say.vbs \Your system will be shutdown in 20 seconds\"");
		system("c:\\windows\\system32\\shutdown /s /t 20 \n\n");
		repeat();

   }


   else if(m_word=="ip")
   {
      string line;
      ifstream IPFile;
      int offset;
      char* search0 ="IPv4 Address. . . . . . . . . . . :";
      system ("ipconfig > ip.txt");
      IPFile.open ("ip.txt");
      if(IPFile.is_open())
      {
	      while(!IPFile.eof())
	      {
		      getline(IPFile,line);
		      if((offset = line.find(search0)) != string::npos)
		      {
			      line.erase(0,39);
			         system("say.vbs \"Getting your Ip address\"");
			      cout<<"IP ADDRESS :: " <<line<<endl<<endl;

			      IPFile.close();
		      }
	      }
      }
      repeat();

   }



   else if(m_word=="date")
   {
      time_t timetoday;
      time (&timetoday);
      cout << "Calendar date and time as per todays is : "<< asctime(localtime(&timetoday));


    repeat();
   }



  else if (m_word=="play"){
          play_music(s_word);
          repeat();

}
   else if (m_word == "search"){

            cout<< "please enter what you want to search :" ;

           system("say.vbs \"Please enter what you want to search\"");

        char word[100];

      gets(word);

        string base_URL = "https://www.google.com/search?q=";
    string search_URL = "dummy ";
    search_URL = base_URL + word;

    cout << "Searching for: \"" << word << "\"\n";


    ShellExecuteA(NULL, "open", search_URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
    repeat();
   }

else if (m_word == "help")
{
    help();
    repeat();


}



else if (m_word == "exit")
{
     exit(1);
}



else if (m_word=="customize")
{
    custom();
}

}
}











//--------------------------------------Typing function-------------------------------//
void typing(string msg)
{

    int i;
    if (msg != "Hello Sir")
        cout<<"\n---> ";
    for(i = 0 ; msg[i] != '\0'; i++){
    cout<<msg[i];
    Sleep(50);
    }
}


//-----------------------Introduction function----------------------------//
void intro()
{
int i;
      for(i=0;i<100;i++)
    {
        system("cls");


     cout<<"\n\n\n\n\n\t\t\t\t\t\tLoading .....  ";
      cout<<i<<"%";
      Sleep(1+i);

    }

     printf("\n\n");

    for(i=0;i<=100;i++)
    {
       Sleep(12);
       printf("%c",219);
    }

     printf("\n\n\t\t\t\t\t Initiating system");


    PlaySound(TEXT("load1.wav"), NULL, SND_SYNC);


    cout<<"\n\n\t\t\t\t";
    typing("Oxygen is Connected....");
    Sleep(200);
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t";
    typing("Hello Sir");  //Give a welcome message to user
    cout<<"\n";
    system("say.vbs \"Hello Sir , I am Oxygen your virtual assistant . How can I help you ?\"");


}

void custom(){

       GeneralCommand general;   //for operating general commands
    iCommand.open("Commands.txt", ios::ate | ios::out | ios::in );
	if(iCommand.fail())
	{
		cout<<"Error in opening Commands.txt\n";
		exit(0);
	}
	 system("cls");
    cout<<"\n\033[1;36mHello! I am Zira You can personally talk to me ?\033[0m\n";
    system("Zira.vbs \"Hello ! I am zira You can personally talk to me ?\"");

    while(1)
    {
        if(iCommand.eof())
            iCommand.clear();
        general.getOrder();
        general.searchOrder();
        if(isCommandFound == FOUND)
            general.perform();

        if(isCommandFound == NOTFOUND)
            orderNotFound();

        isCommandFound = NOTFOUND;
    }
}




//-----------------------------Function to open the files and folders------------------------//
void open_file(string open_fname)
{
 if (open_fname=="chrome")
  {


       typing("Opening the file "+open_fname);
      system("say.vbs \"Trying to open the file\"");
       system("start C:\Program Files (x86)\Google\Chrome\Application");

  }

}

//-----------------------------Function to play music----------------------//
void play_music(string play_fname)
{
    system("cls");
 if (play_fname=="dilbar")
  {

       system("playing.vbs");
       typing("Playing the song "+play_fname);
       system("start My_beat/dilbar.mp3");
       repeat();

  }
   else if (play_fname=="faded")
    {
       system("playing.vbs");
       typing("Playing the song "+play_fname);
       system("start My_beat/Alan_Walker_Fade.mp3");
       repeat();
    }
   else if (play_fname=="trending nakhra")
    {
       system("playing.vbs");
       typing("Playing the song "+play_fname);
       system("start My_beat/trending-nakhra.mp3");
       repeat();
    }
   else if (play_fname=="badfella")
    {
       system("playing.vbs");
       typing("Playing the song "+play_fname);
       system("start My_beat/Badfella_Sidhu_Moose_Wala.mp3");
       repeat();
    }

    else if (play_fname=="shape of you ")
    {
       system("playing.vbs");
       typing("Playing the song "+play_fname);
       system("start My_beat/shape.mp3");
       repeat();
    }

    else{
        system("say.vbs \"Error : There is no such file here...");
        typing("Error : There is no such file here...");
        repeat();
    }




}//end the function play_music



void orderNotFound()
{
    int ch = '\0';
	cout<<"\033[1;36mI cannot understand what you say !\033[0m"<<endl;
	system("Zira.vbs \"I Cannot understand what you say !\"");
	Sleep(0.6);
	cout<<"\033[1;36mI will learn these things soon.\033[0m"<<endl;
	system("Zira.vbs \"I will learn these things soon.\"");
	cout<<"\033[1;36mWant to teach me..??(y/n)\033[0m"<<endl;
	fflush(stdin);
	ch = getch();
	cout << char(ch);
        if(ch=='y')

		createCommandMainMethod();
        else

        cout<<"\033[1;36mOkay!\033[0m"<<endl;
    	system("Zira.vbs \"Okay!\"");

}

//Help

void help()
{
    system("COLOR A");
       system("say.vbs \"You can use the below commands\"");

       cout<<"\n----------------------------------------------------\n";
       cout<<"\t\t\t\tCommands\t\t\t\t";
       cout<<"\n----------------------------------------------------\n";

    cout <<"\n \t\t 1.Search (any question) \n \t\t 2.open (google , mozilla ) \n \t\t 3. Watch (videoname ) \n \t\t 4. Customize(PERSONAL ASSISTANT WITH FEMALE VOICE) \n \t \n\t Time\n\t\t 5.Play song ( songname )\n \t\t 6. Open file \n \t\t 7.  Exit \n \t\t 7.  restart \n \t\t 7. Shutdown 7.find my Ip \n "<<endl;

    repeat();
}




