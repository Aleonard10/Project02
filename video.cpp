#include <iostream>
#include <string>
#include "video.h"

using namespace std;

video::video(string title, string url, string comment, float length, int rating) //constructor used to store user inputs
{
    m_title = title; //stores title
    m_url = url; //stores url
    m_comment = comment; //stores comment
    m_length = length; //stores length
    m_rating = rating; //stores rating
}

bool video::longer(video* other) //function used to check the length of one video with another
{
    return m_length > other->m_length;
}
bool video::alphabetical(video* other) //function used to check the alphabetical order of 2 numbers
{
    return m_title > other->m_title;
}
bool video::better(video* other) //function used to check the rating of one video with another
{
    return m_rating > other->m_rating;
}




void video::print() //print function
{
    cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", "; // outputs the video information in the proper format
    for (int i = 0;i < m_rating; i++) //for loop used to output the rating as *s
    {
        cout << '*';
    }
    cout << endl;
}
