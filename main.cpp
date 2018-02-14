#include <string>
#include <iostream>
#include "video.h"

using namespace std;

int main ()
{
    const int MAX = 100;
    video* Videos[MAX]; // this code creates an array of video pointers of size MAX(100)

    string sortingMethod; //variable to store user input sorting method
    cin >> sortingMethod; //cin for user input sorthing method
    if (sortingMethod != "rating" && sortingMethod != "title" && sortingMethod != "length") //checks if user input is a valid sort type
    {
        cerr << sortingMethod << " is not a legal sorting  method, giving up." << endl; //outputs an error
        return 1; //terminates the program
    }
    string title; //declaration for title variable
    string url; //declaration for url variable
    string comment; //declaration for comment variable
    float length; //declaration for length variable
    int rating; //declaration for rating variable
    int i = 0; //variable declared to be used for iterating the while loop
    int videoCount; //declaration for integer that stores the #of input videos
    videoCount = i;
    cin.ignore(); //removes the white space to prepare for getline
    //user input for video title
    while (getline(cin, title)) //allows loop to continue until there are no more videos to be entered
    {
        getline(cin, url); //user input for the video url
        getline(cin, comment); //user input for video comment
        cin >> length; //user input for video length
        cin >> rating; //user input for video rating
        cin.ignore(); //used to prep the beginning of the loop for getline
        if (videoCount > 100) //checks if # of videos is less than 100
        {
            cerr << "Too many videos, giving up." << endl; //outputs error to the screen
            return 1; //terminates the program
        }
        Videos[i] = new video(title, url, comment, length, rating); //stores the user inputs using the array of video pointers (Videos[i])
        videoCount = i; //sets videoCount to the current value of i
        i++; //iterates
    }

    if (sortingMethod == "rating") //code for sorting if rating sort was selected
    {
        for (int last = videoCount-1; last > 0; last--) //2 for loops used to index videos
        {
            for (int cur = 0; cur < last; cur++) 
            {
                if (Videos[cur]->better(Videos[cur+1])) //passes current video through bool function better to check if its bigger than the next
                {
                    swap(Videos[cur],Videos[cur+1]); //swaps them if the current video is bigger than the next video (reference video.cpp)
                }
            }
        }
    }
    else if (sortingMethod == "title") //code for sorting if title sort was selected (alphabetical)
    {
        for (int last = videoCount-1; last > 0; last--) //2 for loops used to index videos 
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (Videos[cur]->alphabetical(Videos[cur+1])) //passes current video through bool function alphabetical to check if its bigger than the next
                {
                    swap(Videos[cur],Videos[cur+1]); //swaps them if the current video is bigger than the next video (reference video.cpp)
                }
            }
        }
    }
    else if (sortingMethod == "length") //code for sorting if length was selected 
    {
        for (int last = videoCount-1; last > 0; last--) //2 for loops used to index videos
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (Videos[cur]->longer(Videos[cur+1])) //passes current video through bool function longer to check if its bigger than the next
                {
                    swap(Videos[cur],Videos[cur+1]); //swaps them if the current video is bigger than the next video (reference video.cpp)
                }
            }
        }
    }
    for (int x = videoCount-1; x >= 0; x--) //loop used to output the sorted videos
    {
        Videos[x]->print(); //prints out the current video being indexed
    }


return 0;
}
