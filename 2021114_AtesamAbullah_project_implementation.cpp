// ATESAM ABDULLAH     2021114     BAI     CS103L SEMESTER-1 PROJECT 

#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------------------------------------------

const int L=100,COST=300;// --L--max no of students //--cost--cost per day for mess
int CN=0;//current no of students in record
int REGNO[L],BILL[L],DAYS[L];//--regno-- of student//--bill--for each student //--days--no days mess is IN
string NAME[L];//name of student
bool STATUS[L];//mess status---false/true=out/in

//------------------------------------------------------------------------------------------------------------------

void menu();//all optons that can be performed
void register_student();//create a new student record
void student_push(int regnum,string name);
void delete_student();//delete a student record
void student_pop(int index);
void change_inout();//change the IN/OUT status 
void search_student();//search a student by regno
void tally_inout();//displays no of IN/OUT students
void update_days();//updates the no of days student is IN
void student_swap(int i,int j);//swaps two student records--> makes sorting easier
void exit();//updates the csv file

//------------------------------------------------------------------------------------------------------------------
int main()
{
    cout<<" ================================================= \n";
    cout<<"|                     WELCOME                     |\n";
    cout<<"|                       TO                        |\n";
    cout<<"|           GIKI MESS MANAGEMENT SYSTEM           |\n";
    cout<<" ================================================= \n";

    system("pause");
    menu();

	return 0;	
}
//------------------------------------------------------------------------------------------------------------------

void menu()
{	system("cls");

	char option; //stores option selected

    cout<<" ================================================= \n";
    cout<<"| R/r  |  Register a new student                  |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| S/s  |  Search a student record                 |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| C/c  |  Change student mess status              |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| D/d  |  Delete a student record                 |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| T/t  |  Show total number of \"In/Out\" students  |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| N/n  |  Go to next day                          |\n";
    cout<<"|-------------------------------------------------|\n";
    cout<<"| X/x  |  Exit                                    |\n";
    cout<<" ================================================= \n";
    cout<<"\n";
    
	cout<<"Enter option code: ";
	cin>>option;

	switch(option){
        case 'R':
        case 'r':
            register_student();
            break;
        case 'D':
        case 'd':
            delete_student();
            break;
        case 'S':
        case 's':
            search_student();
            break;
        case 'C':
        case 'c':
            change_inout();
            break;
        case 'T':
        case 't':
            tally_inout();
            break;
        case 'N':
        case 'n':
            update_days();
            break;
        case 'X':
        case 'x':
            exit();
            break;
        default:
            menu();
    }
}
void register_student()
{   system("cls");

    int reg;
    string name;

    cout<<"Enter student reg# : ";
    cin>>reg;
    cout<<endl;
    cout<<"Enter student name : ";
    cin.ignore();//clears cin buffer
    getline(cin,name);//inputs name with space included

    
    cout<<"\n|===============================================\n";
    cout<<"| Y/y  |    Confirm                              |\n";
    cout<<"|------------------------------------------------|\n";
    cout<<"| N/n  |    Cancel                               |\n";
    cout<<" ================================================ \n";
    cout<<"\n\n";

    cout<<"Enter Option Code:";
    char temp;
    cin>>temp;

    if ((temp=='Y')||(temp=='y'))
    {
        student_push(reg,name);
        cout<<"----Student registered----\n";
    }
    CN++;
    system("pause");
    menu();
}
void student_push(int regno,string name)
{   
    int index=CN;//new students index in array
    for(int i=0;i<CN;i++)
    {
        if(REGNO[i]>regno)
        {
            index=i;
            break;
        }
    }
    for (int i=CN;i>=index;i--)//creates a hole in array for new student
    {
        student_swap(i,i+1);
    }
    REGNO[index]=regno;
    NAME[index]=name;
    BILL[index]=0;
    DAYS[index]=0;
    STATUS[index]=false;//false=out
}
void delete_student()
{   system("cls");

    int reg,index;
    bool temp=false;

    cout<<"Enter student reg# : ";
    cin>>reg;
    cout<<endl;

    for(int i=0;i<CN;i++)
    {
        if(REGNO[i]==reg)
        {
            temp=true;
            index=i;
        }
    }
    if(temp==true)
    {
        student_pop(index);
        cout<<"----Student deleted----\n";
        CN--;
    }
    else
    {
        cout<<"!! Invalid reg# !!\n";
    }
    system("pause");
    menu();
}
void student_pop(int index)
{   
    int last=CN-1;//last index in array

    for (int i=index;i<CN;i++)
    {
        student_swap(i,i+1);
    }
    REGNO[last]=0;
    NAME[last]="";
    DAYS[last]=0;
    BILL[last]=0;
    STATUS[last]=false;
}
void change_inout()
{   system("cls");

    int reg,index=-1;

    cout<<"Enter student reg# : ";
    cin>>reg;
    cout<<endl;

    for(int i=0;i<CN;i++)
    {
        if(REGNO[i]==reg)
        {
            index=i;
        }
    }
    if(index!=-1)
    {
        STATUS[index]=!STATUS[index];
        cout<<"----Status changed----\n";
    }
    else
    {
        cout<<"!! Invalid reg# !!\n";
    }
    system("pause");
    menu();

}
void search_student()
{   system("cls");

    int reg,index=-1;
    string status;

    cout<<"Enter student reg# : ";
    cin>>reg;
    cout<<"----------------------------------------------------------------------------\n";

    for(int i=0;i<CN;i++)
    {
        if(REGNO[i]==reg)
        {
            index=i;
            if (STATUS[i]==false)
                status="OUT";
            else
                status="IN";
        }
    }
    
    if(index!=-1)
    {
        cout<<"Name : "<<NAME[index]<<endl;
        cout<<"Reg# : "<<REGNO[index]<<endl;
        cout<<"Bill : "<<BILL[index]<<endl;
        cout<<"Status : "<<status<<endl;
        cout<<"Days : "<<DAYS[index]<<endl;
    }
    else
    {
        cout<<"!! Invalid reg# !!\n";
    }
    system("pause");
    menu();
}
void tally_inout()
{   system("cls");

    int in=0,out=0;

    for (int i=0;i<CN;i++)
    {
        if(STATUS[i])//true=in
            in++;
        else//false=out
            out++;
    }
    cout<<"Total no of students 'IN' : "<<in<<endl;
    cout<<"Total no of students 'OUT' : "<<out<<endl;

    system("pause");
    menu();
}
void update_days()
{   system("cls");

    for (int i=0;i<CN;i++)
    {
        if (STATUS[i])
        {
            DAYS[i]++;//update days for IN students
            BILL[i]+=COST;//update bills
        }
    }

    cout<<"----New day started----\n";

    system("pause");
    menu();
}
void student_swap(int i,int j)
{
    swap(REGNO[i],REGNO[j]);
    swap(NAME[i],NAME[j]);
    swap(BILL[i],BILL[j]);
    swap(DAYS[i],DAYS[j]);
    swap(STATUS[i],STATUS[j]);
}
void exit()
{   system("cls");

    fstream file;//file pointer
    file.open("data.csv",fstream::app);//creates or writes in file
    
    string status;

    for(int i=0;i<CN;i++)
    {   
        if (STATUS[i]==false)//converts bool to string for user experience
            status="OUT";
        else
            status="IN";

        file<<REGNO[i]<<","<<NAME[i]<<","<<status<<","<<DAYS[i]<<","<<BILL[i]<<"\n";
    }
    cout<<"----Data saved----\n";

    system("pause");
    system("exit");//terminates program 
}
