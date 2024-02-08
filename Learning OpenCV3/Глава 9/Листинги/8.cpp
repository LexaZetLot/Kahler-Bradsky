#include "wx/wx.h"
#include "WxMoviePlayer.hpp"

// Класс приложения, обьект верхнего уровня в wxWidgets
class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

// за кулисами находится функция main() и присоединение обьекта MyApp
DECLARE_APP(MyApp);
IMPLEMENT_APP(MyApp);

// На этапе инициализации MyApp вызывается следующими функциями
bool MyApp::OnInit()
{
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, wxT("ch4_wx"));
    frame->Show(true);
    WxMoviePlayer* mp = new WxMoviePlayer(frame, wxPoint(-1, -1), wxSize(640, 480));
    mp->open(wxString(argv[1]));
    mp->Show(true);
    return true;
}
