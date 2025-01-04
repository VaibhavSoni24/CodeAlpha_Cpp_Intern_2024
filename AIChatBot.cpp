#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

// Function to simulate speaking (Text-to-Speech)
void speak(const string& message)
{
    cout<<"[Bot]: "<<message<<endl;
}

// Function to simulate time-based greetings
void wishMe()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;

    if(hour >= 0 && hour < 12)
    {
        speak("Good Morning!");
    }
    else if(hour >= 12 && hour < 18)
    {
        speak("Good Afternoon!");
    }
    else
    {
        speak("Good Evening!");
    }

    speak("I am your Assistant. How may I help you?");
}

// Function to handle user input and recognize commands
string takeCommand()
{
    string command;
    cout<<"[User]: ";
    getline(cin, command);
    return command;
}

// Function to simulate opening a website
void openWebsite(const string& website)
{
    string url = "start " + website;
    system(url.c_str());
}

// Function to simulate telling the current time
void tellTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream timeStream;
    timeStream<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec;
    speak("The time is " + timeStream.str());
}

// Function to simulate playing music
void playMusic()
{
    string music_dir = "D:\\Audio\\Music";
    string music_command = "start " + music_dir;
    system(music_command.c_str());
    speak("Playing music...");
}

// Main bot loop
int main()
{
    wishMe();

    while (true)
    {
        string command = takeCommand();
        for (auto& c : command) c = tolower(c);  // Convert to lowercase for easier command matching

        if(command == "hello")
        {
            speak("Hello! How can I assist you today?");
        }
        else if(command == "what are you")
        {
            speak("I am a virtual assistant created to help you with various tasks like opening websites, telling the time, playing music, and more.");
        }
        else if(command.find("open youtube") != string::npos)
        {
            openWebsite("https://youtube.com");
        }
        else if(command.find("open google") != string::npos)
        {
            openWebsite("https://google.com");
        }
        else if(command.find("the time") != string::npos)
        {
            tellTime();
        }
        else if(command.find("play music") != string::npos)
        {
            playMusic();
        }
        else if(command.find("exit") != string::npos || command.find("quit") != string::npos)
        {
            speak("Goodbye!");
            break;  // Exit the loop and end the program
        }
        else if(command.find("c++") != string::npos)
        {
            speak("C++ is a high-level programming language developed by Bjarne Stroustrup.");
        }
        else if(command.find("python") != string::npos)
        {
            speak("Python is an interpreted, high-level, general-purpose programming language.");
        }
        else
        {
            // We can add the wikipedia searching system here after.
            speak("Sorry, I don't have information on that topic.");
        }
    }

    return 0;
}
