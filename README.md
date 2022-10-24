# zoox_parsing_coding_challenge

We have a simple robot that can only take a few actions.
The commands are sent one byte at a time over a serial link as command packets. These packets have the following format:
Header (4 bytes)
Header = "ZOOX", ASCII

Length (1 byte)
1 ASCII decimal digit character, so between '0' and '9' (inclusive).
Length = command length + repeat length (excludes header, length, checksum)

Command (Length-1 bytes)
ASCII, one of: "LEFT", "RIGHT", "FORWARD", "BEEP"

Repeat (1 byte)
1 ASCII decimal digit character, so between '0' and '9' (inclusive).
Number of times to repeat the command

Checksum (1 byte)
1 ASCII uppercase alphabetic character, so between 'A' and 'Z' (inclusive).
Simple computation to check content for bit errors
Calculated over the following section: [Length, Command, Repeat] (excludes header, checksum)

Assignment
Using the provided code, implement the parse(c) function to identify and execute each command packet.
The parse(c) function takes one byte at a time because that is how the data will arrive for the simple robot.
Feel free to add more functions and definitions, but do not change main().
execute_packet_command(...) has been provided to assist with the test output.
A few example inputs -> outputs for the complete system:
ZOOX6RIGHT3X -> Cmd: RRR
ZOOX5LEFT2QZOOX5BEEP3C -> Cmd: LL!!!
If there are multiple complete packets, they should all get called as parameters to execute_packet_command(...).

This simple robot lives in a harsh world. These packets are coming in over a bad link. There may be lots of bit errors, random erroneous bytes, and all kinds of data loss. We need this code to silently drop all the junk data, but output packets that pass the checksum. For example, this means we could have the following inputs -> outputs:
abcZOOX6RIGHT2Wabc -> Cmd: RR
abcZOOX6lmnopRIGHT3Xabc -> Cmd:
ZOOX6RIGHT3abc -> Cmd:
(notice the checksum byte is lost on that last one)
If your parser identifies bytes as belonging to a complete packet, those bytes will not be used for any later packets.

Code development workflow
Please use the provided in-browser RemoteInterview coding environment. It records your progress. This way the person reviewing your submission will be able to review your development and debugging process. Having a clean and clear process will earn you the appreciation of the person reviewing your code.

Grading
A variety of test inputs will be checked automatically and output formatting is very specific. For this reason, all answers must start with "Cmd: " and this is provided in main(). Your parse(c) function need only call execute_packet_command(...) when appropriate.

Timing
Basic command parsing should be achievable within the time limit. Covering all the possible edge cases is bonus.

Starter Code
In case you need to restore any of the starter code, here's a copy.
/************************************************

Do not modify this starter code. * *
Your code should be added at the bottom. * *
   * Thank you and good luck! *           *
************************************************/

#include
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

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
for (int i = 0; i < repeat; i++) {
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

/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
/************************************************/

/************************************************

Do not modify this starter code. * *
Your code should be added at the bottom. * *
   * Thank you and good luck! *           *
************************************************/

#include
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
// You should not need to call this function
// Util used by execute_packet_command(...)

void execute_command(string cmd, int repeat) {
for (int i = 0; i < repeat; i++) {
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

/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------

/************************************************/

void parse(char c)
{

}
