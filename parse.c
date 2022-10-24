/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
// Review problem description for more info

unsigned char checksum(string input) {

unsigned char accumulated = 0;

for(char& c : input) {

accumulated += c;
}

return (accumulated % 26) + 'A';

}

// Required output format
const string MSG_HEADER = "ZOOX";
const string MSG_LEFT = "LEFT";

const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";

const string MSG_BEEP = "BEEP";
const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";
static int j=0;
static int i=0;
// You should not need to call this function
// Util used by execute_packet_command(...)

void execute_command(string cmd, int repeat) {
for (int k = 0; k < repeat; k++) {
cout << cmd;
}
}
// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.

// cmd should be the command string from the packet

// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {

if (cmd.compare(MSG_LEFT) == 0) {

execute_command(OUTPUT_LEFT, repeat);
}

if (cmd.compare(MSG_RIGHT) == 0) {
execute_command(OUTPUT_RIGHT, repeat);
}
if (cmd.compare(MSG_FORWARD) == 0) {
execute_command(OUTPUT_FORWARD, repeat);
}
if (cmd.compare(MSG_BEEP) == 0) {
execute_command(OUTPUT_BEEP, repeat);
}
}

// Required prototype and main

#include <stdio.h>
#include <string.h>
char temp[15];

char cmd[8]={0};
char csum[10];
static int header_flag=0, length_flag=0, command_flag=0, repeat_flag=0, checksum_flag=0;
static int len=0;
char rep[2];
char accumulated;
char header[4];
int repeat=0;

void parse(char c);

int main() {
string input;
cin >> input;
cout << "Cmd: ";
for(char& c : input) {

parse(c);
}
return 0;
}

void slideheader(char header[],char c);

void slideheader(char header[],char c)
{
    for(int i =0;i<3;i++)
    {
        header[i]=header[i+1];
    }
    header[3]=c;
}
void parse(char c)
{
   
    temp[i]=c;
    
   
    if(header_flag<4)
    {
        if(((c>='a') && (c<='z')) || ((c>='A') && (c<='Z')))
        {
            header_flag++;
            i++;
            header[i]=c;
           
            if(header_flag ==4)
            return;
        }
        else
        {
            
            i=0;
            header_flag=0;
            return;
        }
    }
    
    if((header_flag==4) && (length_flag == 0)) {
        
        if(((temp[4]>='a') && (temp[4]<='z')) || ((temp[4]>='A') && (temp[4]<='Z')))
        {
           slideheader(header,temp[4]);
        }

        else if((temp[4] =='5') || (temp[4] =='6') || (temp[4] =='8'))
        {
           
            length_flag=1;
            i++;
            len=temp[4]-'0';
            csum[0]=temp[4];
            
           
            if(length_flag == 1)
            return;
        }
        else
        {
            i=0;
            return;
        }
    }
    if((header_flag==4) && (length_flag==1) && (command_flag ==0))
    {
        cmd[j]=temp[i];
        i++;
        j++;
        
        if(j==len-1){
        if((strcmp(cmd, "RIGHT")) || (strcmp(cmd, "LEFT")) || (strcmp(cmd, "BEEP")) || (strcmp(cmd, "FORWARD")) )
        {
            command_flag=1;     
            strcat(csum,cmd);            
            if(command_flag == 1)
              return;
        }
        else
        {
            i=0;
            header_flag=0;
            length_flag=0;
            command_flag=0;
            return;
        }
        }
    }
    
    if((header_flag==4) && (length_flag==1) && (command_flag==1) && (repeat_flag ==0))
    {
        if((c>='0') || (c<='9'))
        {
            repeat=c-'0';
            rep[0]=c;
            rep[1]='\0';
            strcat(csum,rep);
            repeat_flag=1;
            i++;
            if(repeat_flag == 1)
            return;
        }
        else
        {
            i=0;
            header_flag=0;
            length_flag=0;
            command_flag=0;
            repeat_flag=0;
            return;
        }
    }
    
    if((header_flag==4) && (length_flag==1) && (command_flag==1) && (repeat_flag==1) && (checksum_flag ==0))
    {
        accumulated=checksum(csum);
        if(c==accumulated)
        {
            checksum_flag=1;
            execute_packet_command(cmd,repeat);
            if(checksum_flag == 1){
            header_flag=0;
            length_flag=0;
            command_flag=0;
            repeat_flag=0;
            checksum_flag=0;
            cmd[8]={0};
            j=0;
            len=0;
            repeat=0;
            memset(csum,'\0',10);
            memset(temp,'\0',15);
            i=0;
            return;}
            
        }
        else{
                    
            i=0;
            header_flag=0;
            length_flag=0;
            command_flag=0;
            repeat_flag=0;
            checksum_flag=0;
            return;
        }
    }
}
