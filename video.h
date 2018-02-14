using namespace std;
#ifndef VIDEO_H
#define VIDEO_H
class video
{
    public:
      video(string title, string url, string comment, float length, int rating);
      void print();
      bool longer(video* p);
      bool alphabetical(video* p);
      bool better(video* p);
    private:
      string m_title;
      string m_url;
      string m_comment;
      float m_length;
      int m_rating;

};
#endif
