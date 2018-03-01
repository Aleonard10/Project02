#include <string>
#include <iostream>
#include "vlist.h"
#include "video.h"

using namespace std;

int main ()
{
    string command;
    string delTitle;
    string Title;
    vlist List;
    string Url;
    string Comment;
    float Length;
    int Rating;

    int numVideos = 0;
    while (cin >> command)
    {
        cin.ignore();
        if (command == "insert")
        {
            getline(cin, Title);
            //List.compare(Title); new compare function that will return bool value 1 or 0 (1 == same, 0 == unique)
            if (List.compare(Title) == 0)
            {
                getline(cin, Url);
                getline(cin, Comment);
                cin >> Length;
                cin >> Rating;
                cin.ignore();
                video* Video = new video(Title, Url, Comment, Length, Rating);
                List.insert(Video);               //add to list
            }
            else if (List.compare(Title) == 1)
            {
                cerr << "Could not insert video <" << Title << "> already in list." << endl;
            }
        }
        else if (command == "print")
        {
            List.print();
        }
        else if (command == "length")
        {

        }
        else if (command == "lookup")
        {
            if (List.compare(Title) == 0)
            {

            }
            else if (List.compare(Title) == 1)
            {
                cerr << "Title <" << Title << "> not in list." << endl;
            }
        }
        else if (command == "remove")
        {
            getline(cin, delTitle);
            List.compare(delTitle);

        }
        else
        {
            cerr << "<"<< command << "> is not a legal command, giving up." << endl;
            return 1;
        }
    }


}
