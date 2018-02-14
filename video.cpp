#include <iostream>
#include <string>
#include "video.h"

using namespace std;

video::video(string title, string url, string comment, float length, int rating)
{
    m_title = title;
    m_url = url;
    m_comment = comment;
    m_length = length;
    m_rating = rating;
}

bool video::longer(video* other)
{
    return m_length > other->m_length;
}
bool video::alphabetical(video* other)
{
    return m_title > other->m_title;
}
bool video::better(video* other)
{
    return m_rating > other->m_rating;
}




void video::print()
{
    cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", ";
    for (int i = 0;i < m_rating; i++)
    {
        cout << '*';
    }
    cout << endl;
}
