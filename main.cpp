#include <string>
#include <iostream>
#include "video.h"

using namespace std;

int main ()
{
    const int MAX = 100;
    video* Videos[MAX];

    string sortingMethod;
    cin >> sortingMethod;
    if (sortingMethod != "rating" && sortingMethod != "title" && sortingMethod != "length")
    {
        cerr << sortingMethod << " is not a legal sorting  method, giving up." << endl;
        return 1;
    }
    string title;
    string url;
    string comment;
    float length;
    int rating;
    int i = 0;
    int videoCount;
    videoCount = i;
    cin.ignore();
    while (getline(cin, title))
    {
        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();
        if (videoCount > 99)
        {
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
        Videos[i] = new video(title, url, comment, length, rating);
        i++;
        videoCount = i;
    }

    if (sortingMethod == "rating")
    {
        for (int last = videoCount-1; last > 0; last--)
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (Videos[cur]->better(Videos[cur+1]))
                {
                    swap(Videos[cur],Videos[cur+1]);
                }
            }
        }
        for (int x = videoCount-1; x >= 0; x--)
        {
        Videos[x]->print();
        }
        return 0;
    }
    else if (sortingMethod == "title")
    {
        for (int last = videoCount-1; last > 0; last--)
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (Videos[cur]->alphabetical(Videos[cur+1]))
                {
                    swap(Videos[cur],Videos[cur+1]);
                }
            }
        }
        for (int x = 0; x < videoCount; x++)
        {
        Videos[x]->print();
        }
        return 0;

    }
    else if (sortingMethod == "length")
    {
        for (int last = videoCount-1; last > 0; last--)
        {
            for (int cur = 0; cur < last; cur++)
            {
                if (Videos[cur]->longer(Videos[cur+1]))
                {
                    swap(Videos[cur],Videos[cur+1]);
                }
            }
        }
        for (int x = 0; x < videoCount; x++)
        {
        Videos[x]->print();
        }
        return 0;
    }
    

return 0;
}
