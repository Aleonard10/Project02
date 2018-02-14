using namespace std;
#ifndef VIDEO_H
#define VIDEO_H
class video
{
    public:
      video(string title, string url, string comment, float length, int rating); //prototype function for constructor
      void print(); //prototype function for printing the output
      bool longer(video* p); //prototype function for testing difference in length between 2 videos
      bool alphabetical(video* p); //prototype function for testing difference in alphabetical order between 2 videos
      bool better(video* p); //prototype function for testing difference in rating between 2 videos
    private:
      string m_title; //member variable for title
      string m_url; //member variable for url
      string m_comment; //member variable for comment
      float m_length; //member variable for length
      int m_rating; //member variable for rating

};
#endif
